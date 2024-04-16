/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:43:28 by mvolkman          #+#    #+#             */
/*   Updated: 2024/03/15 09:13:33 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_conversions(const char *format, va_list args)
{
	if (*format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*format == 'p')
		return (ft_putptn(va_arg(args, void *)));
	else if (*format == 'i' || *format == 'd')
		return (ft_putint(va_arg(args, int)));
	else if (*format == 'u')
		return (ft_putint(va_arg(args, unsigned int)));
	else if (*format == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (*format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (*format == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar(*format));
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	int		temp;
	va_list	args;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			temp = ft_conversions(&format[i + 1], args);
			i++;
		}
		else
			temp = ft_putchar(format[i]);
		if (temp == -1)
			return (-1);
		count += temp;
		i++;
	}
	va_end(args);
	return (count);
}
