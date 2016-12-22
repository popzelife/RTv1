/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:39:32 by qduperon          #+#    #+#             */
/*   Updated: 2016/12/22 18:16:45 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_scene		*init_scene(char *scene, t_rt *rt)
{
	char	**file;
	int		i;
	t_cam 	*cam;
	t_scene	*s;
	t_obj	**obj;

	file = NULL;
	obj = NULL;
	file = ft_file(scene, file);
	obj = init_obj(file, obj);
	while(!ft_strstr(file[i], "END"))
	{
		if (ft_strstr(file[i], "camera:"))
			cam = init_camera(file, i, cam, rt);

	}
	free_tab(file, i);
	free(file);
}
