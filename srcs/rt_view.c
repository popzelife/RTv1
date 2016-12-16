/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_view.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:03:14 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/16 19:34:16 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		draw_view(t_rt *rt)
{
	rt->r_view = malloc(sizeof (SDL_Rect));
	SDL_GetWindowSize(rt->win_temp, &rt->r_view->w, &rt->r_view->h);
	rt->r_view->x = 0;
	rt->r_view->y = 0;
	rt->r_view->w -= MENU_RX;
	rt->s_view = esdl_create_surface(rt->r_view->w, rt->r_view->h);
}

void		udpate_view(t_rt *rt)
{
	int			i;
	int			j;

	i = 0;
	while (i < rt->r_view->w)
	{
		j = 0;
		while (j < rt->r_view->h)
		{
			v3_set(rt->tab[i][j], 0.0, 0.0, 0.0);
			++j;
		}
		++i;
	}

	i = 0;
	while (i < rt->m_thread)
	{
		rt->iter->s = 1;
		++i;
	}

	printf("SDL_GetWindowSize %d %d\n", rt->r_view->w, rt->r_view->h);
	SDL_GetWindowSize(rt->esdl->eng.win, &rt->r_view->w, &rt->r_view->h);
	rt->r_view->x = 0;
	rt->r_view->y = 0;
	rt->r_view->w -= MENU_RX;
	printf("SDL_GetWindowSize %d %d\n", rt->r_view->w, rt->r_view->h);
	rt->s_view = esdl_scale_surface(rt->s_view, rt->r_view->w, rt->r_view->h);
	esdl_clear_surface(rt->s_view, NULL_RECT, 0xff000000, NULL);
	rt->t_view = SDL_CreateTextureFromSurface(rt->esdl->eng.render, rt->s_view);
}
