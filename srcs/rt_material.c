/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_material.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:46:01 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/29 19:48:09 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3		*reflect(const t_vec3 v, const t_vec3 n)
{
	t_vec3		*v1;
	t_vec3		*ret;

	v1 = v3_scale_vec(n, 2.0 * v3_dot_float(v, n));
	ret = v3_sub_vec(v, *v1);
	v3_free(v1);
	return (ret);

}

t_mat		*new_material(t_vec3 *albedo)
{
	t_mat		*m;

	m = malloc(sizeof(t_mat));
	m->albedo = albedo;
	return (m);
}

BOOL		scatter_lambertian(t_mat *mat, const t_ray *ray, \
	const t_hit *param, t_vec3 *attenuation, t_ray *scattered)
{
	t_vec3		*target;
	t_vec3		*v1;
	t_vec3		*v2;

	v1 = v3_add_vec(*(param->pos), *(param->normal));
	v2 = random_in_unit_sphere();
	target = v3_add_vec(*v1, *v2);
	v3_free(v1);
	v3_free(v2);
	scattered = new_ray(v3_copy_vec(*param->pos), \
		v3_sub_vec(*target, *(param->pos)));
	v3_free(target);
	attenuation = mat->albedo;
	return (TRUE);
}

BOOL		scatter_metal(t_mat *mat, const t_ray *ray, \
	const t_hit *param, t_vec3 *attenuation, t_ray *scattered)
{

	t_vec3		*v1;
	t_vec3		*reflected;

	v1 = v3_unit_vec(*(ray->dir));
	reflected = reflect(*v1, *(param->normal));
	scattered = new_ray(v3_copy_vec(*param->pos), reflected);
	attenuation = mat->albedo;
	v3_free(v1);
	v3_free(reflected);
	return (v3_dot_float(*(scattered->dir), *(param->normal)) > 0);
}
