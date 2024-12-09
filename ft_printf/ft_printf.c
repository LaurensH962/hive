/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:10:22 by lhaas             #+#    #+#             */
/*   Updated: 2024/11/29 09:35:11 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putstr(char *s, int count)
{
	size_t	i;
	int	ret;

	if (!s)
	{
		ret = write(1, "(null)", 6);
		if (ret == -1)
			return (-1);
		count += ret;
		return (count);
	}
	i = 0;
	while (s[i])
	{
		ret = write(1, &s[i], 1);
		if (ret == -1)
			return (-1);
		count += ret;
		i++;
	}
	return (count);
}

int	check_specifier(const char str_c, va_list args, int count)
{
	if (str_c == 'd' || str_c == 'i')
		count = ft_putnbr(va_arg(args, int), count);
	else if (str_c == 'x')
		count = ft_putnbr_hex(va_arg(args, int), count, 0);
	else if (str_c == 'X')
		count = ft_putnbr_hex(va_arg(args, int), count, 1);
	else if (str_c == 'u')
		count = ft_putnbr_hex(va_arg(args, int), count, 2);
	else if (str_c == 'p')
		count = ft_putptr(va_arg(args, char *), count);
	else if (str_c == 's')
		count = ft_putstr(va_arg(args, char *), count);
	else if (str_c == 'c')
		count = ft_putchar(va_arg(args, int), count);
	else if (str_c == '%')
	{
		if (write(1, "%", 1) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	is_specif(const char str_c)
{
	if (str_c == 'd' || str_c == 'i' || str_c == 'x' || str_c == 'X'
		|| str_c == 'u' || str_c == 'p' || str_c == 's' || str_c == 'c'
		|| str_c == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, str);
	i = 0;
	count = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && is_specif(str[i + 1]))
			count = check_specifier(str[++i], args, count);
		else if(str[i] == '%' && !str [i + 1])
			count = -1;
		else
			count = ft_putchar(str[i], count);
		if (count == -1)
			break ;
		i++;
	}
	va_end(args);
	return (count);
}

/* #include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int	main(void)
{
	int	count;
	int	realcount;
	int	x;
	int	*ptr;

	x = 42;
	printf("\t<------ CHARACTER ----->\n");
	count = ft_printf("Char: %c\n", 'A');
	realcount = printf("Char: %c\n", 'A');
	ft_printf("Returned count: %d\n", count);
	printf("Returned realcount: %d\n", realcount);
	ft_printf("Null character: %c\n", '\0');
	printf("Null character: %c\n", '\0');
	ft_printf("ASCII 0: %c, ASCII 127: %c\n", 0, 127);
	ft_printf("ASCII 0: %c, ASCII 127: %c\n", 0, 127);
	printf("\t<------ STRING ----->\n");
	count = ft_printf("Hello, World!\n");
	realcount = printf("Hello, World!\n");
	ft_printf("Returned count: %d\n", count);
	printf("Returned realcount: %d\n", realcount);
	count = 0;
	realcount = 0;
	count = ft_printf("Empty string: '%s'\n", "");
	realcount = ft_printf("Empty string: '%s'\n", "");
	ft_printf("Returned count: %d\n", count);
	printf("Returned realcount: %d\n", realcount);
	count = 0;
	realcount = 0;
	count = ft_printf("&&^^@@Long string: %c %s\n", 225,
			" This is a really long string to test if your ft_printf handles large inputs properly aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	realcount = printf("&&^^@@Long string: %c %s\n", 225,
			" This is a really long string to test if your ft_printf handles large inputs properly aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	ft_printf("Returned count: %d\n", count);
	printf("Returned realcount: %d\n", realcount);
	printf("\t<------ INTEGER ----->\n");
	count = ft_printf("Integer: %d\n", 42);
	realcount = printf("Integer: %d\n", 42);
	ft_printf("Returned count: %d\n", count);
	printf("Returned realcount: %d\n", realcount);
	ft_printf("Positive: %d, Negative: %d\n", 123, -123);
	printf("Positive: %d, Negative: %d\n", 123, -123);
	ft_printf("Zero: %d\n", 0);
	printf("Zero: %d\n", 0);
	ft_printf("INT_MAX: %d, INT_MIN: %d\n", INT_MAX, INT_MIN);
	printf("INT_MAX: %d, INT_MIN: %d\n", INT_MAX, INT_MIN);
	printf("\t<------ UNSIGNED INTEGER ----->\n");
	ft_printf("Unsigned: %u\n", 123);
	printf("Unsigned: %u\n", 123);
	ft_printf("Unsigned zero: %u\n", 0);
	printf("Unsigned zero: %u\n", 0);
	ft_printf("UINT_MAX: %u\n", UINT_MAX);
	printf("UINT_MAX: %u\n", UINT_MAX);
	printf("\t<------ HEXADECIMAL ----->\n");
	count = ft_printf("Hexadecimal: %x\n", 255);
	realcount = printf("Hexadecimal: %x\n", 255);
	ft_printf("Returned count: %d\n", count);
	printf("Returned realcount: %d\n", realcount);
	count = ft_printf("Hexadecimal: %X\n", 255);
	realcount = printf("Hexadecimal: %X\n", 255);
	ft_printf("Returned count: %d\n", count);
	printf("Returned realcount: %d\n", realcount);
	ft_printf("Hex zero: %x, %X\n", 0, 0);
	printf("Hex zero: %x, %X\n", 0, 0);
	ft_printf("Hex UINT_MAX: %x, %X\n", UINT_MAX, UINT_MAX);
	printf("Hex UINT_MAX: %x, %X\n", UINT_MAX, UINT_MAX);
	ft_printf("Large hex value: %x\n", 0xdeadbeef);
	printf("Large hex value: %x\n", 0xdeadbeef);
	printf("\t<------ PERCENT ----->\n");
	ft_printf("Percent: %%\n");
	printf("Percent: %%\n");
	count = ft_printf("Many percent signs: %% %% %%\n%");
	realcount = printf("Many percent signs: %% %% %%\n%");
	ft_printf("Returned count: %d\n", count);
	printf("Returned realcount: %d\n", realcount);
	printf("\t<------ COMPLEX CASES ----->\n");
	ft_printf("Char: %c, String: %s, Pointer: %p\n", 'A', "Test", &x);
	ft_printf("Int: %d, Unsigned: %u, Hex: %x, Hex Upper: %X, Percent: %%\n",
		42, 42, 42, 42);
	printf("Char: %c, String: %s, Pointer: %p\n", 'A', "Test", &x);
	printf("Int: %d, Unsigned: %u, Hex: %x, Hex Upper: %X, Percent: %%\n", 42,
		42, 42, 42);
	printf("\t<------ POINTER ----->\n");
	ptr = NULL;
	count = ft_printf("Pointer: %p\n", ptr);
	realcount = printf("Pointer: %p\n", ptr);
	ft_printf("Returned count: %d\n", count);
	printf("Returned realcount: %d\n", realcount);
	ft_printf("Pointer: %p\n", &x);
	printf("Pointer: %p\n", &x);
	ft_printf("Pointer at zero: %p\n", (void *)0);
	printf("Pointer at zero: %p\n", (void *)0);
	printf("%%");
	printf("moi\n\n\n");

int ret;
int ret_ft;
int original_stdout = dup(STDOUT_FILENO);
    fclose(stdout);
    ret = printf("test\n");
    ret_ft = ft_printf("test\n");
    stdout = (FILE *)fdopen(original_stdout, "w");
    printf ("%d\n%d", ret, ret_ft);

    return 0;
} */
