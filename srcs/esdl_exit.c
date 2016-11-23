/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esdl_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:29:11 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/23 11:30:00 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				esdl_exit(t_esdl *esdl)
{
	SDL_DestroyRenderer(esdl->eng.render);
	SDL_DestroyWindow(esdl->eng.win);
	SDL_Quit();
}
