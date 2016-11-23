/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytrace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:36:47 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/16 16:23:48 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*void	ray_trace(t_img *img)
{
	t_obj		object;
	t_obj		curs_obj;
	t_point		p_hit;
	t_norm		n_hit;
	t_ray		prim_ray;
	t_ray		shadow_ray;
	float		min_distance;
	float		distance;
	int			x;
	int			y;
	int			i;
	BOOL		is_in_shadow;

	y = 0;
	while (y < img->height)
	{
		x = 0
		{
			while (x < img->width)
			{
				compute_ray(i, j, &prim_ray);
				min_distance = INFINITY;
				object = NULL;
				i = 0;
				while (i < object->size)
				{
					if (is_intersect(object[i], prim_raym &p_hit, &n_hit))
					{
						distance == get_distance(eye_position, p_hit);
						if (distance < min_distance)
						{
							object = object[i];
							min_distance = distance;
						}
					}
					++i;
				}
				if (object != NULL)
				{
					shadow_ray.direction = light_position - p_hit;
					is_in_shadow = FALSE;
					i = 0;
					while (i < object->size)
					{
						if (is_intersect(objet[i], shadow_ray))
						{
							is_in_shadow = TRUE;
							break;
						}
						++i;
					}
				}
				++x;
			}
			if (!is_in_shadow)
				pixels[x][y] = object->color * light.brightness;
			else
				pixels[x][y] = 0;
			++y;
		}
	}
}*/