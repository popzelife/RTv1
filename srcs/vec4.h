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
	double		x;
	double		y;
	double		z;
	double		w;
}				t_vec4;

t_vec4		v4(double const x, double const y, double const z, double const w);
t_vec4		*v4_new_vec(double const x, double const y, double const z, \
	double const w);
t_vec4		*v4_copy_vec(t_vec4 const v);
void		v4_set(t_vec4 *v, t_vec3 const xyz, double const w);
void		v4_free(t_vec4 *v);

t_vec4		*v4_add_vec(t_vec4 const v1, t_vec4 const v2);
t_vec4		*v4_sub_vec(t_vec4 const v1, t_vec4 const v2);
t_vec4		*v4_cross_vec(t_vec4 const v1, t_vec4 const v2);
t_vec4		*v4_multiply_vec(t_vec4 const v1, t_vec4 const v2);
t_vec4		*v4_scale_vec(t_vec4 const v, double const c);
t_vec4		*v4_div_vec(t_vec4 const v, double const c);

void		v4_normalize(t_vec4 *v);
void		v4_negative(t_vec4 *v);

double		v4_dot_double(t_vec4 const v1, t_vec4 const v2);
double		v4_magnitude_double(t_vec4 const v);
double		v4_lenght_double(t_vec4 const v);

t_vec4		*v4_unit_vec(t_vec4 const v);

#endif
