/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerrah <acerrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:25:16 by acerrah           #+#    #+#             */
/*   Updated: 2022/10/18 11:25:17 by acerrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*iter;
	int		i;

	iter = lst;
	i = 0;
	while (iter != NULL)
	{
		i++;
		iter = iter->next;
	}
	return (i);
}
