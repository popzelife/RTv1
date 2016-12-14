/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esdl_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:10:16 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/14 16:35:10 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			esdl_put_pixel(SDL_Surface *surf, \
	const int x, const int y, const int color)
{
	Uint32		*pixels;

	SDL_LockSurface(surf);
	if ((x >= 0 && y >= 0) && (x < surf->w && y < surf->h))
	{
		pixels = (Uint32 *)surf->pixels;
		pixels[(y * surf->w) + x] = color;
	}
	SDL_UnlockSurface(surf);
}

void			esdl_draw_filled_square(SDL_Surface *surf, \
	const SDL_Rect rect, const int color, void *param)
{
	register int		x;
	register int		y;

	(void)param;
	y = 0;
	while (y < rect.h)
	{
		x = 0;
		while (x < rect.w)
		{
			esdl_put_pixel(surf, x + rect.x, y + rect.y, color);
			++x;
		}
		++y;
	}
}
