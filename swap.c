/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjmrzd <bjmrzd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:40 by brouzaud          #+#    #+#             */
/*   Updated: 2025/12/29 21:02:05 by bjmrzd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **list, t_count *count)
{
	t_list	*head;
	t_list	*tmp;

	if (!(*list) || !(*list)->next)
		return ;
	head = (*list);
	tmp = (*list)->next;
	head->next = tmp->next;
	tmp->next = head;
	(*list) = tmp;
	count->sa_count++;
	return ;
}
