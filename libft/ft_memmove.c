/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:46:23 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/15 21:46:24 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == NULL && src == NULL)
		return (NULL);
	if (n == 0)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	else if (dest > src)
		while (n-- > 0)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	return (dest);
}
