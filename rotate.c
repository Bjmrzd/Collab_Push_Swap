/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjmrzd <bjmrzd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:49 by brouzaud          #+#    #+#             */
/*   Updated: 2025/12/29 21:01:29 by bjmrzd           ###   ########.fr       */
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
