/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:31:05 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/06 19:02:26 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RTV1_H
# define _RTV1_H

# include "stdafx.h"

# include "global.h"
# include "esdl.h"
# include "kernel.h"
# include "vec3.h"

typedef struct	s_ray
{
	t_vec3			*orig;
	t_vec3			*dir;
}				t_ray;

typedef struct s_hit
{
	float			t;
	t_vec3			*pos;
	t_vec3			*normal;
	struct s_mat	*material;
}				t_hit;

typedef struct s_mat
{
	UCHAR			type_mat;
	t_vec3			*albedo;
	BOOL			(*scatter)(const t_ray*, const t_hit, t_vec3*, t_ray*);
}				t_mat;

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

typedef struct s_obj
{
	UCHAR			type_obj;
	void			*p_obj;
	BOOL			(*hit)(void*, const t_ray*, const float, const float, \
		t_hit*);
	t_mat			*p_mat;
}				t_obj;

typedef struct s_light
{
	t_vec3			*vec;
}				t_light;

typedef struct	s_cam
{
	t_vec3			*low_left_corner;
	t_vec3			*horizontal;
	t_vec3			*vertical;
	t_vec3			*orig;
	t_vec3			*u;
	t_vec3			*v;
	t_vec3			*w;
}				t_cam;

typedef struct	s_scene
{
	t_cam			*cam;
	t_obj			**obj;
	t_light			**light;
	int				obj_nb;
	int				light_nb;
}				t_scene;

typedef struct	s_iter
{
	int				s;
	struct s_iter	*next;
}				t_iter;

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

	int				render;

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

t_iter		*lst_new_iter(t_iter **iter, int i);
t_thread	*lst_new_thread(t_thread **thread);

t_scene		*new_scene(t_cam *cam, t_obj **obj, t_light **light);
t_scene		*init_scene(t_rt *rt);

void		draw_view(t_rt *rt);
void		draw_menu(t_rt *rt);

void		render(t_rt *rt);
void		thread_render(t_tharg *arg);

void		reset_render(t_rt *rt);

void		rt_events(t_rt *rt, int ret);

t_vec3		*color(t_ray *ray, t_scene *scene, int depth, int max_depth);

t_ray		*new_ray(t_vec3 *orig, t_vec3 *dir);
t_vec3		*ray_point_at(const t_ray *ray, const float point);
void		free_ray(t_ray *ray);

t_cam		*new_camera(t_vec3 *lw_lf, t_vec3 *hor, t_vec3 *ver, t_vec3 *ori, \
	t_vec3 *u, t_vec3 *v, t_vec3 *w);
t_cam		*init_camera(const t_vec3 look_from, const t_vec3 look_at, \
	const t_vec3 v_up, float vfov, float aspect);
t_ray		*camera_ray(t_cam *cam, float u, float v);

t_obj		*new_object(t_vec3 *pos, const float param, \
	const UCHAR type_obj, t_vec3 *albedo, const UCHAR type_mat);

t_sphere	*new_sphere(t_vec3 *center, const float radius);
BOOL		hit_sphere(void *obj, const t_ray *r, const float t_min, \
	const float t_max, t_hit *param);

t_mat		*new_material(t_vec3 *albedo);

t_vec3		*reflect(const t_vec3 v, const t_vec3 n);
BOOL		scatter_lambertian(const t_ray *ray, const t_hit param, \
	t_vec3 *attenuation, t_ray *scattered);
BOOL		scatter_metal(const t_ray *ray, const t_hit param, \
	t_vec3 *attenuation, t_ray *scattered);


t_vec3		*random_in_unit_sphere();
float		f_random();

#endif
