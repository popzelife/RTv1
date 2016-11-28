/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_object.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 00:30:30 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/28 19:25:39 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	*select_obj(t_vec3 *p, const float f, const UCHAR t)
{
	void	*o;

	if (t == OBJ_SPHERE)
		o = (void*)new_sphere(p, f);
	else
		o = NULL;
	return (o);
}

static void	*select_hit(const UCHAR t)
{
	void	*f;

	if (t == OBJ_SPHERE)
		f = &hit_sphere;
	else
		f = NULL;
	return (f);
}

t_obj		*new_object(t_vec3 *pos, const float param, const int color, \
	const UCHAR type)
{
	t_obj	*o;

	o = malloc(sizeof(t_obj));
	o->color = color;
	o->type = type;
	o->p_obj = select_obj(pos, param, o->type);
	o->hit = select_hit(o->type);
	return (o);
}
