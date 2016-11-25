/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_object.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 00:30:30 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/25 02:32:09 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	*select_obj(t_vec3 *v, const float f, const UCHAR t)
{
	void	*p;

	if (t == OBJ_PLANE)
		p = (void*)new_plane(v, f);
	else if (t == OBJ_SPHERE)
		p = (void*)new_sphere(v, f);
	return (p);
}

static void	*select_hit(const UCHAR t)
{
	void	*f;

	if (t == OBJ_PLANE)
		f = (void*)&intersect_plane;
	else if (t == OBJ_SPHERE)
		f = (void*)&intersect_sphere;
	return (f);
}

t_obj		*create_object(t_vec3 *pos, const float param, const int color, \
	const UCHAR type)
{
	t_obj	*o;

	o = malloc(sizeof(t_obj));
	o->pos = pos;
	o->color = color;
	o->type = type;
	o->p_obj = select_obj(o->pos, param, o->type);
	o->hit = select_hit(o->type);
	return (o);
}
