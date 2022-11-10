/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerrah <acerrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:25:06 by acerrah           #+#    #+#             */
/*   Updated: 2022/10/18 11:25:08 by acerrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nback;
	void	*data;

	nback = NULL;
	if (!lst || !f | !del)
		return (nback);
	while (lst != NULL)
	{
		data = (*f)(lst->content);
		if (!data)
		{
			del(data);
			ft_lstdelone(nback, del);
			return (NULL);
		}
		ft_lstadd_back(&nback, ft_lstnew(data));
		lst = lst->next;
	}
	return (nback);
}
