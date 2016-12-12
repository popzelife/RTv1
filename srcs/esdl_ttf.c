/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esdl_ttf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: popzelife <popzelife@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 21:31:36 by popzelife         #+#    #+#             */
/*   Updated: 2016/12/12 21:40:29 by popzelife        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			esdl_init_ttf(t_esdl *esdl)
{
	int		ret;

	ret = 1;
	if (TTF_Init() == -1)
	{
		ret = -1;
   		ft_dprintf(2, "TTF_Init() failed: %s\n", TTF_GetError());
	}
	esdl->ttf = 1;
	return (ret);
}
