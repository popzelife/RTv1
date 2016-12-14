/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_3dview.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:01:12 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/14 21:55:03 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		rt_3dview_surface(SDL_Surface *surf, const SDL_Rect rect, \
	const int color, void *param)
{
	register int	x;
	register int	y;
	register int	s;
	register float	u;
	register float	v;
	t_ray			*ray;
	t_vec3			*ret;
	t_vec3			temp;
	SDL_Color		pixel;
	t_viewparam		*viewparam;

	(void)color;
	viewparam = (t_viewparam*)param;
	y = 0;
	while (y < rect.h)
	{
		x = 0;
		temp = v3(0.0, 0.0, 0.0);
		while (x < rect.w)
		{
			s = 0;
			while (s < 15)
			{
				u = ((float)x + f_random()) / (float)rect.w;
				v = ((float)y + f_random()) / (float)rect.h;
				ray = camera_ray(viewparam->scene->cam, u, v);
				ret = rt_color(ray, viewparam->scene, 0, 2);
				free_ray(ray);
				temp = v3(temp.x + ret->x, temp.y + ret->y, temp.z + ret->z);
				v3_free(ret);
				++s;
			}
			temp = v3(temp.x / 15, temp.y / 15, temp.z / 15);
			pixel = vec3_to_sdlcolor(temp);
			esdl_put_pixel(surf, rect.w - (x + 1), rect.h - (y + 1), \
				esdl_color_to_int(pixel));
			++x;
		}
		++y;
	}
}
