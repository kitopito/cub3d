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
