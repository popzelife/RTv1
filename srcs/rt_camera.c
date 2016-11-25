/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 22:11:23 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/25 00:17:30 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cam		*new_camera(t_vec3 *pos, t_vec3 *dir, t_vec3 *right, t_vec3 *up)
{
	t_cam		*c;

	c = malloc(sizeof(t_cam));
	c->pos = pos;
	c->dir = dir;
	c->right = right;
	c->up = up;
	return (c);
}

t_cam		*init_camera(t_vec3 *pos, t_vec3 look_at)
{
	t_vec3		*axe;
	t_vec3		*d;
	t_vec3		*r;
	t_vec3		*u;

	d = v3_sub_vec(*pos, look_at);
	v3_negative(d);
	v3_normalize(d);
	axe = v3_new_vec(0, 1, 0);
	r = v3_cross_vec(*axe, *d);
	v3_free(axe);
	v3_normalize(r);
	u = v3_cross_vec(*r, *d);
	return (new_camera(pos, d, r, u));
}
