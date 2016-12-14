/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: popzelife <popzelife@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 21:17:20 by popzelife         #+#    #+#             */
/*   Updated: 2016/12/13 20:08:50 by popzelife        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"



void	draw_menu(t_rt *rt)
{
	SDL_Rect		r_win;
	SDL_Rect		rect;

	rt->panel = malloc(sizeof(t_panel));
	rt->panel->lst_surf = NULL;
	SDL_GetWindowSize(rt->win_temp, &r_win.x, &r_win.h);
	r_win = esdl_rect(r_win.x - MENU_RX, 0, r_win.h, WIN_RY);

	/*
	  Background surfaces
	*/

	rt->panel->lst_surf = lst_new_surface(&(rt->panel->lst_surf), surfparam( \
		&r_win, 0xff373737), rt->esdl->eng.render, esdl_clear_surface);

	rect = esdl_fuse_rect(r_win, esdl_rect(0, 0, MENU_RX, 35));
	rt->panel->lst_surf = lst_new_surface(&(rt->panel->lst_surf), surfparam( \
		&rect, 0xff222222), rt->esdl->eng.render, esdl_clear_surface);

	rect = esdl_fuse_rect(r_win, esdl_rect(50, 50, 200, 200));
	rt->panel->lst_surf = lst_new_surface(&(rt->panel->lst_surf), surfparam( \
		&rect, 0xffdddddd), rt->esdl->eng.render, esdl_clear_surface);

	rect = esdl_fuse_rect(r_win, esdl_rect(0, 300, MENU_RX, 35));
	rt->panel->lst_surf = lst_new_surface(&(rt->panel->lst_surf), surfparam( \
		&rect, 0xff222222), rt->esdl->eng.render, esdl_clear_surface);

	/*
	  Text & Title
	*/

	rt->panel->title1 = esdl_load_font(QUICKFONT, 22, 0xccccccff);

	rt->panel->objview = esdl_render_blendedtext("Object View", \
		rt->panel->title1, ft_tab2(WIN_RX - MENU_RX + 5, 5), \
		rt->esdl->eng.render);
	
	//rt->panel->objview = esdl_render_blendedtext("Object View", \
		rt->panel->title1, ft_tab2(WIN_RX - MENU_RX + 5, 5), \
		rt->esdl->eng.render);
}
