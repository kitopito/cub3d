/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:15:12 by ywada             #+#    #+#             */
/*   Updated: 2025/08/11 19:15:51 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DDA_H
# define DDA_H
#include <stdlib.h>
#include <math.h>

typedef struct s_vector {
    double x;
    double y;
} t_vector;

int dda(t_dda *dda_data, t_img_data *img_data);

#endif