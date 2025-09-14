/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:15:29 by ywada             #+#    #+#             */
/*   Updated: 2025/08/12 01:25:16 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hooks/hooks.h"
#include "dda.h"

#define screenWidth 640
#define screenHeight 480

/*
in directory: srcs/dda
cc -I../../minilibx-linux *.c ../hooks/*.c ../../minilibx-linux/libmlx.a -lXext
	-lX11 -lz -lm
*/