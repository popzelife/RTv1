/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 22:11:23 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/07 17:39:52 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cam		*new_camera(t_vec3 *lw_lf, t_vec3 *hor, t_vec3 *ver, t_vec3 *ori, \
	t_vec3 *u, t_vec3 *v, t_vec3 *w, float lens_radius)
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
	c->lens_radius = lens_radius;
	return (c);
}

t_cam		*init_camera(const t_vec3 look_from, const t_vec3 look_at, \
	const t_vec3 v_up, float vfov, float aspect, float aperture, float focus)
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
	float			lens_radius;
	
	lens_radius = aperture / 2;
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

	v1 = v3_scale_vec(*u, half_width * focus);
	v2 = v3_sub_vec(*origin, *v1);
	v3_free(v1);
	v1 = v3_scale_vec(*v, half_height * focus);
	sum = v3_sub_vec(*v2, *v1);
	v3_free(v1);
	v3_free(v2);
	v1 = v3_scale_vec(*w, focus);
	low_left_corner = v3_sub_vec(*sum, *v1);
	v3_free(v1);

	v3_free(sum);
	horizontal = v3_scale_vec(*u, 2.0 * half_width * focus);
	vertical = v3_scale_vec(*v, 2.0 * half_height * focus);

	return (new_camera(low_left_corner, horizontal, vertical, origin, \
		u, v, w, lens_radius));
}

t_ray		*camera_ray(t_cam *cam, float s, float t)
{
	t_vec3			*radius;
	t_vec3			*offset;
	t_vec3			*dir;
	t_vec3			*orig;

	t_vec3			*v1;
	t_vec3			*v2;
	t_vec3			*sum;

	v1 = random_in_unit_disk();
	radius = v3_scale_vec(*v1, cam->lens_radius);
	v3_free(v1);

	v1 = v3_scale_vec(*(cam->u), radius->x);
	v2 = v3_scale_vec(*(cam->v), radius->y);
	offset = v3_add_vec(*v1, *v2);
	v3_free(v1);
	v3_free(v2);
	orig = v3_add_vec(*(cam->orig), *offset);

	v1 = v3_scale_vec(*(cam->horizontal), s);
	v2 = v3_add_vec(*(cam->low_left_corner), *v1);
	v3_free(v1);
	v1 = v3_scale_vec(*(cam->vertical), t);
	sum = v3_add_vec(*v2, *v1);
	v3_free(v1);
	v3_free(v2);
	v1 = v3_sub_vec(*sum, *(cam->orig));
	v3_free(sum);
	dir = v3_sub_vec(*v1, *offset);

	v3_free(radius);
	v3_free(offset);
	v3_free(v1);
	return (new_ray(orig, dir));
}
