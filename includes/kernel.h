/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:13:55 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/24 18:31:54 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _KERNEL_H
# define _KERNEL_H

# ifdef __APPLE__
# include <OpenCL/opencl.h>
# else
# include <CL/cl.h>
# endif

void		kernel_isopencl(void);

#endif
