/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:32 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/03 19:02:53 by brouzaud         ###   ########.fr       */
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
		else
			insertion_sort(list, count);
	}
}

// int	getMin(t_list **list)
// {
// 	int		min;
// 	t_list	*tmp;

// 	tmp = (*list);
// 	min = tmp->data;
// 	while (tmp)
// 	{
// 		if (tmp->data < min)
// 			min = tmp->data;
// 		tmp = tmp->next;
// 	}
// 	return (min);
// }

void	sort3(t_list **a_list, t_count *count)
{
	t_list	*last;
	int		first;
	int		second;

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

void	insertion_sort(t_list **a_list, t_count *count)
{
	int		len;
	int		index;
	t_list	**b_list;

	b_list = malloc(sizeof(t_list *));
	len = ft_lstsize((*a_list));
	while (*a_list)
	{
		index = 0;
		while (index < len)
		{
			if ((*a_list)->data < (*a_list)->next->data)
				ra(a_list, count);
			else
				sa(a_list, count);
			index++;
		}
		pb(a_list, b_list, count);
	}
	while ((*b_list))
		pa(a_list, b_list, count);
}
