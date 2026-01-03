/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:49 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/03 12:32:16 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **list, t_count *count)
{
	t_list	*head;
	t_list	*tmp;
	t_list	*end;

	if (!(*list) || !(*list)->next)
		return ;
	head = (*list);
	tmp = (*list)->next;
	(*list) = (head)->next;
	end = ft_lstlast(*list);
	end->next = head;
	(*list) = tmp;
	head->next = NULL;
	count->ra_count++;
	return ;
}
