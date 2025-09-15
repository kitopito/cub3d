/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_state.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywada <ywada@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:15:00 by ywada             #+#    #+#             */
/*   Updated: 2025/08/11 20:33:55 by ywada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_STATE_H
# define KEY_STATE_H

# include <stdbool.h>

typedef struct s_key_state
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
}			t_key_state;

#endif