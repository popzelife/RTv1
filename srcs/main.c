/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 21:40:50 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/05 19:22:42 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		init_rt(t_rt *rt)
{
	SDL_Rect		*r_load;

	rt->esdl = malloc(sizeof(t_esdl));
	if (esdl_init(rt->esdl, LOAD_RX, LOAD_RY, API_NAME) == -1)
		esdl_exit(rt->esdl);
	SDL_SetWindowBordered(rt->esdl->eng.win, FALSE);
	r_load = malloc(sizeof(SDL_Rect));
	rt->t_load = esdl_load_texture(rt->esdl, LOAD_NAME, &r_load->w, &r_load->h);
	SDL_RenderClear(rt->esdl->eng.render);
	SDL_RenderCopy(rt->esdl->eng.render, rt->t_load, NULL, NULL);
	SDL_RenderPresent(rt->esdl->eng.render);
	SDL_DestroyTexture(rt->t_load);
	free(r_load);
	rt->r_view = malloc(sizeof (SDL_Rect));
	rt->r_menu = malloc(sizeof (SDL_Rect));
}

void	draw_menu(t_rt *rt)
{
	SDL_GetWindowSize(rt->win_temp, &rt->r_menu->x, &rt->r_menu->h);
	rt->r_menu->x -= MENU_RX;
	rt->r_menu->y = 0;
	rt->r_menu->w = MENU_RX;
	rt->s_menu = esdl_create_surface(rt->r_menu->w, rt->r_menu->h);
	SDL_DestroyWindow(rt->win_temp);
}

void	draw_view(t_rt *rt)
{
	rt->win_temp = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, \
		SDL_WINDOWPOS_UNDEFINED, WIN_RX, WIN_RY, \
		SDL_WINDOW_HIDDEN | SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_GetWindowSize(rt->win_temp, &rt->r_view->w, &rt->r_view->h);
	rt->r_view->x = 0;
	rt->r_view->y = 0;
	rt->r_view->w -= MENU_RX;
	rt->s_view = esdl_create_surface(rt->r_view->w, rt->r_view->h);
}

void		display_rt(t_rt *rt)
{
	SDL_RenderClear(rt->esdl->eng.render);
	SDL_RenderCopy(rt->esdl->eng.render, rt->t_view, NULL, rt->r_view);
	SDL_RenderCopy(rt->esdl->eng.render, rt->t_menu, NULL, rt->r_menu);
	SDL_RenderPresent(rt->esdl->eng.render);
}

void		quit_rt(t_rt *rt)
{
	esdl_exit(rt->esdl);
}

int			main(int ac, char **av)
{
	(void)			av;
	(void)			ac;
	t_rt			*rt;
	int				i;
	int				j;

	rt = malloc(sizeof(t_rt));
	kernel_isopencl();
	init_rt(rt);
	draw_view(rt);
	draw_menu(rt);
	rt->scene = init_scene(rt);

	/*
	  Fill tab[x][y] with (0.0, 0.0, 0.0) vec3 ptr*
	*/

	rt->tab = (t_vec3***)malloc(rt->r_view->w * sizeof(t_vec3**));
	i = 0;
	while (i < rt->r_view->w)
	{
		rt->tab[i] = (t_vec3**)malloc(rt->r_view->h * sizeof(t_vec3*));
		j = 0;
		while (j < rt->r_view->h)
		{
			rt->tab[i][j] = v3_new_vec(0.0, 0.0, 0.0);
			++j;
		}
		++i;
	}

	/*
	  Prepare the rendering thread conditions
	*/

	rt->iter = NULL;
	i = 0;
	while (i < 5)
	{
		rt->iter = lst_new_iter(&(rt->iter), i);
		++i;
	}

	posix_memalign(&(rt->stack), PAGE_SIZE, STACK_SIZE);
	rt->t = NULL;
	i = 0;
	while (i < 5)
	{
		rt->t = lst_new_thread(&(rt->t));
		++i;
	}

	/*
	  Start first render while loading panel is still on screen
	*/

	render(rt);

	/*
	  Render to screen the view window
	*/

	SDL_SetWindowSize(rt->esdl->eng.win, WIN_RX, WIN_RY);
	SDL_SetWindowMinimumSize(rt->esdl->eng.win, WIN_RX - 400, WIN_RY - 300);
	SDL_SetWindowPosition(rt->esdl->eng.win, SDL_WINDOWPOS_CENTERED, \
		SDL_WINDOWPOS_CENTERED);
	SDL_SetWindowBordered(rt->esdl->eng.win, TRUE);

	/*
	  Start the rendering loop
	*/

	while (rt->esdl->run)
	{
		esdl_update_events(&(rt->esdl->eng.input), &(rt->esdl->run));

		display_rt(rt);
		render(rt);	

		esdl_fps_limit(rt->esdl);
		esdl_fps_counter(rt->esdl);
	}
	quit_rt(rt);
	return (0);
}
