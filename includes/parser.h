/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 13:55:19 by qduperon          #+#    #+#             */
/*   Updated: 2017/01/03 17:35:05 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct 	s_c
{
	t_vec3		*origin;
	t_vec3		*v1;
	t_vec3		*v2;
	t_vec3		*sum;
	t_vec3		*u;
	t_vec3		*v;
	t_vec3		*w;
	t_vec3		*hor;
	t_vec3		*low_left_corner;
	t_vec3		*vert;
	t_vec3		look_f;
	t_vec3		look_at;
	t_vec3		v_up;
	float		fov;
	float		ap;
	float		half_height;
	float		half_width;
	float		lens_radius;
	float		focus;
}				t_c;

#endif
