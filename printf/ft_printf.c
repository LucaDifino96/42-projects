/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:12:26 by ldifino           #+#    #+#             */
/*   Updated: 2023/04/18 14:29:40 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_printf(const char *base, int cont)
{
	if (base == "c")
		cont += ft_putchar(base);
	if (base == "s")
		cont += ft_putstr(base);
	if (base == "d")
		cont += ft_putnbr(base);
	if (base == "i")
		cont += 
	if (base == "p")
		cont += 
	if (base == "u")
		cont += 
	if (base == "x")
		cont += 
	if (base == "X")
		cont +=
	if (base == "%")
		cont +=

