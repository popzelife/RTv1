/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:26:38 by qfremeau          #+#    #+#             */
/*   Updated: 2016/12/16 19:47:24 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GLOBAL_H
# define _GLOBAL_H

# define UCHAR			unsigned char
# define UINT			unsigned int
# define BOOL			int
# define TRUE			1
# define FALSE			0

# ifdef __linux__
# define PAGE_SIZE		4096
# endif
# define STACK_SIZE		(1 * PAGE_SIZE)

# define ALIASING		10
# define NO_ALIASING	1
# define MAX_DEPTH		25

# define API_NAME		"RTv1"
# define MAX_FPS		60
# define WIN_RX			1400
# define WIN_RY			900
# define MENU_RX		300
# define LOAD_NAME		"image/Loader.bmp"
# define LOAD_RX		900
# define LOAD_RY		563
# define QUICKFONT		"font/Quicksand_Book.otf"
# define IMG_ADDSPHERE	"image/AddSphere.bmp"
# define IMG_ADDPLANE	"image/AddPlane.bmp"
# define IMG_ADDCUBE	"image/AddCube.bmp"

# define HELP			-2
# define ERROR			-1

# define EV_EXIT		-1
# define EV_RESIZE		-2

# define OBJ_PLANE		0x1
# define OBJ_SPHERE		0x2
# define OBJ_CUBE		0x4
# define OBJ_PYRAMID	0x8
# define OBJ_CYLINDER	0x10
# define OBJ_SKYBOX		0x20

# define SKYBX_NONE		0x0
# define SKYBX_GRADIENT	0x1

# define NULL_PARAM		0.0
# define NULL_RECT		(SDL_Rect){0,0,0,0}

# define MAT_LAMBERT	0x1
# define MAT_METAL		0x2
# define MAT_DIELECT	0x4
# define MAT_DIFF_LIGHT	0x8

#endif
