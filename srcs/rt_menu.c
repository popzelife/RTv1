/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 21:17:20 by popzelife         #+#    #+#             */
/*   Updated: 2016/12/14 22:05:17 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_viewparam	*new_viewparam(t_scene *scene)
{
	t_viewparam		*p;
	t_obj			**obj;
	t_skybox		*skybox;
	t_cam			*cam;

	cam = init_camera(v3(-0.6, 0.0, -0.6), v3(0.0, 0.0, 0.0), \
		v3(0.0, 1.0, 0.0), 60.0, 1.0, 0.0, 0.5);
	obj = (t_obj**)malloc(2 * sizeof(t_obj*));
	obj[0] = copy_object(scene->obj[2]);
	obj[1] = new_object(v3_new_vec(0.0, 1.5, 0.0), 0.5, OBJ_SPHERE, \
		v3_new_vec(1.0, 1.0, 1.0), MAT_DIFF_LIGHT, NULL_PARAM);
	skybox = new_skybox(v3_new_vec(0.4, 0.4, 0.4), \
		v3_new_vec(0.9, 0.9, 0.9), SKYBX_GRADIENT);

	p = (t_viewparam*)malloc(sizeof(t_viewparam));
	p->scene = new_scene(cam, obj, skybox);
	p->scene->obj_nb = 2;
	p->obj = scene->obj[2];
	return (p);
}

void		draw_menu(t_rt *rt)
{
	SDL_Rect		r_win;
	SDL_Rect		rect;

	rt->panel = malloc(sizeof(t_panel));
	rt->panel->lst_surf = NULL;
	rt->panel->lst_string = NULL;
	rt->panel->viewparam = new_viewparam(rt->scene);
	SDL_GetWindowSize(rt->win_temp, &r_win.w, &r_win.h);
	r_win = esdl_rect(r_win.w - MENU_RX, 0, MENU_RX, r_win.h);

	/*
	  Background surfaces
	*/

	//background
	rt->panel->lst_surf = lst_new_surface(&(rt->panel->lst_surf), surfparam( \
		&r_win, 0xff373737, NULL), rt->esdl->eng.render, esdl_clear_surface);

	//title1
	rect = esdl_fuse_rect(r_win, esdl_rect(0, 0, MENU_RX, 30));
	rt->panel->lst_surf = lst_new_surface(&(rt->panel->lst_surf), surfparam( \
		&rect, 0xff888888, NULL), rt->esdl->eng.render, esdl_clear_surface);

	//3dview
	rect = esdl_fuse_rect(r_win, esdl_rect(50, 50, 200, 200));
	rt->panel->lst_surf = lst_new_surface(&(rt->panel->lst_surf), surfparam( \
		&rect, 0, (void*)rt->panel->viewparam), rt->esdl->eng.render, \
		rt_3dview_surface);

	//subtitle1
	rect = esdl_fuse_rect(r_win, esdl_rect(0, 280, MENU_RX, 30));
	rt->panel->lst_surf = lst_new_surface(&(rt->panel->lst_surf), surfparam( \
		&rect, 0xff222222, NULL), rt->esdl->eng.render, esdl_clear_surface);

	//title2
	rect = esdl_fuse_rect(r_win, esdl_rect(0, 480, MENU_RX, 30));
	rt->panel->lst_surf = lst_new_surface(&(rt->panel->lst_surf), surfparam( \
		&rect, 0xff888888, NULL), rt->esdl->eng.render, esdl_clear_surface);

	/*
	  Get param from object
	*/

	if (rt->panel->viewparam->obj->type_obj == OBJ_SPHERE)
	{
		t_sphere		*sphere;

		sphere = (t_sphere*)rt->panel->viewparam->obj->p_obj;
		sprintf(rt->panel->viewparam->str_obj, "Sphere Param:");
		sprintf(rt->panel->viewparam->str_pos, "Position: %5s[%.3g; %.3g; %.3g]", \
			"", sphere->center->x, sphere->center->y, sphere->center->z);
		sprintf(rt->panel->viewparam->str_param_o, "Radius: %10.3g", \
			sphere->radius);
	}
	else if (rt->panel->viewparam->obj->type_obj == OBJ_PLANE)
		sprintf(rt->panel->viewparam->str_obj, "Plane Param:");
	else if (rt->panel->viewparam->obj->type_obj == OBJ_CUBE)
		sprintf(rt->panel->viewparam->str_obj, "Cube Param:");

	if (rt->panel->viewparam->obj->p_mat->type_mat == MAT_METAL)
	{
		sprintf(rt->panel->viewparam->str_mat, "Material: %5sMetallic", "");
		sprintf(rt->panel->viewparam->str_param_m, "Fuzzy: %10.3g", \
			rt->panel->viewparam->obj->p_mat->t);
	}
	else if (rt->panel->viewparam->obj->p_mat->type_mat == MAT_LAMBERT)
	{
		sprintf(rt->panel->viewparam->str_mat, "Material: %5sLambertian", "");
		sprintf(rt->panel->viewparam->str_param_m, "");
	}
	else if (rt->panel->viewparam->obj->p_mat->type_mat == MAT_DIFF_LIGHT)
	{

		sprintf(rt->panel->viewparam->str_mat, "Material: %5sDiffuse Light", "");
		sprintf(rt->panel->viewparam->str_param_m, "");
	}

	sprintf(rt->panel->viewparam->str_color, "Color: %10srgb(%.3g, %.3g, %.3g)", \
		"", rt->panel->viewparam->obj->p_mat->albedo->x * 255.0, \
		rt->panel->viewparam->obj->p_mat->albedo->y * 255.0, \
		rt->panel->viewparam->obj->p_mat->albedo->z * 255.0);

	/*
	  Text & Title
	*/

	rt->panel->title1 = esdl_load_font(QUICKFONT, 22, 0x222222ff);
	rt->panel->sub_title1 = esdl_load_font(QUICKFONT, 18, 0xccccccff);
	rt->panel->word1 = esdl_load_font(QUICKFONT, 18, 0xccccccff);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		"Object Setting:", rt->panel->title1, ft_tab2(WIN_RX - MENU_RX + 5, 7)), \
		rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		"2D view", rt->panel->word1, ft_tab2(WIN_RX - MENU_RX + 220, 257)), \
		rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_obj, rt->panel->sub_title1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289)), rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_pos, rt->panel->word1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289 + 30)), rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_param_o, rt->panel->word1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289 + 60)), rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_mat, rt->panel->word1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289 + 90)), rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_color, rt->panel->word1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289 + 120)), rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		rt->panel->viewparam->str_param_m, rt->panel->word1, ft_tab2(WIN_RX - \
		MENU_RX + 5, 289 + 150)), rt->esdl->eng.render, esdl_render_blendedtext);

	rt->panel->lst_string = lst_new_string(&(rt->panel->lst_string), strparam( \
		"Primitives:", rt->panel->title1, ft_tab2(WIN_RX - MENU_RX + 5, 489)), \
		rt->esdl->eng.render, esdl_render_blendedtext);
}
