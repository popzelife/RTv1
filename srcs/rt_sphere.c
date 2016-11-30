/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 01:43:54 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/29 19:48:24 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere	*new_sphere(t_vec3 *center, const float radius)
{
	t_sphere		*s;

	s = malloc(sizeof(t_sphere));
	s->center = center;
	s->radius = radius;
	s->radius2 = radius * radius;
	return (s);
}

BOOL		hit_sphere(void *obj, const t_ray *ray, const float t_min, \
	const float t_max, t_hit *param)
{
	t_sphere	*sphere;
	t_vec3		*oc;
	t_vec3		*v;
	t_vec3		*set;
	float		a;
	float		b;
	float		c;
	float		discriminant;
	float		temp;

	sphere = (t_sphere*)obj;
	oc = v3_sub_vec(*(ray->orig), *(sphere->center));
	a = v3_dot_float(*(ray->dir), *(ray->dir));
	b = v3_dot_float(*oc, *(ray->dir));
	c = v3_dot_float(*oc, *oc) - sphere->radius2;

	discriminant = b * b - a * c;
	v3_free(oc);
	if (discriminant > 0)
	{

		temp = (-b - sqrt(discriminant)) / a;
		if (temp < t_max && temp > t_min)
		{
			param->t = temp;
			set = ray_point_at(ray, param->t);
			v3_set(param->pos, set->x, set->y, set->z);
			v3_free(set);
			v = v3_sub_vec(*(param->pos), *(sphere->center));
			set = v3_div_vec(*v, sphere->radius);
			v3_set(param->normal, set->x, set->y, set->z);
			v3_free(set);
			v3_free(v);
			return (TRUE);
		}

		temp = (-b + sqrt(discriminant)) / a;
		if (temp < t_max && temp > t_min)
		{
			param->t = temp;
			set = ray_point_at(ray, param->t);
			v3_set(param->pos, set->x, set->y, set->z);
			v3_free(set);
			v = v3_sub_vec(*(param->pos), *(sphere->center));
			set = v3_div_vec(*v, sphere->radius);
			v3_set(param->normal, set->x, set->y, set->z);
			v3_free(set);
			v3_free(v);
			return (TRUE);
		}
	}
	return (FALSE);
}
