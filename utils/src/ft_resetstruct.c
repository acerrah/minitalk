/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resetstruct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerrah <acerrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:22:47 by acerrah           #+#    #+#             */
/*   Updated: 2022/10/18 11:22:50 by acerrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_struck(t_printf *p)
{
	p->flagstart = 0;
	p->dec = 0;
	p->cvalue = 0;
	p->string = 0;
	p->unsval = 0;
	p->xval = 0;
	p->pval = 0;
}
