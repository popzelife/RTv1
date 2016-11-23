/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:39:43 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/16 16:39:48 by qfremeau         ###   ########.fr       */
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

t_vec3		*new_vec(float const x, float const y, float const z);
t_vec3		*copy_vec(t_vec3 const v);

t_vec3		*add_vec(t_vec3 const v1, t_vec3 const v2);
t_vec3		*sub_vec(t_vec3 const v1, t_vec3 const v2);
t_vec3		*scale_vec(t_vec3 const v, float const c);
float		dot_vec(t_vec3 const v1, t_vec3 const v2);
void		norm_vec(t_vec3 *v);

#endif
