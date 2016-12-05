/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytrace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:36:47 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/05 19:23:59 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
  Need sufficient malloc on each pthread #pthread_attr_getstack()
  Need also a pthread_mutex handling as rt->tab is shared between threads
*/

void		set_thread(t_thread *t, t_rt *rt, int i, int *s)
{
	t->arg.rt = rt;
	t->arg.scene = rt->scene;
	t->arg.j = i;
	t->arg.tab = rt->tab;
	t->arg.s = s;
	pthread_attr_init(&t->attr);
	pthread_attr_setstack(&t->attr, &(rt->stack), STACK_SIZE);
	if (pthread_create(&t->thread, &t->attr, (void*)thread_render, \
		(void*)&t->arg))
	{
		ft_dprintf(2, "RTv1 error - pthread_create failed");
		exit(-1);
	}
}

void		join_thread(t_thread *t)
{
	pthread_join(t->thread, NULL);
}

void		destroy_thread_attr(t_thread *t)
{
	pthread_attr_destroy(&(t->attr));
}

void		render(t_rt *rt)
{
	t_thread	*th_curs;
	t_iter		*it_curs;
	int			i;

	/*
	  Set all threads
	*/

	i = 0;
	th_curs = rt->t;
	it_curs = rt->iter;
	while (i < 5)
	{
		set_thread(th_curs, rt, i, &(it_curs->s));
		th_curs = th_curs->next;
		it_curs = it_curs->next;
		++i;
	}

	/*
	  Join all threads
	*/

	i = 0;
	th_curs = rt->t;
	while (i < 5)
	{
		join_thread(th_curs);
		th_curs = th_curs->next;
		++i;
	}

	/*
	  Destroy all threads
	*/

	i = 0;
	th_curs = rt->t;
	while (i < 5)
	{
		destroy_thread_attr(th_curs);
		th_curs = th_curs->next;
		++i;
	}

	ft_printf("Render pass # %3d/%3d\r", rt->iter->s - 1, ALIASING);

	/*
	  Creates the textures from the surfaces
	*/

	rt->t_view = SDL_CreateTextureFromSurface(rt->esdl->eng.render, rt->s_view);
	esdl_clear_surface(rt->s_menu, 0xff373737);
	rt->t_menu = SDL_CreateTextureFromSurface(rt->esdl->eng.render, rt->s_menu);
}
