/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esdl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: popzelife <popzelife@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:14:03 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/12 21:40:57 by popzelife        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ESDL_H
# define _ESDL_H

# ifdef __APPLE__
# include <SDL.h>
# include <SDL_ttf.h>
# else
# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>
# endif

typedef struct			s_input
{
	char				key[SDL_NUM_SCANCODES];
	char				button[8];
	int					mw_y;
	int					m_x;
	int					m_y;
	int					m_r_x;
	int					m_r_y;
}						t_input;

typedef	struct			s_timer
{
	int					fps;
	int					current;
	int					update;
	int					limit;
	char				title[128];
	UINT				framelimit;
}						t_timer;

typedef struct			s_engine
{
	SDL_Window			*win;
	int					rx;
	int					ry;
	SDL_Renderer		*render;
	t_input				input;
}						t_engine;

typedef	struct			s_esdl
{
	t_engine			eng;
	t_timer				fps;
	int					run;
	int					ttf;
}						t_esdl;

int			esdl_init(t_esdl *esdl, const int rx, const int ry, char * name);
SDL_Surface	*esdl_create_surface(int width, int height);

int			esdl_update_events(t_input *in, int *run);
int			esdl_check_input(t_input *in, const int input);

void		esdl_fps_limit(t_esdl *esdl);
void		esdl_fps_counter(t_esdl *esdl);

int			esdl_color_to_int(SDL_Color color);
SDL_Color	esdl_int_to_color(int color);
void		esdl_put_pixel(SDL_Surface *surf, \
	const int x, const int y, const int color);
void		esdl_draw_filled_square(SDL_Surface *surf, \
	const SDL_Rect rect, const int color);
void		esdl_clear_surface(SDL_Surface *surf, const int color);

SDL_Texture	*esdl_load_texture(t_esdl *esdl, const char *path, int *w, int *h);

void		esdl_exit(t_esdl *esdl);

/*
  SDL_TTF
*/

int			esdl_init_ttf(t_esdl *esdl);

#endif
