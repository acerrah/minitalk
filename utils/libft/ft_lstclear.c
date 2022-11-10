/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerrah <acerrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:24:48 by acerrah           #+#    #+#             */
/*   Updated: 2022/10/18 11:24:50 by acerrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cnext;

	if (!lst || !del || !*lst)
		return ;
	cnext = (*lst);
	while (cnext != (NULL))
	{
		cnext = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		(*lst) = cnext;
	}
}
