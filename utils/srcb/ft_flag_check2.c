/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_check2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerrah <acerrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:20:09 by acerrah           #+#    #+#             */
/*   Updated: 2022/10/18 11:20:41 by acerrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	f_conv_neg(t_printfb *print, char *str, int *i)
{
	if (str[*i] == '#')
	{
		print->fconvert = TRUE;
		if (str[ft_strlen(str) - 1] != 'x' && str[ft_strlen(str) - 1] != 'X')
			print->fconvert = FALSE;
		(*i)++;
	}
	if (str[*i] == '-')
	{
		(*i)++;
		print->fnegative = TRUE;
	}
}

void	f_plus_zero(t_printfb *print, char *str, int *i)
{
	if (str[*i] == '+')
	{
		print->fplus = TRUE;
		(*i)++;
	}
	if (str[*i] == '0')
	{
		while (str[*i] <= '9' && str[*i] >= '0')
		{
			print->fzero = print->fzero * 10 + (str[*i] - '0');
			(*i)++;
		}
	}
}

void	f_dot_space(t_printfb *print, char *str, int *i)
{
	if (str[*i] == '.')
	{
		print->fdotdot = TRUE;
		(*i)++;
		while (str[*i] <= '9' && str[*i] >= '0')
		{
			print->fdot = print->fdot * 10 + (str[*i] - '0');
			(*i)++;
		}
	}
	if (str[*i] == ' ')
	{
		print->fspace = TRUE;
		(*i)++;
	}
}

void	f_num(t_printfb *print, char *str, int *i)
{
	if (str[*i] <= '9' && str[*i] >= '0')
	{
		while (str[*i] <= '9' && str[*i] >= '0')
		{
			print->fnum = print->fnum * 10 + (str[*i] - '0');
			(*i)++;
		}
	}
}
