/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 01:43:54 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/25 02:44:33 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere	*new_sphere(t_vec3 *center, const float radius)
{
	t_sphere		*s;

	s = malloc(sizeof(t_sphere));
	s->center = center;
	s->radius = radius;
	return (s);
}

t_vec3		*intersect_sphere(void *sphere, t_vec3 *ray)
{
	t_sphere	*s;
	t_vec3		*vec;

	s = (t_sphere*)sphere;
	vec = malloc(sizeof(t_vec3));
	return (vec);
}
