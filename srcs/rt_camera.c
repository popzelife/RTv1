/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 22:11:23 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/28 21:11:44 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cam		*new_camera(t_vec3 *lw_lft, t_vec3 *hor, t_vec3 *vert, t_vec3 *orig)
{
	t_cam		*c;

	c = malloc(sizeof(t_cam));
	c->low_left_corner = lw_lft;
	c->horizontal = hor;
	c->vertical = vert;
	c->orig = orig;
	return (c);
}

t_cam		*init_camera(t_vec3 *eye, t_vec3 look_at)
{
	t_vec3			*low_left_corner;
	t_vec3			*horizontal;
	t_vec3			*vertical;
	
	horizontal = v3_new_vec(2.4, 0.0, 0.0);
	vertical = v3_new_vec(0.0, 2.0, 0.0);
	low_left_corner = v3_new_vec(look_at.x - 1.2, look_at.y - 1.0, look_at.z);
	return (new_camera(low_left_corner, horizontal, vertical, eye));
}

t_ray		*camera_ray(t_cam *cam, float u, float v)
{
	t_ray			*ray;
	t_vec3			*dir;
	t_vec3			*orig;
	t_vec3			*v1;
	t_vec3			*v2;
	t_vec3			*vadd;

	v1 = v3_scale_vec(*(cam->horizontal), u);
	v2 = v3_scale_vec(*(cam->vertical), v);
	vadd = v3_add_vec(*v1, *v2);

	dir = v3_add_vec(*(cam->low_left_corner), *vadd);
	orig = v3_copy_vec(*(cam->orig));
	ray = new_ray(orig, dir);

	v3_free(v1);
	v3_free(v2);
	v3_free(vadd);
	return (ray);
}
