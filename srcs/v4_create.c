/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v4_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:03:01 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/04 10:05:36 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rtv1.h"

t_vec4		v4(float const x, float const y, float const z, float const w)
{
	t_vec4		vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = w;
	return (vec);
}

t_vec4		*v4_new_vec(float const x, float const y, float const z, \
	float const w)
{
	t_vec4		*vec;

	vec = malloc(sizeof(t_vec4));
	vec->x = x;
	vec->y = y;
	vec->z = z;
	vec->w = w;
	return (vec);
}

t_vec4		*v4_copy_vec(t_vec4 const v)
{
	return (v4_new_vec(v.x, v.y, v.z, v.w));
}

void		v4_set(t_vec4 *v, t_vec3 const xyz, float const w)
{
	v->x = xyz.x;
	v->y = xyz.y;
	v->z = xyz.z;
	v->w = w;
}

void		v4_free(t_vec4 *v)
{
	if (v)
		free(v);
}
