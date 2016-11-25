/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 21:40:50 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/25 11:39:46 by qfremeau         ###   ########.fr       */
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
	t_rt			rt;
	t_scene			*scene;

	//kernel_isopencl();
	init_rt(&rt);
	scene = init_scene();
	SDL_Delay(2000);
	SDL_SetWindowSize(rt.esdl->eng.win, WIN_RX, WIN_RY);
	SDL_SetWindowMinimumSize(rt.esdl->eng.win, WIN_RX - 400, WIN_RY - 300);
	SDL_SetWindowPosition(rt.esdl->eng.win, SDL_WINDOWPOS_CENTERED, \
		SDL_WINDOWPOS_CENTERED);
	SDL_SetWindowBordered(rt.esdl->eng.win, TRUE);
	draw_view(&rt, scene);
	draw_menu(&rt);
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
