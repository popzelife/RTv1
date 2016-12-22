/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:31:07 by qduperon          #+#    #+#             */
/*   Updated: 2016/12/22 18:25:34 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

typedef struct 	s_c
{
	t_vec3		look_f;
	t_vec3		look_at;
	float		fov;
	float		ap;
}				t_c;

t_cam	*init_camera2(t_c c, t_cam *cam, t_rt *rt)
{
	t_vec3	*orig;
	t_vec3	*u;
	t_vec3	*v;
	t_vec3	*w;
	float	half_height;
	float	half_width;
	float	lens_radius;

	half_height = tan((c.fov * M_PI / 180) / 2.0);
	half_width = ((float)rt->r_view->w / (float)rt->r_view->h) * half_height;
	lens_radius = c.ap / 2;
	orig = v3_copy_vec(c.look_f);
	w = v3_unit_vec(v3_sub_vec(c.look_f, c.look_at));
	u = v3_unit_vec(v3_cross_vec(, w));
}

t_cam	*init_camera(char **file, int i, t_cam *cam, t_rt *rt)
{
	t_c c;

	while (!ft_strstr(file[i], "-------"))
	{
		if (ft_strstr(file[i]), "pos:")
			c.look_f = ft_vector(line[i + 1]);
		if (ft_strstr(file[i]), "lookat:")
			c.look_at = ft_vector(line[i + 1]);
		if (ft_strstr(file[i]), "fov:")
			c.fov = ft_data(line[i + 1]);
		if (ft_strstr(file[i]), "aperture:")
			c.ap = ft_data(line[i + 1]);
		i++;
	}
	cam = init_camera2(c, cam, rt);
	return (cam);
}
