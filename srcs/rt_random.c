/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:54:32 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/13 10:29:51 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float				f_random()
{
	return ((float)rand() / RAND_MAX);
}

t_vec3				*random_in_unit_sphere()
{
	t_vec3		p;

	p = v3(2.0 * f_random() - 1.0, 2.0 * f_random() - 1.0, \
			2.0 * f_random() - 1.0);
	while (v3_dot_float(p, p) >= 1.0)
	{
		p = v3(2.0 * f_random() - 1.0, 2.0 * f_random() - 1.0, \
			2.0 * f_random() - 1.0);
	}
	return (v3_copy_vec(p));
}

t_vec3				*random_in_unit_disk()
{
	t_vec3		p;

	p = v3(2.0 * f_random() - 1.0, 2.0 * f_random() - 1.0, 0);
	while (v3_dot_float(p, p) >= 1.0)
	{
		p = v3(2.0 * f_random() - 1.0, 2.0 * f_random() - 1.0, 0);
	}
	return (v3_copy_vec(p));
}
