/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:31:07 by qduperon          #+#    #+#             */
/*   Updated: 2016/12/21 19:52:59 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_cam	*init_camera(char **file, int i, t_cam *cam)
{
	t_vec3	look_from;
	t_vec3	look_at;
	float	fov;
	float	aperture;

	while (!ft_strstr(file[i], "-------"))
	{
		if (ft_strstr(file[i]), "pos:")
			look_from = ft_vector(line[i + 1]);
		if (ft_strstr(file[i]), "lookat:")
			look_at = ft_vector(line[i + 1]);
		if (ft_strstr(file[i]), "fov:")
			fov = ft_data(line[i + 1]);
		if (ft_strstr(file[i]), "aperture:")
			aperture = ft_data(line[i + 1]);
		i++;
	}
	return (cam);
}
