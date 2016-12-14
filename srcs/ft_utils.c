/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:31:00 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/14 16:34:23 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				*ft_tab2(const int x, const int y)
{
	int		*xy;

	xy = (int*)malloc(2 * sizeof(int));
	xy[0] = x;
	xy[1] = y;
	return (xy);
}

t_surfparam		surfparam(SDL_Rect *rect, int color, void *param)
{
	t_surfparam		p;

	p.rect = rect;
	p.color = color;
	p.param = param;
	return (p);
}

t_strparam		strparam(char* string, t_font font, int xy[2])
{
	t_strparam		p;

	p.string = string;
	p.font = font;
	p.xy[0] = xy[0];
	p.xy[1] = xy[1];
	return (p);
}
