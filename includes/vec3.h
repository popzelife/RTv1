/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:39:43 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/28 16:13:36 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VEC3_H
# define _VEC3_H

typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;

}				t_vec3;

t_vec3		v3(float const x, float const y, float const z);
t_vec3		*v3_new_vec(float const x, float const y, float const z);
t_vec3		*v3_copy_vec(t_vec3 const v);
void		v3_set(t_vec3 *v, float const x, float const y, float const z);
void		v3_free(t_vec3 *v);

t_vec3		*v3_add_vec(t_vec3 const v1, t_vec3 const v2);
t_vec3		*v3_sub_vec(t_vec3 const v1, t_vec3 const v2);
t_vec3		*v3_cross_vec(t_vec3 const v1, t_vec3 const v2);
t_vec3		*v3_scale_vec(t_vec3 const v, float const c);
t_vec3		*v3_div_vec(t_vec3 const v, float const c);

void		v3_normalize(t_vec3 *v);
void		v3_negative(t_vec3 *v);

float		v3_dot_float(t_vec3 const v1, t_vec3 const v2);
float		v3_magnitude_float(t_vec3 const v);
float		v3_lenght_float(t_vec3 const v);

t_vec3		*v3_unit_vec(t_vec3 const v);

#endif
