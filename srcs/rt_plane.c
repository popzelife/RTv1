/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:43:46 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/28 18:18:44 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_plane		*new_plane(const float distance)
{
	t_plane		*p;

	p = malloc(sizeof(t_plane));
	p->distance = distance;
	return (p);
}

/*t_vec3		*intersect_plane(void *plane, t_vec3 *ray)
{
	(void)ray;
	t_plane		*p;
	t_vec3		*vec;

	p = (t_plane*)plane;
	vec = malloc(sizeof(t_vec3));
	return (vec);
}*/
