/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:31:07 by qduperon          #+#    #+#             */
/*   Updated: 2017/01/03 17:36:29 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_cam	*new_camera(t_c c, t_cam *cam)
{
	cam = malloc(sizeof(t_cam));
	cam->low_left_corner = c.low_left_corner;
	cam->horizontal = c.hor;
	cam->vertical = c.vert;
	cam->u = c.u;
	cam->v = c.v;
	cam->w = c.w;
	cam->lens_radius = c.lens_radius;
	return (cam);
}

t_cam	*init_camera2(t_c c, t_cam *cam, t_rt *rt)
{
	c.lens_radius = c.ap / 2;
	c.half_height = tan((60.0 * M_PI / 180) / 2.0);
	c.half_width = ((float)rt->r_view->w /(float)rt->r_view->h) * half_height;
	c.origin = v3_copy_vec(c.look_from);
	c.v1 = v3_sub_vec(c.look_f, c.look_at);
	c.w = v3_unit_vec(*c.v1);
	v3_free(c.v1);
	c.v1 = v3_cross_vec(c.v_up, *c.w);
	c.u = v3_unit_vec(*c.v1);
	v3_free(c.v1);
	c.v = v3_cross_vec(*c.w, *c.u);
	c.v1 = v3_scale_vec(*c.u, c.half_width * c.focus);
	v2 = v3_sub_vec(*origin, *v1);
	v3_free(v1);
	c.v1 = v3_scale_vec(*c.v, c.half_height * c.focus);
	c.sum = v3_sub_vec(*c.v2, *c.v1);
	v3_free(c.v1);
	v3_free(c.v2);
	c.v1 = v3_scale_vec(*c.w, c.focus);
	c.low_left_corner = v3_sub_vec(*c.sum, *c.v1);
	v3_free(c.v1);
	v3_free(c.sum);
	c.hor = v3_scale_vec(*c.u, 2.0 * c.half_width * c.focus);
	c.vert = v3_scale_vec(*c.v, 2.0 * c.half_height * c.focus);
	return (new_camera(c, cam));
}

t_cam	*init_camera(char **file, int i, t_cam *cam, t_rt *rt)
{
	t_c c;
	t_vec3 *temp;

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
	temp = v3_sub_vec(c.look_f, c.look_at);
	c.focus = v3_lenght_float(*temp);
	v3_free(temp);
	c.v_up = v3(0.0, -1.0, 0.0);
	cam = init_camera2(c, cam, rt);
	return (cam);
}
