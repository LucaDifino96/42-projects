/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:12:26 by ldifino           #+#    #+#             */
/*   Updated: 2023/04/19 18:39:29 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checker(const char *s, int i, va_list args)
{
	int	j;

	j = 0;
	if (s[i] == 'c')
		j += ft_putchar((char)va_arg(args, int));
	else if (s[i] == 's')
		j += ft_putstr(va_arg(args, char *));
	else if (s[i] == 'd')
		j += ft_putnbr(va_arg(args, int));
	else if (s[i] == 'i')
		j += ft_putnbr(va_arg(args, int));
	else if (s[i] == 'p')
		j += ft_void_hexa(va_arg(args, unsigned long int), "0123456789abcdef");
	else if (s[i] == 'u')
		j += ft_uns_putnbr(va_arg(args, unsigned int));
	else if (s[i] == 'x')
		j += ft_hexa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (s[i] == 'X')
		j += ft_hexa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (s[i] == '%')
		j += ft_putchar('%');
	return (j);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		j;
	va_list	args;

	i = 0;
	j = 0;
	va_start(args, s);
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '%')
		{
			j += ft_check(s[i], i + 1, args);
			i++;
		}
		else
			j += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (j);
}
