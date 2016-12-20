/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:23:54 by qduperon          #+#    #+#             */
/*   Updated: 2016/12/20 16:27:37 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_obj	**init_obj(char **file, t_obj **obj)
{
	int	nb_obj;

	nb = ft_countobj(file);
	obj = (t_obj **)malloc(sizeof(t_obj *) * nb_obj);
	return (obj);
}
