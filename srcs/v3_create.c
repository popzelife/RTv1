/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:04:21 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/25 00:23:41 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3		*v3_new_vec(float const x, float const y, float const z)
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

void		v3_free(t_vec3 *v)
{
	if (v)
		free(v);
}
