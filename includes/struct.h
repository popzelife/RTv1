/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:40:28 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/15 21:43:59 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STRUCT_H
# define _STRUCT_H

/*
  Ray
*/

typedef struct	s_ray
{
	t_vec3			*orig;
	t_vec3			*dir;
}				t_ray;

/*
  Param link object and material for rendering
*/

typedef struct s_hit
{
	float			t;
	int				i_lst;
	t_vec3			*pos;
	t_vec3			*normal;
	struct s_mat	*material;
}				t_hit;

/*
  Materials
*/

typedef struct s_mat
{
	UCHAR			type_mat;
	t_vec3			*albedo;
	t_vec3			*emitted;
	float			t;
	BOOL			(*scatter)(const t_ray*, const t_hit, t_vec3*, t_ray*);
}				t_mat;

/*
  Objects
*/

typedef struct	s_plane
{
	float			distance;
}				t_plane;

typedef struct	s_sphere
{
	t_vec3			*center;
	float			radius;
	float			radius2;
}				t_sphere;

/*
  Scene holder
*/

typedef struct s_obj
{
	UCHAR			type_obj;
	void			*p_obj;
	BOOL			(*hit)(void*, const t_ray*, const float, const float, \
		t_hit*);
	t_mat			*p_mat;
}				t_obj;

typedef struct	s_cam
{
	t_vec3			*low_left_corner;
	t_vec3			*horizontal;
	t_vec3			*vertical;
	t_vec3			*orig;
	t_vec3			*u;
	t_vec3			*v;
	t_vec3			*w;
	float			lens_radius;
}				t_cam;

typedef struct	s_skybox
{
	t_vec3			*color1;
	t_vec3			*color2;
	t_vec3*			(*hit)(const struct s_skybox*, const t_ray*);
}				t_skybox;

typedef struct	s_scene
{
	t_cam			*cam;
	t_obj			**obj;
	t_skybox		*skybox;
	int				obj_nb;
}				t_scene;

/*
  Param for menu with lists rendering
*/

typedef struct	s_surfparam
{
	SDL_Rect		*rect;
	int				color;
	void			*param;
	int				i_lst;
}				t_surfparam;

typedef struct	s_strparam
{
	t_font			font;
	char*			string;
	int				xy[2];
	int				i_lst;
}				t_strparam;

typedef struct	s_surface
{
	SDL_Surface			*surf;
	SDL_Texture			*text;
	SDL_Rect			*rect;
	struct s_surface	*next;
}				t_surface;

typedef struct	s_string
{
	t_text			text;
	struct s_string	*next;
}				t_string;

/*
  Mini 3D view rendering for menu
*/

typedef struct	s_viewparam
{
	t_scene			*scene;
	t_obj			*obj;

	char			str_obj[128];
	char			str_pos[128];
	char			str_param_o[128];
	char			str_mat[128];
	char			str_color[128];
	char			str_param_m[128];
}				t_viewparam;

typedef struct	s_imgparam
{
	char			*path;
}				t_imgparam;

/*
  Menu view
*/

typedef struct	s_panel
{
	t_surface		*lst_surf;
	t_string		*lst_string;

	t_viewparam		*viewparam;
	t_imgparam		*imgparam;

	t_font			title1;
	t_font			sub_title1;
	t_font			word1;
	t_text			objview;
}				t_panel;

/*
  Param for rendering
*/

typedef struct	s_iter
{
	int				s;
	struct s_iter	*next;
}				t_iter;

/*
  Raytracer main
*/

typedef struct	s_rt
{
	t_esdl			*esdl;
	t_scene			*scene;

	SDL_Window		*win_temp;
	SDL_Texture		*t_load;

	SDL_Rect		*r_view;
	SDL_Surface		*s_view;
	SDL_Texture		*t_view;

	SDL_Rect		*r_menu;
	SDL_Surface		*s_menu;
	SDL_Texture		*t_menu;

	t_panel			*panel;

	int				render;

	int				x;
	int				y;
	int				s;
	t_vec3			*brush;
	t_vec3			****paint;

	t_vec3			***tab;
	t_iter			*iter;
	void			*stack;
	int				m_thread;
	struct s_thread	*t;

	pthread_t		render_th;
	pthread_t		display_th;
	pthread_mutex_t	mutex;
	pthread_cond_t	display_cond;
}				t_rt;

/*
  Multithreading
*/

typedef struct	s_tharg
{
	t_rt		*rt;
	t_scene		*scene;
	int			j;

	t_vec3		***tab;
	int			*s;
}				t_tharg;

typedef struct	s_thread
{
	pthread_t			thread;
	pthread_attr_t		attr;
	t_tharg				arg;
	struct s_thread		*next;
}				t_thread;

#endif