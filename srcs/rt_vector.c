/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:04:21 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/16 16:28:40 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3		*new_vec(float const x, float const y, float const z)
{
	t_vec3		*vec;

	vec = malloc(sizeof(t_vec3));
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

t_vec3		*copy_vec(t_vec3 const v)
{
	t_vec3		*vec;

	vec = malloc(sizeof(t_vec3));
	vec->x = v.x;
	vec->y = v.y;
	vec->z = v.z;
	return (vec);
}
