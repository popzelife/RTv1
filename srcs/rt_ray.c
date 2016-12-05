/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:54:12 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/29 19:47:38 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_ray		*new_ray(t_vec3 *orig, t_vec3 *dir)
{
	t_ray		*r;

	r = malloc(sizeof(t_ray));
	r->orig = orig;
	r->dir = dir;
	return (r);
}

t_vec3		*ray_point_at(const t_ray *ray, const float point)
{
	t_vec3		*v;
	t_vec3		*s;

	s = v3_scale_vec(*ray->dir, point);
	v = v3_add_vec(*ray->orig, *s);
	v3_free(s);
	return (v);
}

void		free_ray(t_ray *ray)
{
	if (ray)
	{
		v3_free(ray->orig);
		v3_free(ray->dir);
		free(ray);
	}
}
