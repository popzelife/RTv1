/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:00:00 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/15 21:02:49 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"



void			rt_events(t_rt *rt, int ret)
{
	if (ret == EV_EXIT)
		exit(0);
	else if (ret == SDL_MOUSEBUTTONUP)
	{
		SDL_GetMouseState(&rt->x, &rt->y);
		rt->render = 1;
		/*if (x < rt->r_view->w && y < rt->r_view->h)
		{
			set_viewparam(rt->panel->viewparam, rt, x, y);
			update_menu(rt);
			printf("%s\n", __FUNCTION__);
		}*/
	}
	/*else if (ret == EV_RESIZE)
	{
		rt->render = -2;
		draw_menu(rt);
		draw_view(rt);
	}*/
}