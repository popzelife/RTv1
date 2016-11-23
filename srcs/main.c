/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 21:40:50 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/23 19:18:51 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	init_cam(t_rt *rt)
{
	(void)rt;
}

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
	init_cam(rt);
	rt->r_view = malloc(sizeof (SDL_Rect));
	rt->r_menu = malloc(sizeof (SDL_Rect));
}

void		display_rt(t_rt *rt)
{
	SDL_GetWindowSize(rt->esdl->eng.win, &rt->r_view->w, &rt->r_view->h);
	rt->r_view->x = 0;
	rt->r_view->y = 0;
	rt->r_view->w -= MENU_RX;
	rt->s_view = esdl_create_surface(rt->r_view->w, rt->r_view->h);
	esdl_clear_surface(rt->s_view, 0xffc8c8c8);

	SDL_GetWindowSize(rt->esdl->eng.win, &rt->r_menu->x, &rt->r_menu->h);
	rt->r_menu->x -= MENU_RX;
	rt->r_menu->y = 0;
	rt->r_menu->w = MENU_RX;
	rt->s_menu = esdl_create_surface(rt->r_menu->w, rt->r_menu->h);
	esdl_clear_surface(rt->s_menu, 0xff373737);


	rt->t_view = SDL_CreateTextureFromSurface(rt->esdl->eng.render, rt->s_view);
	rt->t_menu = SDL_CreateTextureFromSurface(rt->esdl->eng.render, rt->s_menu);
	SDL_RenderClear(rt->esdl->eng.render);

	SDL_RenderCopy(rt->esdl->eng.render, rt->t_view, NULL, rt->r_view);
	SDL_RenderCopy(rt->esdl->eng.render, rt->t_menu, NULL, rt->r_menu);

	SDL_RenderPresent(rt->esdl->eng.render);
	SDL_DestroyTexture(rt->t_view);
	SDL_DestroyTexture(rt->t_menu);
	SDL_FreeSurface(rt->s_view);
	SDL_FreeSurface(rt->s_menu);
}

void		quit_rt(t_rt *rt)
{
	esdl_exit(rt->esdl);
}

int			main(int ac, char **av)
{
	(void)			av;
	(void)			ac;
	t_rt			rt;

	kernel_isopencl();
	init_rt(&rt);
	SDL_Delay(2000);
	SDL_SetWindowSize(rt.esdl->eng.win, WIN_RX, WIN_RY);
	SDL_SetWindowMinimumSize(rt.esdl->eng.win, WIN_RX - 400, WIN_RY - 300);
	SDL_SetWindowPosition(rt.esdl->eng.win, SDL_WINDOWPOS_CENTERED, \
		SDL_WINDOWPOS_CENTERED);
	SDL_SetWindowBordered(rt.esdl->eng.win, TRUE);
	while (rt.esdl->run)
	{
		esdl_update_events(&rt.esdl->eng.input, &rt.esdl->run);
		display_rt(&rt);
		esdl_fps_limit(rt.esdl);
		esdl_fps_counter(rt.esdl);
	}
	quit_rt(&rt);
	return (0);
}
