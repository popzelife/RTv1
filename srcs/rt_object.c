/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_object.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: popzelife <popzelife@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 00:30:30 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/09 05:44:49 by popzelife        ###   ########.fr       */
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
		f = (void*)&hit_sphere;
	else
		f = NULL;
	return (f);
}

static void	*select_scatter(const UCHAR t)
{
	void	*s;

	if (t == MAT_LAMBERT)
		s = (void*)&scatter_lambertian;
	else if (t == MAT_METAL)
		s = (void*)&scatter_metal;
	else if (t == MAT_DIELECT)
		s = (void*)&scatter_dielectric;
	else if (t == MAT_DIFF_LIGHT)
		s = (void*)&scatter_diffuse_light;
	else
		s = NULL;
	return (s);
}

t_obj		*new_object(t_vec3 *pos, const float param, \
	const UCHAR type_obj, t_vec3 *albedo, const UCHAR type_mat, const float t)
{
	t_obj	*o;

	o = malloc(sizeof(t_obj));
	o->type_obj = type_obj;
	o->p_obj = select_obj(pos, param, o->type_obj);
	o->hit = select_hit(o->type_obj);
	o->p_mat = new_material(albedo, t);
	o->p_mat->type_mat = type_mat;
	o->p_mat->scatter = select_scatter(o->type_obj);
	if (type_mat == MAT_DIFF_LIGHT)
		o->p_mat->emitted = albedo;
	else
		o->p_mat->emitted = v3_new_vec(0.0, 0.0, 0.0);
	return (o);
}
