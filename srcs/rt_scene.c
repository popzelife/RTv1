/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 22:26:38 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/03 17:44:55 by qfremeau         ###   ########.fr       */
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

t_scene		*init_scene(t_rt *rt)
{
	t_scene		*scene;
	t_obj		**obj;
	t_cam		*cam;
	t_light		**light;
	t_vec3		*cam_lookfrom;
	t_vec3		*cam_lookat;
	t_vec3		*cam_vup;
	int			obj_nb;
	int			light_nb;

	cam_lookfrom = v3_new_vec(0.0, 0.0, 0.3);
	cam_lookat = v3_new_vec(0.0, 0.0, -1.0);
	cam_vup = v3_new_vec(0.0, 1.0, 0.0);
	cam = init_camera(*cam_lookfrom, *cam_lookat, *cam_vup, 90.0, \
		(float)rt->r_view->w / (float)rt->r_view->h);
	v3_free(cam_vup);
	v3_free(cam_lookat);
	v3_free(cam_lookfrom);

	obj_nb = 6;
	obj = malloc(obj_nb * sizeof(t_obj*));
	obj[0] = new_object(v3_new_vec(0.0, 0.0, -1.0), 0.6, \
		OBJ_SPHERE, v3_new_vec(1.0, 0.1, 0.1), MAT_LAMBERT);
	obj[1] = new_object(v3_new_vec(0.0, -100.5, -1.0), 100.0, \
		OBJ_SPHERE, v3_new_vec(0.0, 0.8, 0.5), MAT_LAMBERT);
	obj[2] = new_object(v3_new_vec(1.0, 0.0, -1.0), 0.5, \
		OBJ_SPHERE, v3_new_vec(0.7, 0.7, 0.7), MAT_METAL);
	obj[3] = new_object(v3_new_vec(-1.0, 0.0, -1.0), 0.5, \
		OBJ_SPHERE, v3_new_vec(0.8, 0.8, 0.2), MAT_METAL);
	obj[4] = new_object(v3_new_vec(0.0, 0.0, 1.0), 0.5, \
		OBJ_SPHERE, v3_new_vec(0.1, 0.1, 0.8), MAT_LAMBERT);
	obj[5] = new_object(v3_new_vec(0.0, 0.0, -3.0), 2.0, \
		OBJ_SPHERE, v3_new_vec(0.1, 0.1, 0.1), MAT_LAMBERT);

	light_nb = 1;
	light = malloc(light_nb * sizeof(t_light*));
	scene = new_scene(cam, obj, light);
	scene->obj_nb = obj_nb;
	scene->light_nb = light_nb;
	return (scene);
}
