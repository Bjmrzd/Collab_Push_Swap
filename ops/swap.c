/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjmrzd <bjmrzd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:40 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/11 04:20:21 by bjmrzd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(char *argv[], t_list **list, t_count *count)
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
	if (arg_error(argv) == BENCH)
		return ;
	else
		write(1, "sa\n", 3);
	return ;
}

void	sb(char *argv[], t_list **list, t_count *count)
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
	count->sb_count++;
	if (arg_error(argv) == BENCH)
		return ;
	else
		write(1, "sb\n", 3);
	return ;
}
