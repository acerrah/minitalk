/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerrah <acerrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:21:44 by acerrah           #+#    #+#             */
/*   Updated: 2022/10/18 11:21:45 by acerrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	t_printfb	specter;

	va_start(arg, str);
	specter.rtn = 0;
	ft_reset(&specter);
	ft_check_arg(str, arg, &specter);
	va_end(arg);
	return (specter.rtn);
}
