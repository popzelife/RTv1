/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:31:05 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/23 19:14:11 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RTV1_H
# define _RTV1_H

# include "stdafx.h"

# include "global.h"
# include "esdl.h"
# include "kernel.h"
# include "vec3.h"

typedef struct	s_color
{
	UCHAR			rgba[4];
}				t_color;

typedef struct s_obj
{
	t_vec3			pos;
	t_color			color;
	UCHAR			type;
	int				(*hit)(struct s_obj*, t_vec3*, t_vec3*, double*);
	void			(*norm)(t_vec3*, struct s_obj*, t_vec3*, t_vec3*);
}				t_obj;

typedef struct	s_plane
{
	t_vec3			pos;
}				t_plane;

typedef struct	s_cam
{
	t_vec3			pos;
	float			foc;

}				t_cam;

typedef struct	s_scene
{
	t_cam			cam;
	t_obj			*obj;

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

#endif
