/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:15:22 by ywada             #+#    #+#             */
/*   Updated: 2025/08/11 19:15:51 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dda_test.h"
#include "dda.h"

void fill_img(t_img_data *img_data, int color) {
    for (int y = 0; y < windowHeight; y++) {
        for (int x = 0; x < windowWidth; x++) {
            my_mlx_pixel_put(img_data, x, y, color);
        }
    }
}

int dda(t_dda *dda_data, t_img_data *img_data) {
    fill_img(img_data, 0x000000);
    int i = 0;
    while(i < windowWidth) {
        double ray_length;
        t_vector ray_dir;
        double camera_x = 2 * i / (double)windowWidth - 1;
        ray_dir.x = dda_data->dirX + camera_x * dda_data->planeX;
        ray_dir.y = dda_data->dirY + camera_x * dda_data->planeY;
        
        int mapX = (int)dda_data->x;
        int mapY = (int)dda_data->y;
        
        if(ray_dir.x != 0)
            dda_data->delta_x = fabs(1 / ray_dir.x);
        else 
            dda_data->delta_x = 1e30;
        if (ray_dir.y != 0)
            dda_data->delta_y = fabs(1 / ray_dir.y);
        else 
            dda_data->delta_y = 1e30;
        
        if (ray_dir.x < 0) {
            dda_data->step_x = -1;
            dda_data->side_dist_x = (dda_data->x - mapX) * dda_data->delta_x;
        } else {
            dda_data->step_x = 1;
            dda_data->side_dist_x = (mapX + 1.0 - dda_data->x) * dda_data->delta_x;
        }
        
        if (ray_dir.y < 0) {
            dda_data->step_y = -1;
            dda_data->side_dist_y = (dda_data->y - mapY) * dda_data->delta_y;
        } else {
            dda_data->step_y = 1;
            dda_data->side_dist_y = (mapY + 1.0 - dda_data->y) * dda_data->delta_y;
        }
        // printf("Ray direction: (%lf, %lf)\n", ray_dir.x, ray_dir.y);
        // printf("Delta distances: X = %lf, Y = %lf\n", dda_data->delta_x, dda_data->delta_y);
        // printf("Initial side distances: X = %lf, Y = %lf\n", dda_data->side_dist_x, dda_data->side_dist_y);
        
        int side = -1;
        while(1) {
            //printf("Current map position: (%d, %d)\n", mapX, mapY);
            //printf("Side distances: X = %f, Y = %f\n", dda_data->side_dist_x, dda_data->side_dist_y);
            if (dda_data->side_dist_x < dda_data->side_dist_y) {
                dda_data->side_dist_x += dda_data->delta_x;
                mapX += dda_data->step_x;
                side = 0;
            }
            else {
                dda_data->side_dist_y += dda_data->delta_y;
                mapY += dda_data->step_y;
                side = 1;
            }
            //printf("Updated map position: (%d, %d)\n", mapX, mapY);
            if (dda_data->map[mapY][mapX] > 0) {
                break;
            }
        }
        // printf("Map hit at (%d, %d) with side %d\n", mapX, mapY, side);
        int h = windowHeight;
        int line_height;
        if (side == 0) {
            line_height = (int)(h / (dda_data->side_dist_x - dda_data->delta_x));
        } else {
            line_height = (int)(h / (dda_data->side_dist_y - dda_data->delta_y));
        }
        
        int draw_start = h / 2 - line_height / 2;
        int k = draw_start;
        while (k < draw_start + line_height) {
            if (k >= 0 && k < windowHeight) {
                int color = (side == 0) ? 0xFF0000 : 0x00FF00;
                my_mlx_pixel_put(img_data, i, k, color);
                //printf("Pixel at (%d, %d) with color %06X\n", i, k, color);
            }
            k++;
        }
        i++;
    }
}
