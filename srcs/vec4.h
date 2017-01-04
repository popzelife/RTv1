/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 09:56:32 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/04 10:02:31 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VEC4_H
# define _VEC4_H

typedef struct	s_vec4
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_vec4;

t_vec4		v4(float const x, float const y, float const z, float const w);
t_vec4		*v4_new_vec(float const x, float const y, float const z, \
	float const w);
t_vec4		*v4_copy_vec(t_vec4 const v);
void		v4_set(t_vec4 *v, t_vec3 const xyz, float const w);
void		v4_free(t_vec4 *v);

t_vec4		*v4_add_vec(t_vec4 const v1, t_vec4 const v2);
t_vec4		*v4_sub_vec(t_vec4 const v1, t_vec4 const v2);
t_vec4		*v4_cross_vec(t_vec4 const v1, t_vec4 const v2);
t_vec4		*v4_multiply_vec(t_vec4 const v1, t_vec4 const v2);
t_vec4		*v4_scale_vec(t_vec4 const v, float const c);
t_vec4		*v4_div_vec(t_vec4 const v, float const c);

void		v4_normalize(t_vec4 *v);
void		v4_negative(t_vec4 *v);

float		v4_dot_float(t_vec4 const v1, t_vec4 const v2);
float		v4_magnitude_float(t_vec4 const v);
float		v4_lenght_float(t_vec4 const v);

t_vec4		*v4_unit_vec(t_vec4 const v);

#endif
