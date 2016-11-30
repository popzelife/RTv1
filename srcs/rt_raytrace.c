/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytrace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:36:47 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/29 20:19:17 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

#define max(a,b) (a>=b?a:b)
#define min(a,b) (a<=b?a:b)

/*
  Need sufficient malloc on each pthread #pthread_attr_getstack()
*/

void		render(t_rt *rt, t_scene *scene)
{
	/*pthread_t	t1;
	pthread_t	t2;
	pthread_t	t3;
	pthread_t	t4;
	pthread_t	t5;*/
	t_tharg		arg1;
	/*t_tharg		arg2;
	t_tharg		arg3;
	t_tharg		arg4;
	t_tharg		arg5;*/

	arg1.rt = rt;
	arg1.scene = scene;
	arg1.j = 0;
	thread_render(&arg1);
	//pthread_create(&t1, NULL, (void*)thread_render, (void*)&arg1);

	/*arg2.rt = rt;
	arg2.scene = scene;
	arg2.j = 1;
	pthread_create(&t2, NULL, (void*)thread_render, (void*)&arg2);

	arg3.rt = rt;
	arg3.scene = scene;
	arg3.j = 2;
	pthread_create(&t3, NULL, (void*)thread_render, (void*)&arg3);

	arg4.rt = rt;
	arg4.scene = scene;
	arg4.j = 3;
	pthread_create(&t4, NULL, (void*)thread_render, (void*)&arg4);
	arg5.rt = rt;
	arg5.scene = scene;
	arg5.j = 4;
	pthread_create(&t5, NULL, (void*)thread_render, (void*)&arg5);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);
	pthread_join(t5, NULL);*/

	rt->t_view = SDL_CreateTextureFromSurface(rt->esdl->eng.render, rt->s_view);
	SDL_FreeSurface(rt->s_view);
	esdl_clear_surface(rt->s_menu, 0xff373737);
	rt->t_menu = SDL_CreateTextureFromSurface(rt->esdl->eng.render, rt->s_menu);
	SDL_FreeSurface(rt->s_menu);
}
