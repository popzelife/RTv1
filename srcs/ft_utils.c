/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:31:00 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/13 12:52:10 by qfremeau         ###   ########.fr       */
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

t_surfparam		surfparam(SDL_Rect rect, int color)
{
	t_surfparam		p;

	p.rect = rect;
	p.color = color;
	return (p);
}
