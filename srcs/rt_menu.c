/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: popzelife <popzelife@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 21:17:20 by popzelife         #+#    #+#             */
/*   Updated: 2016/12/13 18:12:35 by popzelife        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"



void	draw_menu(t_rt *rt)
{
	SDL_Rect		rect;

	rt->panel = malloc(sizeof(t_panel));

	/*SDL_GetWindowSize(rt->win_temp, &rect.x, &rect.h);
	rect.x -= MENU_RX;
	rect.y = 0;
	rect.w = MENU_RX;
	rt->panel->lst_surf = lst_new_surface(&(rt->panel->lst_surf), surfparam( \
		rect, 0xff373737), rt->esdl->eng.render, esdl_clear_surface);*/

	/*esdl_draw_filled_square(rt->panel->s_3dview, 0xffffffff);
	rt->t_menu = SDL_CreateTextureFromSurface(rt->esdl->eng.render, rt->s_menu);
	rt->t_3dview = SDL_CreateTextureFromSurface(rt->esdl->eng.render, \
		rt->s_3dview);*/

	/*rt->panel->title1 = esdl_load_font(QUICKFONT, 20, 0xccccccff);

	rt->panel->objview = esdl_render_blendedtext("Object View", \
		rt->panel->title1, ft_tab2(WIN_RX - MENU_RX + 5, 5), \
		rt->esdl->eng.render);*/
	//rt->panel->objview = esdl_render_blendedtext("Object View", \
		rt->panel->title1, ft_tab2(WIN_RX - MENU_RX + 5, 5), \
		rt->esdl->eng.render);
}
