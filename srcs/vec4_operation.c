/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:54:33 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/04 10:57:09 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec4		*v4_add_vec(t_vec4 const v1, t_vec4 const v2)
{
	t_vec4		*vec;

	vec = v4_new_vec(v1.x + v2.x,
					v1.y + v2.y,
					v1.z + v2.z,
					v1.w + v2.w);
	return (vec);
}

t_vec4		*v4_sub_vec(t_vec4 const v1, t_vec4 const v2)
{
	t_vec4		*vec;

	vec = v4_new_vec(v1.x - v2.x,
					v1.y - v2.y,
					v1.z - v2.z,
					v1.w - v2.w);
	return (vec);
}

t_vec4		*v4_cross_vec(t_vec4 const v1, t_vec4 const v2)
{
	t_vec4		*vec;

	vec = v4_new_vec(v1.y * v2.z - v1.z * v2.y,
					v1.z * v2.x - v1.x * v2.z,
					v1.x * v2.y - v1.y * v2.x,
					v1.x * v2.y - v1.y * v2.x);
	return (vec);
}

t_vec4		*v4_multiply_vec(t_vec4 const v1, t_vec4 const v2)
{
	t_vec3		*vec;

	vec = v4_new_vec(v1.x * v2.x,
					v1.y * v2.y,
					v1.z * v2.z,
					v1.w * v2.w);
	return (vec);
}

t_vec4		*v4_scale_vec(t_vec4 const v, float const c)
{
	t_vec4		*vec;

	vec = v4_new_vec(v.x * c,
					v.y * c,
					v.z * c,
					v.w * c);
	return (vec);
}

t_vec4		*v4_div_vec(t_vec4 const v, float const c)
{
	t_vec4		*vec;

	vec = v4_new_vec(v.x / c,
					v.y / c,
					v.z / c,
					v.w / c);
	return (vec);
}
