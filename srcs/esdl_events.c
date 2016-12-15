/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esdl_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:47:31 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/15 17:46:00 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int			esdl_get_input(SDL_Event *event, t_input *in)
{
	int				ret;

	ret = 0;
	if (event->type == SDL_KEYDOWN)
	{
		in->key[event->key.keysym.scancode] = 1;
		ret++;
	}
	else if (event->type == SDL_KEYUP)
	{
		in->key[event->key.keysym.scancode] = 0;
		ret++;
	}
	return (ret);
}

static int			esdl_get_mouse(SDL_Event *event, t_input *in)
{
	int				ret;

	ret = 0;
	if (event->type == SDL_MOUSEBUTTONDOWN)
	{
		in->button[event->button.button] = 1;
		ret = SDL_MOUSEBUTTONDOWN;
	}
	else if (event->type == SDL_MOUSEBUTTONUP)
	{
		in->button[event->button.button] = 0;
		ret = SDL_MOUSEBUTTONUP;
	}
	return (ret);
}

int					esdl_check_input(t_input *in, const int input)
{
	if (in->key[input])
		return (1);
	return (0);
}

int					esdl_update_events(t_input *in, int *run)
{
	SDL_Event		event;
	int				ret;	

	ret = 0;
	SDL_GetMouseState(&in->m_x, &in->m_y);
	SDL_GetRelativeMouseState(&in->m_r_x, &in->m_r_y);
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT || esdl_check_input(in, SDL_SCANCODE_ESCAPE))
		{
			*run = 0;
			return (EV_EXIT);
		}
		else if (event.type == SDL_WINDOWEVENT)
		{
			if (event.window.event == SDL_WINDOWEVENT_RESIZED)
				return (EV_RESIZE);
		}
		if ((ret += esdl_get_input(&event, in)) > 0)
			break ;
		if ((ret += esdl_get_mouse(&event, in)) > 0)
			break ;
	}
	return (ret);
}
