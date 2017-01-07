/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:04:21 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/04 18:08:34 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3		v3(double const x, double const y, double const z)
{
	t_vec3		vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec3		*v3_new_vec(double const x, double const y, double const z)
{
	t_vec3		*vec;

	vec = malloc(sizeof(t_vec3));
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

t_vec3		*v3_copy_vec(t_vec3 const v)
{
	return (v3_new_vec(v.x, v.y, v.z));
}

void		v3_set(t_vec3 *v, double const x, double const y, double const z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

void		v3_free(t_vec3 *v)
{
	if (v)
		free(v);
}

double		v3_access(t_vec3 *v, int i)
{
	if (v)
	{
		if (i == 0)
			return (v->x);
		else if (i == 1)
			return (v->y);
		else if (i == 2)
			return (v->z);
	}
	return (0.0);
}
