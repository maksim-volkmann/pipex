/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:59:26 by mvolkman          #+#    #+#             */
/*   Updated: 2024/03/14 11:59:22 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;
	t_list	*last;

	current = lst;
	last = NULL;
	while (current)
	{
		last = current;
		current = current->next;
	}
	return (last);
}
