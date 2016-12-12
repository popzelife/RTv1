/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: popzelife <popzelife@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 21:17:20 by popzelife         #+#    #+#             */
/*   Updated: 2016/12/12 23:15:07 by popzelife        ###   ########.fr       */
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

	TTF_Font *quicksand = TTF_OpenFont(QUICKFONT, 24);
	if (quicksand == NULL)
	{
		ft_dprintf(2, "Draw_menu() failed: quicksand font not found\n");
		esdl_exit(rt->esdl);
		exit(0);
	}
	SDL_Color white = {230, 230, 230, 0}; 

	SDL_Surface *s_objview = TTF_RenderText_Solid(quicksand, \
	"Object View", white);
	rt->panel->t_objview = SDL_CreateTextureFromSurface(rt->esdl->eng.render, \
		s_objview);
	rt->panel->r_objview = malloc(sizeof(SDL_Rect));
	rt->panel->r_objview->x = WIN_RX - MENU_RX;
	rt->panel->r_objview->y = 0;
	SDL_QueryTexture(rt->panel->t_objview, NULL, NULL, \
		&(rt->panel->r_objview->w), &(rt->panel->r_objview->h));

	esdl_clear_surface(rt->s_menu, 0xff373737);
	rt->t_menu = SDL_CreateTextureFromSurface(rt->esdl->eng.render, rt->s_menu);
}
