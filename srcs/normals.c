/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:08:37 by pmartine          #+#    #+#             */
/*   Updated: 2017/01/27 19:14:59 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	plane_normal(t_vec3 *norm, t_obj *hit_obj)
{
	norm->x = 0;
	norm->y = 0;
	norm->z = 1;
	//vector_rotation(norm, hit_obj, 0);
}

static void	sphere_normal(t_vec3 *norm, t_obj *hit_obj, t_vec3 *hit_pt)
{
	norm->x = hit_pt->x - hit_obj->crd->x;
	norm->y = hit_pt->y - hit_obj->crd->y;
	norm->z = hit_pt->z - hit_obj->crd->z;
	v3_normalize(norm);
}

static void	cylinder_normal(t_vec3 *norm, t_obj *hit_obj, t_vec3 *hit_pt)
{
	set_vec(norm, hit_obj->crd, hit_pt);
	//vector_rotation(norm, hit_obj, 1);
	norm->z = 0;
	//vector_rotation(norm, hit_obj, 0);
	v3_normalize(norm);
}

static void	cone_normal(t_vec3 *norm, t_obj *hit_obj, t_vec3 *hit_pt)
{
	set_vec(norm, hit_obj->crd, hit_pt);
	//vector_rotation(norm, hit_obj, 1);
	norm->z = (norm->x * norm->x + norm->y * norm->y) / -norm->z;
	//vector_rotation(norm, hit_obj, 0);
	v3_normalize(norm);
}

void		get_normal(t_vector3 *norm, t_obj *hit_obj, t_vec3 *hit_pt)
{
	if (hit_obj->type == OBJ_PLANE_XY)
		plane_normal(norm, hit_obj);
	else if (hit_obj->type == OBJ_SPHERE)
		sphere_normal(norm, hit_obj, hit_pt);
	else if (hit_obj->type == OBJ_CONE)
		cone_normal(norm, hit_obj, hit_pt);
	else if (hit_obj->type == OBJ_CYLINDER)
		cylinder_normal(norm, hit_obj, hit_pt);
}
