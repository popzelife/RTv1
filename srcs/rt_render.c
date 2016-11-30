/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:38:18 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/30 11:59:16 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
  All vectors need to get a unit length #v3_normalize()
*/

# define ALIASING		1
# define NO_DEPTH		1

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

	t_vec3		*emission;
	t_ray		*scattered = NULL;
	t_vec3		*attenuation = NULL;
	float		t;

	param.pos = v3_new_vec(0.0, 0.0, 0.0);
	param.normal = v3_new_vec(0.0, 0.0, 0.0);
	if (hit_list(scene, ray, 0.001, FLT_MAX, &param))
	{
		if (depth < 10 && param.material->scatter(param.material, ray, \
			&param, attenuation, scattered))
		{
			emission = color(scattered, scene, depth + 1);
			ret = v3_multiple_vec(*attenuation, *emission);
			v3_free(emission);
			v3_free(attenuation);
			v3_free(param.pos);
			v3_free(param.normal);
			free_ray(scattered);
			return (ret);
		}
		else
			return (v3_new_vec(0.0, 0.0, 0.0));
	}
	else
	{
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
	register int	s;
	register float	u;
	register float	v;
	t_ray			*ray;
	t_vec3			*temp;
	t_vec3			ret;
	t_vec3			*p;
	SDL_Color		pixel;

	y = arg->rt->r_view->h - arg->j;
	while (y >= 0)
	{
		x = arg->rt->r_view->w;
		while (x >= 0)
		{
			ret = v3(0, 0, 0);
			s = 0;
			while (s < ALIASING)
			{
				u = (float)((float)x + (ALIASING == NO_DEPTH ? 0 : \
					f_random())) / (float)arg->rt->r_view->w;
				v = (float)((float)y + (ALIASING == NO_DEPTH ? 0 : \
					f_random())) / (float)arg->rt->r_view->h;

				ray = camera_ray(arg->scene->cam, u, v);
				//p = ray_point_at(ray, 2.0);

				temp = color(ray, arg->scene, 0);
				ret = v3(temp->x + ret.x, temp->y + ret.y, temp->z + ret.z);

				free_ray(ray);
				++s;
			}
			ret = v3(sqrt(ret.x / ALIASING), sqrt(ret.y / ALIASING), \
				sqrt(ret.z / ALIASING));
			v3_free(temp);
			pixel = vec3_to_sdlcolor(ret);
			esdl_put_pixel(arg->rt->s_view, arg->rt->r_view->w - x, \
				arg->rt->r_view->h - y, esdl_color_to_int(pixel));

			--x;
		}
		y -= 1;
	}
}
