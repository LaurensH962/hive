/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:45:47 by lhaas             #+#    #+#             */
/*   Updated: 2024/11/26 10:18:46 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int count)
{
	count += write(1, &c, 1);
	return (count);
}

int	ft_putnbr_base(unsigned long long n, int count, char *base,
		unsigned int base_n)
{
	if (n >= base_n)
	{
		count = ft_putnbr_base(n / base_n, count, base, base_n);
		count = ft_putnbr_base(n % base_n, count, base, base_n);
	}
	else
	{
		count = ft_putchar(base[n], count);
	}
	return (count);
}

int	ft_putnbr_hex(unsigned int n, int count, int uppercase)
{
	if (uppercase == 1)
	{
		count = ft_putnbr_base((unsigned long long)n, count, "0123456789ABCDEF",
				16);
	}
	else if (uppercase == 2)
		count = ft_putnbr_base((unsigned long long)n, count, "0123456789", 10);
	else
	{
		count = ft_putnbr_base((unsigned long long)n, count, "0123456789abcdef",
				16);
	}
	return (count);
}

int	ft_putptr(void *ptr, int count)
{
	uintptr_t	address;

	if (!ptr)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	address = (uintptr_t)ptr;
	count += write(1, "0x", 2);
	count = ft_putnbr_base((unsigned long long)address, count,
			"0123456789abcdef", 16);
	return (count);
}

int	ft_putnbr(int n, int count)
{
	if (n == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		count = ft_putnbr(n / 10, count);
		count = ft_putnbr(n % 10, count);
	}
	else
		count = ft_putchar(n + '0', count);
	return (count);
}
