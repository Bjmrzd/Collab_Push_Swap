/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjmrzd <bjmrzd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:32 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/01 13:55:21 by bjmrzd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_list *list)
{
	while (list && list->next)
	{
		if (list->data > list->next->data)
		{
			return (1);
		}
		list = list->next;
	}
	return (0);
}

int	ft_lstsize(t_list *lst)
{
	int	index;

	index = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		index++;
	}
	return (index);
}
void	simple_sort(int argc, char *argv[], t_list **list, t_count *count)
{
	t_flag	flag;
	t_flag	isbench;
	int		size;

	isbench = arg_error(argc, argv);
	if (isbench == BENCH)
		flag = second_flag(argc, argv);
	else
		flag = arg_error(argc, argv);
	if (flag == SIMPLE)
	{
		size = ft_lstsize((*list));
		if (size == 3)
			sort3(list, count);
	}
}

void	sort3(t_list **a_list, t_count *count)
{
	t_list *last;
	int first;
	int second;

	first = (*a_list)->data;
	second = (*a_list)->next->data;
	last = ft_lstlast((*a_list));
	if (sorted((*a_list)) == 0)
		exit(2);
	if (first > second && second < last->data && last->data > first)
		sa(a_list, count);
	else if (first > second && second > last->data && last->data < first)
	{
		sa(a_list, count);
		rra(a_list, count);
	}
	else if (first > second && second < last->data && last->data < first)
		ra(a_list, count);
	else if (first < second && second > last->data && last->data > first)
	{
		sa(a_list, count);
		ra(a_list, count);
	}
	else
		rra(a_list, count);
}