/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 21:17:20 by popzelife         #+#    #+#             */
/*   Updated: 2016/12/13 12:59:27 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"



void	draw_menu(t_rt *rt)
{
	SDL_GetWindowSize(rt->win_temp, &rt->r_menu->x, &rt->r_menu->h);
	rt->r_menu->x -= MENU_RX;
	rt->r_menu->y = 0;
	rt->r_menu->w = MENU_RX;
	rt->s_menu = esdl_create_surface(rt->r_menu->w, rt->r_menu->h);

	rt->panel = malloc(sizeof(t_panel));

	rt->lst_surf = lst_new_surface(rt->lst_surf, surfparam(NULL_RECT, \
		0xff373737), rt->esdl->eng.render, esdl_clear_surface);
	esdl_clear_surface(rt->s_menu, NULL_RECT, 0xff373737);
	esdl_draw_filled_square(rt->panel->s_3dview, 0xffffffff);
	rt->t_menu = SDL_CreateTextureFromSurface(rt->esdl->eng.render, rt->s_menu);
	rt->t_3dview = SDL_CreateTextureFromSurface(rt->esdl->eng.render, \
		rt->s_3dview);
	SDL_FreeSurface(rt->s_menu);
	SDL_FreeSurface(rt->s_3dview);

	rt->panel->title1 = esdl_load_font(QUICKFONT, 20, 0xccccccff);

	rt->panel->objview = esdl_render_blendedtext("Object View", \
		rt->panel->title1, ft_tab2(WIN_RX - MENU_RX + 5, 5), \
		rt->esdl->eng.render);
	//rt->panel->objview = esdl_render_blendedtext("Object View", \
		rt->panel->title1, ft_tab2(WIN_RX - MENU_RX + 5, 5), \
		rt->esdl->eng.render);
}
