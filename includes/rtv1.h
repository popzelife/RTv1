/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:31:05 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/25 11:35:30 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RTV1_H
# define _RTV1_H

# include "stdafx.h"

# include "global.h"
# include "esdl.h"
# include "kernel.h"
# include "vec3.h"

typedef struct	s_plane
{
	t_vec3			*normal;
	float			distance;
}				t_plane;

typedef struct	s_sphere
{
	t_vec3			*center;
	float			radius;
}				t_sphere;

typedef struct s_obj
{
	t_vec3			*pos;
	int				color;
	UCHAR			type;
	void			*p_obj;
	t_vec3			(*hit)(void*, t_vec3*);
}				t_obj;

typedef struct s_light
{
	t_vec3			*vec;
}				t_light;

typedef struct	s_cam
{
	t_vec3			*pos;
	t_vec3			*dir;
	t_vec3			*right;
	t_vec3			*up;
}				t_cam;

typedef struct	s_scene
{
	t_cam			*cam;
	t_obj			**obj;
	t_light			**light;
	int				obj_nb;
	int				light_nb;
}				t_scene;

typedef struct	s_rt
{
	t_esdl			*esdl;
	SDL_Texture		*t_load;
	SDL_Rect		*r_view;
	SDL_Surface		*s_view;
	SDL_Texture		*t_view;
	SDL_Rect		*r_menu;
	SDL_Surface		*s_menu;
	SDL_Texture		*t_menu;
}				t_rt;

t_scene		*new_scene(t_cam *cam, t_obj **obj, t_light **light);
t_scene		*init_scene(void);

void		draw_view(t_rt *rt, t_scene *scene);
void		draw_menu(t_rt *rt);

t_cam		*new_camera(t_vec3 *pos, t_vec3 *dir, t_vec3 *right, t_vec3 *up);
t_cam		*init_camera(t_vec3 *pos, t_vec3 look_at);

t_obj		*new_object(t_vec3 *pos, const float param, const int color, \
	const UCHAR type);

t_plane		*new_plane(t_vec3 *normal, const float distance);
t_vec3		*intersect_plane(void *plane, t_vec3 *ray);

t_sphere	*new_sphere(t_vec3 *center, const float radius);
t_vec3		*intersect_sphere(void *sphere, t_vec3 *ray);

#endif
