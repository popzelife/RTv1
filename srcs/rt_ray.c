/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:54:12 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/21 12:13:56 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3		*init_ray()
{
	t_vec3		*vec;

	vec = malloc(sizeof(t_vec3));
    return (vec);
}

t_vec3		*intersect(t_scene const s, t_vec3 const v)
{
    (void)s;
    (void)v;
	t_vec3		*vec;

    vec = malloc(sizeof(t_vec3));
	return (vec);
}
