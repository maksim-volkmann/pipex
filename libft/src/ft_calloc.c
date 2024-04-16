/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:14:38 by mvolkman          #+#    #+#             */
/*   Updated: 2024/03/14 11:57:13 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t count, size_t n)
{
	void	*memory;

	memory = (void *)malloc(count * n);
	if (!memory)
		return (NULL);
	ft_bzero(memory, count * n);
	return (memory);
}
