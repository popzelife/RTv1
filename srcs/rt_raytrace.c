/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytrace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:36:47 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/25 11:38:57 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	draw_menu(t_rt *rt)
{
	SDL_GetWindowSize(rt->esdl->eng.win, &rt->r_menu->x, &rt->r_menu->h);
	rt->r_menu->x -= MENU_RX;
	rt->r_menu->y = 0;
	rt->r_menu->w = MENU_RX;
	rt->s_menu = esdl_create_surface(rt->r_menu->w, rt->r_menu->h);
	esdl_clear_surface(rt->s_menu, 0xff373737);
	rt->t_menu = SDL_CreateTextureFromSurface(rt->esdl->eng.render, rt->s_menu);
	SDL_FreeSurface(rt->s_menu);
}

void	draw_view(t_rt *rt, t_scene *scene)
{
	(void)scene;

	SDL_GetWindowSize(rt->esdl->eng.win, &rt->r_view->w, &rt->r_view->h);
	rt->r_view->x = 0;
	rt->r_view->y = 0;
	rt->r_view->w -= MENU_RX;
	rt->s_view = esdl_create_surface(rt->r_view->w, rt->r_view->h);
	esdl_clear_surface(rt->s_view, 0xffc8c8c8);
	rt->t_view = SDL_CreateTextureFromSurface(rt->esdl->eng.render, rt->s_view);
	SDL_FreeSurface(rt->s_view);
}
