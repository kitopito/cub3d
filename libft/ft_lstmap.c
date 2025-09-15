/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:45:58 by nateshim          #+#    #+#             */
/*   Updated: 2025/09/15 21:45:59 by nateshim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*tmp;
	void	*content;

	if (lst == NULL)
		return (NULL);
	ret = NULL;
	while (lst != NULL)
	{
		if (f != NULL)
			content = f(lst->content);
		else
			content = lst->content;
		tmp = ft_lstnew(content);
		if (tmp == NULL)
		{
			if (f != NULL || del != NULL)
				del(content);
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, tmp);
		lst = lst->next;
	}
	return (ret);
}
