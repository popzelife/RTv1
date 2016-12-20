/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:00:00 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/16 19:45:36 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
  SDL_WINDOWEVENT_RESIZED needs more work, and other rendering functions 
  need to get dynamic values not just MACROS.
*/

void			rt_events(t_rt *rt, t_input *in)
{
	esdl_update_events(in, &rt->esdl->run);
	if (in->quit)
		pthread_join(rt->render_th, NULL);
	else if (in->window == SDL_WINDOWEVENT_RESIZED)
	{
		pthread_cancel(rt->render_th);
		pthread_join(rt->render_th, NULL);
		rt->render = 0;
		udpate_view(rt);
		free(rt->panel);
		free(rt->r_menu);
		reset_menu(rt);
		display_rt(rt);
		pthread_create(&rt->render_th, NULL, (void*)render_loop, (void*)rt);
		in->window = 0;
	}
	else if (in->button[SDL_BUTTON_LEFT])
	{
		if (in->m_x < rt->r_view->w && in->m_y < rt->r_view->h)
		{
			set_viewparam(rt->panel->viewparam, rt, in->m_x, in->m_y);
			update_menu(rt);
		}
	}
}
