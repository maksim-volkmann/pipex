/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:33:06 by mvolkman          #+#    #+#             */
/*   Updated: 2024/03/14 16:22:58 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putchar(char c)
{
	int	check;

	check = write(1, &c, 1);
	if (check == -1)
		return (-1);
	return (check);
}

int	ft_putstr(char *str)
{
	int	count;
	int	i;
	int	check;

	count = 0;
	i = 0;
	if (str == NULL )
		return (write(1, "(null)", sizeof(char) * 6));
	while (str[i])
	{
		check = ft_putchar(str[i]);
		if (check == -1)
			return (-1);
		count += check;
		i++;
	}
	return (count);
}

int	ft_puthex(unsigned long long n, int c)
{
	char const	*hex = "0123456789abcdef";
	char		hex_char;
	int			count;

	count = 0;
	if (n >= 16)
	{
		count = ft_puthex(n / 16, c);
		if (count == -1)
			return (-1);
	}
	if (c)
	{
		hex_char = ft_toupper(hex[n % 16]);
		if (ft_putchar(hex_char) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar(hex[n % 16]) == -1)
			return (-1);
	}
	return (count + 1);
}

int	ft_putptn(void *n)
{
	int	count;
	int	check;

	count = 0;
	check = ft_putstr("0x");
	if (check == -1)
		return (-1);
	count += check;
	check = ft_puthex((unsigned long long)n, 0);
	if (check == -1)
		return (-1);
	count += check;
	return (count);
}

int	ft_putint(long n)
{
	int	count;
	int	temp;

	count = 0;
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		n = -n;
		count = 1;
	}
	if (n >= 10)
	{
		temp = ft_putint(n / 10);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	if (ft_putchar(n % 10 + '0') == -1)
		return (-1);
	return (count + 1);
}
