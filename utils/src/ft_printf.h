/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerrah <acerrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:22:35 by acerrah           #+#    #+#             */
/*   Updated: 2022/10/18 11:22:36 by acerrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

# include "../libft/libft.h"

typedef struct t_listt
{
	char			flagstart;
	long			dec;
	int				cvalue;
	char			*string;
	unsigned int	unsval;
	unsigned int	xval;
	unsigned long	pval;
	int				rtn;

}					t_printf;

void	check_arg(const char *str, va_list pars, t_printf *prnt);
void	check_one(va_list pars, t_printf *prnt);
void	check_two(va_list pars, t_printf *prnt);
void	check_tree(va_list pars, t_printf *prnt);
void	decimal_to_hexa(t_printf *prnt, unsigned int nb);
void	decimal_to_hexap(t_printf *prnt, unsigned long nb);
void	unsigned_convert(t_printf *print, unsigned int nb);
void	reset_struck(t_printf *p);
int		ft_printf(const char *str, ...);

#endif