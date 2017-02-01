/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:08:37 by pmartine          #+#    #+#             */
/*   Updated: 2017/02/01 16:59:02 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rotation_matrix(double *absc, double *ord, double angle[3], int neg)
{
	double	k;

	if (!absc || !ord || !angle)
		return ;
	k = (*absc);
	if (neg)
	{
		*absc = k * angle[1] + (*ord) * angle[2];
		*ord = (*ord) * angle[1] - k * angle[2];
		return ;
	}
	*absc = k * angle[1] - (*ord) * angle[2];
	*ord = (*ord) * angle[1] + k * angle[2];
}

void	vector_rotation(t_vec3 *vec, t_hit *obj, int neg)
{
	if (neg)
	{
		rotation_matrix(&vec->x, &vec->y, obj->rot->x, neg);
		rotation_matrix(&vec->z, &vec->x, obj->rot->y, neg);
		rotation_matrix(&vec->y, &vec->z, obj->rot->z, neg);
	}
	else
	{
		rotation_matrix(&vec->y, &vec->z, obj->rot->x, neg);
		rotation_matrix(&vec->z, &vec->x, obj->rot->y, neg);
		rotation_matrix(&vec->x, &vec->y, obj->rot->z, neg);
	}
}

static void	plane_normal(t_vec3 *norm, t_hit *hit_obj)
{
	norm->x = 0;
	norm->y = 0;
	norm->z = 1;
	vector_rotation(norm, hit_obj, 0);
}

static void	sphere_normal(t_vec3 *norm, t_hit *hit_obj, t_vec3 *hit_pt)
{
	norm->x = hit_pt->x - hit_obj->pos->x;
	norm->y = hit_pt->y - hit_obj->pos->y;
	norm->z = hit_pt->z - hit_obj->pos->z;
	v3_normalize(norm);
}

static void	cylinder_normal(t_vec3 *norm, t_hit *hit_obj, t_vec3 *hit_pt)
{
	set_vec(norm, hit_obj->pos, hit_pt);
	vector_rotation(norm, hit_obj, 1);
	norm->z = 0;
	vector_rotation(norm, hit_obj, 0);
	v3_normalize(norm);
}

static void	cone_normal(t_vec3 *norm, t_hit *hit_obj, t_vec3 *hit_pt)
{
	set_vec(norm, hit_obj->rot, hit_pt);
	vector_rotation(norm, hit_obj, 1);
	norm->z = (norm->x * norm->x + norm->y * norm->y) / -norm->z;
	vector_rotation(norm, hit_obj, 0);
	v3_normalize(norm);
}

void		get_normal(t_vec3 *norm, t_hit *param, t_vec3 *hit_pt)
{
	if (param->type == OBJ_PLANE_XY)
		plane_normal(norm, hit_obj);
	else if (param->type == OBJ_SPHERE)
		sphere_normal(norm, hit_obj, hit_pt);
	//else if (hit_obj->type_obj == OBJ_CONE)
	//	cone_normal(norm, hit_obj, hit_pt);
	else if (param->type == OBJ_CYLINDER)
		cylinder_normal(norm, hit_obj, hit_pt);
}

/*t_vec		normale(t_obj *obj, t_env *env, t_vec cam)
  {
  t_vec	result;
  t_vec	tmp;
  t_vec	temp;

  if (obj->type == 0)
  {
  result = obj->rot;
  result = inv(result, env, obj);
  }
  else
  {
  if (obj->type == 1)
  result = sub_vect(cam, obj->pos);
  else
  {
  temp = scale_vect(obj->rot, dot_vect(env->ray_dir, obj->rot) * \
  env->d + dot_vect(sub_vect(env->cam_pos, obj->pos), obj->rot));
  if (obj->type == 2)
  temp = scale_vect(temp, \
  (1 + powf(tanf(deg_to_rad(obj->size)), 2)));
  tmp = sub_vect(cam, obj->pos);
  result = sub_vect(tmp, temp);
  }
  }
  return (norm_vect(result));
  }*/
