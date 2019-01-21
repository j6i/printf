/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:39:49 by jgabelho          #+#    #+#             */
/*   Updated: 2019/01/20 17:21:24 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "printf.h"

void	ft_printf(char *form, ...)
{
	char		*print;
	va_list		vars;

	print = form;
	va_start(vars, form);
	while (*print != '\0')
	{
		while (*print != '%' && *print != '\0')
		{
			ft_putchar(*print);
			print++;
		}
		print++;
		if (*print == '%')
		{
			ft_putchar('%');
			print++;
		}
		if (*print == 'c')
		{
			ft_putchar(va_arg(vars, int));
			print++;
		}
		if (*print == 's')
		{
			ft_putstr(va_arg(vars, char *));
			print++;
		}
		if (*print == 'd')
		{
			ft_putnbr(va_arg(vars, int));
			print++;
		}
	}
	va_end(vars);
}

int		main(void)
{
	char	s[6] = "Hello";
	int		i;
	char	c;

	i = 10;
	c = 'd';
	ft_printf("%s %d %%ute guys\0", s, i, c);
	return (0);
}
