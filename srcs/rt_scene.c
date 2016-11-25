/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 22:26:38 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/25 02:50:40 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_scene		*new_scene(t_cam *cam, t_obj **obj, t_light **light)
{
	t_scene		*s;

	s = malloc(sizeof(t_scene));
	s->cam = cam;
	s->obj = obj;
	s->light = light;
	return (s);
}

t_scene		*init_scene(void)
{
	t_scene		*scene;
	t_obj		**obj;
	t_cam		*cam;
	t_light		**light;
	t_vec3		*cam_pos;
	t_vec3		*cam_lookat;
	t_vec3		*plane_pos;
	t_vec3		*sphere_pos;
	t_vec3		*sphere2_pos;
	int			obj_nb;
	int			light_nb;

	cam_pos = v3_new_vec(0, 0, -5);
	cam_lookat = v3_new_vec(0, 0, 0);
	cam = init_camera(cam_pos, *cam_lookat);
	v3_free(cam_lookat);
	obj_nb = 3;
	obj = malloc(obj_nb * sizeof(t_obj*));
	plane_pos = v3_new_vec(0, 0, 0);
	obj[0] = create_object(plane_pos, 1, 0xffc8c8c8, OBJ_PLANE);
	sphere_pos = v3_new_vec(0, 0, 0);
	obj[1] = create_object(sphere_pos, 1, 0xff999900, OBJ_SPHERE);
	sphere2_pos = v3_new_vec(0.5, 0.25, 0);
	obj[2] = create_object(sphere2_pos, 0.5, 0xff009999, OBJ_SPHERE);
	light_nb = 1;
	light = malloc(light_nb * sizeof(t_light*));
	scene = new_scene(cam, obj, light);
	scene->obj_nb = obj_nb;
	scene->light_nb = light_nb;
	return (scene);
}
