/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjmrzd <bjmrzd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:53 by brouzaud          #+#    #+#             */
/*   Updated: 2025/12/29 21:01:50 by bjmrzd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **list, t_count *count)
{
	t_list	*end;
	t_list	*head;
	t_list	*tmp;

	if (!(*list) || !(*list)->next)
		return ;
	head = (*list);
	tmp = head;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	end = tmp->next;
	if (!end)
		return ;
	tmp->next = NULL;
	end->next = head;
	(*list) = end;
	count->rra_count++;
	return ;
}
