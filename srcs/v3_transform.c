/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 22:57:30 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/25 00:50:06 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		v3_negative(t_vec3 *v)
{
	v->x *= -1;
	v->y *= -1;
	v->z *= -1;
}

void		v3_normalize(t_vec3 *v)
{
	float	m;

	m = v3_magnitude_float(*v);
	v->x *= m;
	v->y *= m;
	v->z *= m;
}

float		v3_dot_float(t_vec3 const v1, t_vec3 const v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

float		v3_magnitude_float(t_vec3 const v)
{
	return (1 / sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
}
