/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:38:18 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/20 15:21:29 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
  All vectors should get a unit length #v3_normalize()
*/

SDL_Color			vec3_to_sdlcolor(t_vec3 v)
{
	SDL_Color	c;

	c.r = (v.x * 255.0) > 255 ? 255 : v.x * 254.99;
	c.g = (v.y * 255.0) > 255 ? 255 : v.y * 254.99;
	c.b = (v.z * 255.0) > 255 ? 255 : v.z * 254.99;
	c.a = 255.0;
	return (c);
}

BOOL				hit_list(t_scene *scene, const t_ray *ray, \
	const float t_min, const float t_max, t_hit *param)
{
	BOOL		hit_anything;
	double		closest_so_far;
	int			i;

	i = 0;
	hit_anything = FALSE;
	closest_so_far = t_max;
	while (i < scene->obj_nb)
	{
		if (scene->obj[i]->hit(scene->obj[i]->p_obj, ray, t_min, \
			closest_so_far, param))
		{
			hit_anything = TRUE;
			closest_so_far = param->t;
			param->material = scene->obj[i]->p_mat;
			param->i_lst = i;
		}
		++i;
	}
	return (hit_anything);
}

t_vec3				*rt_color(t_ray *ray, t_scene *scene, int depth, \
	int max_depth)
{
	t_hit		param;
	t_vec3		*v1;
	t_vec3		*v2;
	t_vec3		*ret;
	t_vec3		*target;

	t_vec3		*emission;
	t_ray		*scattered;
	t_vec3		*attenuation;
	t_vec3		*reflected;

	param.pos = v3_new_vec(0.0, 0.0, 0.0);
	param.normal = v3_new_vec(0.0, 0.0, 0.0);
	if (hit_list(scene, ray, 0.001, FLT_MAX, &param))
	{
		if (depth < max_depth)// && param.material->scatter(ray, param, \
			//attenuation, scattered))
		{

			/*
			  Pick material as for now scatter func_ptr* doesn't work
			*/

			if (param.material->type_mat == MAT_METAL)
			{
				//scatter_metal(ray, param, attenuation, scattered);
				v1 = v3_unit_vec(*(ray->dir));
				reflected = reflect(*v1, *(param.normal));
				v3_free(v1);
			
				v1 = random_in_unit_sphere();
				v2 = v3_scale_vec(*v1, param.material->t);
				v3_free(v1);
				v1 =  v3_add_vec(*reflected, *v2);
				v3_free(v2);
				v3_free(reflected);
			
				scattered = new_ray(v3_copy_vec(*param.pos), v1);
				attenuation = param.material->albedo;

				if (v3_dot_float(*(scattered->dir), *(param.normal)) <= 0)
				{
					v3_free(param.pos);
					v3_free(param.normal);
					free_ray(scattered);
					return (v3_copy_vec(*(param.material->emitted)));
				}
			}
			else if (param.material->type_mat == MAT_LAMBERT)
			{
				//scatter_lambertian(ray, param, attenuation, scattered);
				v1 = v3_add_vec(*(param.pos), *(param.normal));
				v2 = random_in_unit_sphere();
				target = v3_add_vec(*v1, *v2);
				v3_free(v1);
				v3_free(v2);
				scattered = new_ray(v3_copy_vec(*param.pos), \
					v3_sub_vec(*target, *(param.pos)));
				v3_free(target);
				attenuation = param.material->albedo;
			}
			else if (param.material->type_mat == MAT_DIFF_LIGHT)
			{
				v3_free(param.pos);
				v3_free(param.normal);
				return (v3_copy_vec(*(param.material->emitted)));
			}
			else
			{
				v3_free(param.pos);
				v3_free(param.normal);
				return (v3_copy_vec(*(param.material->emitted)));
			}

			/*
			  Does the job for rendering material
			*/

			emission = rt_color(scattered, scene, depth + 1, max_depth);
			v1 = v3_multiply_vec(*attenuation, *emission);
			ret = v3_add_vec(*(param.material->emitted), *v1);
			v3_free(v1);
			v3_free(emission);
			v3_free(param.pos);
			v3_free(param.normal);
			free_ray(scattered);
			return (ret);
		}
		else
		{
			v3_free(param.pos);
			v3_free(param.normal);
			return (v3_copy_vec(*(param.material->emitted)));
		}
	}
	else
	{
		/*
		  Render skybox
		*/

		ret = scene->skybox->hit(scene->skybox, ray);

		v3_free(param.pos);
		v3_free(param.normal);
		return (ret);
	}
	return (NULL);
}

void				thread_render(t_tharg *arg)
{
	register int	x;
	register int	y;
	register float	u;
	register float	v;
	t_vec3	        *temp;
	t_ray			*ray;
	SDL_Color		pixel;

	y = arg->j;
	while (y < arg->rt->r_view->h)
	{
		x = 0;
		while (x < arg->rt->r_view->w)
		{
			if (*(arg->s) <= ALIASING)
			{
				u = (float)((float)x + (*(arg->s) == NO_ALIASING ? 0 : \
					f_random())) / (float)arg->rt->r_view->w;
				v = (float)((float)y + (*(arg->s) == NO_ALIASING ? 0 : \
					f_random())) / (float)arg->rt->r_view->h;

				ray = camera_ray(arg->scene->cam, u, v);

				temp = rt_color(ray, arg->scene, 0, \
					(*(arg->s) == -NO_ALIASING ? 1 : MAX_DEPTH));
				v3_set(arg->tab[x][y], temp->x + arg->tab[x][y]->x, \
					temp->y + arg->tab[x][y]->y, \
					temp->z + arg->tab[x][y]->z);
				free_ray(ray);
				v3_set(temp, sqrt(arg->tab[x][y]->x / *(arg->s)), \
					sqrt(arg->tab[x][y]->y / *(arg->s)), \
					sqrt(arg->tab[x][y]->z / *(arg->s)));
			}
			else
			{
				arg->rt->render = 0;
				return ;
			}
			pixel = vec3_to_sdlcolor(*(temp));
			esdl_put_pixel(arg->rt->s_view, x, y, esdl_color_to_int(pixel));
			v3_free(temp);
			++x;
		}
		y += arg->rt->m_thread;
	}
	++(*(arg->s));
}
