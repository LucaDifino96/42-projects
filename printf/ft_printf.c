/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:12:26 by ldifino           #+#    #+#             */
/*   Updated: 2023/04/19 12:48:16 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_printf(const char *base, int i)
{
	int	cont;

	cont = 0;
	if (base[i] == 'c')
		cont += ft_putchar(int (base[i]));
	else if (base[i] == 's')
		cont += ft_putstr(int (base[i]));
	else if (base[i] == 'd')
		cont += ft_putnbr(int (base[i]);
	else if (base[i] == 'i')
		cont += ft_putnbr(base[i]);
	else if (base[i] == 'p')
		cont += ft_void_hexa(base[i]);
	else if (base[i] == 'u')
		cont += ft_uns_putnbr(base[i]);
	else if (base[i] == 'x')
		cont += ft_hexa(base[i]);
	else if (base == 'X')
		cont += ft_hexa(base[i]);
	else if (base == '%')
		cont += ft_putchar('%');
	return (cont);
}


