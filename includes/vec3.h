/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:39:43 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/04 18:08:33 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VEC3_H
# define _VEC3_H

typedef struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

t_vec3		v3(double const x, double const y, double const z);
t_vec3		*v3_new_vec(double const x, double const y, double const z);
t_vec3		*v3_copy_vec(t_vec3 const v);
void		v3_set(t_vec3 *v, double const x, double const y, double const z);
void		v3_free(t_vec3 *v);

double		v3_access(t_vec3 *v, int i);

t_vec3		*v3_add_vec(t_vec3 const v1, t_vec3 const v2);
t_vec3		*v3_sub_vec(t_vec3 const v1, t_vec3 const v2);
t_vec3		*v3_cross_vec(t_vec3 const v1, t_vec3 const v2);
t_vec3		*v3_multiply_vec(t_vec3 const v1, t_vec3 const v2);
t_vec3		*v3_scale_vec(t_vec3 const v, double const c);
t_vec3		*v3_div_vec(t_vec3 const v, double const c);

void		v3_normalize(t_vec3 *v);
void		v3_negative(t_vec3 *v);

double		v3_dot_double(t_vec3 const v1, t_vec3 const v2);
double		v3_magnitude_double(t_vec3 const v);
double		v3_lenght_double(t_vec3 const v);

t_vec3		*v3_unit_vec(t_vec3 const v);

#endif
