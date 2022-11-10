/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerrah <acerrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:22:39 by acerrah           #+#    #+#             */
/*   Updated: 2022/10/18 11:22:44 by acerrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_one(va_list pars, t_printf *prnt)
{
	if (prnt->flagstart == 'c')
	{
		prnt->cvalue = va_arg(pars, int);
		ft_putchar_fd(prnt->cvalue, 1);
		prnt->rtn = prnt->rtn + 1;
	}
	if (prnt->flagstart == 's')
	{
		prnt->string = va_arg(pars, char *);
		if (!prnt->string)
		{
			ft_putstr_fd("(null)", 1);
			prnt->rtn += 6;
			return ;
		}
		ft_putstr_fd(prnt->string, 1);
		prnt->rtn += ft_strlen(prnt->string);
	}
	else
	{
		check_two(pars, prnt);
	}
}

void	check_two(va_list pars, t_printf *prnt)
{
	if (prnt->flagstart == 'd' || prnt->flagstart == 'i')
	{
		prnt->dec = va_arg(pars, int);
		ft_putnbr_fd(prnt->dec, 1);
		prnt->string = ft_itoa(prnt->dec);
		prnt->rtn += ft_strlen(prnt->string);
		free(prnt->string);
	}
	if (prnt->flagstart == 'u')
	{
		prnt->unsval = va_arg(pars, unsigned int);
		unsigned_convert(prnt, prnt->unsval);
	}
	else
	{
		check_tree(pars, prnt);
	}
}

void	check_tree(va_list pars, t_printf *prnt)
{
	if (prnt->flagstart == 'x' || prnt->flagstart == 'X')
	{
		prnt->xval = va_arg(pars, unsigned int);
		decimal_to_hexa(prnt, prnt->xval);
	}
	if (prnt->flagstart == 'p')
	{
		prnt->pval = va_arg(pars, unsigned long);
		ft_putstr_fd("0x", 1);
		prnt->rtn = prnt->rtn + 2;
		decimal_to_hexap(prnt, prnt->pval);
	}
	if (prnt->flagstart == '%')
	{
		ft_putchar_fd('%', 1);
		prnt->rtn = prnt->rtn + 1;
	}
}
