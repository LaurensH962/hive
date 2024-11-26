/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:46:07 by lhaas             #+#    #+#             */
/*   Updated: 2024/11/26 10:14:24 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	ft_putchar(char c, int count);
int	ft_putnbr_base(unsigned long long n, int count, char *base, unsigned int base_n);
int	ft_putnbr_hex(unsigned int n, int count, int uppercase);
int	ft_putptr(void *ptr, int count);
int	ft_putnbr(int n, int count);
int	ft_putstr(char *s, int count);
int	check_specifier(const char str_c, va_list args, int count);
int	ft_printf(const char *str, ...);

#endif
