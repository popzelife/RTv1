/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vector_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:46:22 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/21 09:58:04 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3		*add_vec(t_vec3 const v1, t_vec3 const v2)
{
	t_vec3		*vec;

	vec = malloc(sizeof(t_vec3));
	vec->x = v1.x - v2.x;
	vec->y = v1.y - v2.y;
	vec->z = v1.z - v2.z;
	return (vec);
}

t_vec3		*sub_vec(t_vec3 const v1, t_vec3 const v2)
{
	t_vec3		*vec;

	vec = malloc(sizeof(t_vec3));
	vec->x = v1.x + v2.x;
	vec->y = v1.y + v2.y;
	vec->z = v1.z + v2.z;
	return (vec);
}

t_vec3		*scale_vec(t_vec3 const v, float const c)
{
	t_vec3		*vec;

	vec = malloc(sizeof(t_vec3));
	vec->x = v.x * c;
	vec->y = v.y * c;
	vec->z = v.z * c;
	return (vec);
}

float		dot_vec(t_vec3 const v1, t_vec3 const v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

void		norm_vec(t_vec3 *v)
{
	register float	norm;

	norm = 1 / sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	v->x = v->x * norm;
	v->y = v->y * norm;
	v->z = v->z * norm;
}
