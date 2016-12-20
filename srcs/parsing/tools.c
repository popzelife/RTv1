/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:06:40 by qduperon          #+#    #+#             */
/*   Updated: 2016/12/20 16:19:19 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

int		ft_countobj(char **file)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (file[i])
	{
		 if (ft_strstr(OBJECTS, file[i]))
			 nb++;
		 i++;
	}
	return (nb)
}
