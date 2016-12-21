/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:06:40 by qduperon          #+#    #+#             */
/*   Updated: 2016/12/21 19:25:26 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

float	ft_data(char *line)
{
	return ((float)ft_atodouble(&line));
}

t_vec3	ft_vector(char *line)
{
	float	x;
	float	y;
	float	z;

	x = (float)ft_atodouble(&line);
	y = (float)ft_atodouble(&line);
	z = (float)ft_atodouble(&line);
	return (v3(x, y, z));
}

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
