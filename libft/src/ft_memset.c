/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:35:12 by mvolkman          #+#    #+#             */
/*   Updated: 2024/03/14 11:59:04 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((char *)dest)[i] = c;
		i++;
	}
	return (dest);
}
