/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:12:12 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/16 17:15:53 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		kernel_isopencl(void)
{
	register cl_uint		i;
	register cl_device_id	*devices;
	register char			buf[128];
	cl_uint					num_devices;

	clGetDeviceIDs(NULL, CL_DEVICE_TYPE_ALL, 0, NULL, &num_devices);
	devices = malloc(sizeof(cl_device_id) * num_devices);
	clGetDeviceIDs(NULL, CL_DEVICE_TYPE_ALL, num_devices, devices, NULL);
	i = 0;
	while (i < num_devices)
	{
		clGetDeviceInfo(devices[i], CL_DEVICE_NAME, 128, buf, NULL);
		ft_printf("Device %s supports ", buf);
		clGetDeviceInfo(devices[i], CL_DEVICE_VERSION, 128, buf, NULL);
		ft_printf("%s\n", buf);
		++i;
	}
	free(devices);
}