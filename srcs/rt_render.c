/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:38:18 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/05 18:50:38 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
  All vectors need to get a unit length #v3_normalize()
*/

static SDL_Color	vec3_to_sdlcolor(t_vec3 v)
{
	SDL_Color	c;

	c.r = v.x * 255.99;
	c.g = v.y * 255.99;
	c.b = v.z * 255.99;
	c.a = 255;
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
		}
		++i;
	}
	return (hit_anything);
}

t_vec3				*color(t_ray *ray, t_scene *scene, int depth)
{
	t_hit		param;
	t_vec3		*unit_dir;
	t_vec3		*v1;
	t_vec3		*v2;
	t_vec3		*ret;
	t_vec3		*target;

	t_vec3		*emission;
	t_ray		*scattered;
	t_vec3		*attenuation;
	t_vec3		*reflected;
	float		t;

	param.pos = v3_new_vec(0.0, 0.0, 0.0);
	param.normal = v3_new_vec(0.0, 0.0, 0.0);
	if (hit_list(scene, ray, 0.001, FLT_MAX, &param))
	{
		if (depth < MAX_DEPTH)// && param.material->scatter(ray, param, \
			//attenuation, scattered))
		{

			/*
			  Pick material as for now scatter func_ptr* doesn't work
			*/

			if (param.material->type_mat == MAT_METAL)
			{
				v1 = v3_unit_vec(*(ray->dir));
				reflected = reflect(*v1, *(param.normal));
				scattered = new_ray(v3_copy_vec(*param.pos), reflected);
				attenuation = param.material->albedo;
				v3_free(v1);

				if (v3_dot_float(*(scattered->dir), *(param.normal)) <= 0)
				{
					v3_free(param.pos);
					v3_free(param.normal);
					free_ray(scattered);
					return (v3_new_vec(0.0, 0.0, 0.0));
				}
			}
			else if (param.material->type_mat == MAT_LAMBERT)
			{
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
			else
			{
				v3_free(param.pos);
				v3_free(param.normal);
				return (v3_new_vec(0.0, 0.0, 0.0));
			}

			/*
			  Does the job for rendering material
			*/

			emission = color(scattered, scene, depth + 1);
			ret = v3_multiply_vec(*attenuation, *emission);
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
			return (v3_new_vec(0.0, 0.0, 0.0));
		}
	}
	else
	{
		/*
		  Draw skybox
		*/

		unit_dir = v3_unit_vec(*ray->dir);
		t = 0.5 * (unit_dir->y + 1.0);
		v1 = v3_scale_vec(v3(1.0, 1.0, 1.0), 1.0 - t);
		v2 = v3_scale_vec(v3(0.5, 0.7, 1.0), t);
		ret = v3_add_vec(*v1, *v2);

		v3_free(unit_dir);
		v3_free(v1);
		v3_free(v2);
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
				u = (float)((float)x + (ALIASING == NO_ALIASING ? 0 : \
					f_random())) / (float)arg->rt->r_view->w;
				v = (float)((float)y + (ALIASING == NO_ALIASING ? 0 : \
					f_random())) / (float)arg->rt->r_view->h;

				ray = camera_ray(arg->scene->cam, u, v);

				temp = color(ray, arg->scene, 0);
				v3_set(arg->tab[x][y], temp->x + arg->tab[x][y]->x, \
					temp->y + arg->tab[x][y]->y, \
					temp->z + arg->tab[x][y]->z);
				free_ray(ray);
				v3_set(temp, sqrt(arg->tab[x][y]->x / *(arg->s)), \
					sqrt(arg->tab[x][y]->y / *(arg->s)), \
					sqrt(arg->tab[x][y]->z / *(arg->s)));
			}
			else
				return ;
			pixel = vec3_to_sdlcolor(*(temp));
			esdl_put_pixel(arg->rt->s_view, arg->rt->r_view->w - (x + 1), \
				arg->rt->r_view->h - (y + 1), esdl_color_to_int(pixel));
			v3_free(temp);
			++x;
		}
		y += 5;
	}
	++(*(arg->s));
}
