/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 22:11:23 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/03 17:44:04 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cam		*new_camera(t_vec3 *lw_lf, t_vec3 *hor, t_vec3 *ver, t_vec3 *ori, \
	t_vec3 *u, t_vec3 *v, t_vec3 *w)
{
	t_cam		*c;

	c = malloc(sizeof(t_cam));
	c->low_left_corner = lw_lf;
	c->horizontal = hor;
	c->vertical = ver;
	c->orig = ori;
	c->u = u;
	c->v = v;
	c->w = w;
	return (c);
}

t_cam		*init_camera(const t_vec3 look_from, const t_vec3 look_at, \
	const t_vec3 v_up, float vfov, float aspect)
{
	t_vec3			*origin;
	t_vec3			*low_left_corner;
	t_vec3			*horizontal;
	t_vec3			*vertical;
	t_vec3			*u;
	t_vec3			*v;
	t_vec3			*w;
	t_vec3			*v1;
	t_vec3			*v2;
	t_vec3			*sum;
	float			theta;
	float			half_height;
	float			half_width;
	
	theta = vfov * M_PI / 180.0;
	half_height = tan(theta / 2.0);
	half_width = aspect * half_height;

	origin = v3_copy_vec(look_from);
	v1 = v3_sub_vec(look_from, look_at);
	w = v3_unit_vec(*v1);
	v3_free(v1);
	v1 = v3_cross_vec(v_up, *w);
	u = v3_unit_vec(*v1);
	v3_free(v1);
	v = v3_cross_vec(*w, *u);

	v1 = v3_scale_vec(*u, half_width);
	v2 = v3_sub_vec(*origin, *v1);
	v3_free(v1);
	v1 = v3_scale_vec(*v, half_height);
	sum = v3_sub_vec(*v2, *v1);
	v3_free(v1);
	v3_free(v2);
	low_left_corner = v3_sub_vec(*sum, *w);
	v3_free(sum);
	horizontal = v3_scale_vec(*u, 2.0 * half_width);
	vertical = v3_scale_vec(*v, 2.0 * half_height);

	return (new_camera(low_left_corner, horizontal, vertical, origin, \
		u, v, w));
}

t_ray		*camera_ray(t_cam *cam, float u, float v)
{
	t_ray			*ray;
	t_vec3			*dir;
	t_vec3			*orig;
	
	t_vec3			*v1;
	t_vec3			*v2;
	t_vec3			*sum;

	v1 = v3_scale_vec(*(cam->horizontal), u);
	v2 = v3_scale_vec(*(cam->vertical), v);
	sum = v3_add_vec(*v1, *v2);

	dir = v3_add_vec(*(cam->low_left_corner), *sum);
	orig = v3_copy_vec(*(cam->orig));
	ray = new_ray(orig, dir);

	v3_free(v1);
	v3_free(v2);
	v3_free(sum);
	return (ray);
}
