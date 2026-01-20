/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:44:00 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/20 16:40:56 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max_bits(t_list **list)
{
	int	max_bits;
	int	size;

	size = ft_lstsize(*list);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	return (max_bits);
}

void	presort_index(t_list **a_list)
{
	t_list	*tmp;
	t_list	*temp;

	tmp = (*a_list);
	while (tmp)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
	tmp = (*a_list);
	while (tmp)
	{
		temp = (*a_list);
		while (temp)
		{
			if (temp->data < tmp->data)
				tmp->index++;
			temp = temp->next;
		}
		tmp = tmp->next;
	}
}

void	push_back(char *argv[], t_list **b_list, t_list **a_list,
		t_count *count)
{
	while (*b_list)
		pa(argv, a_list, b_list, count);
}

void	radix_logic(int count_bits, t_list **a_list, char *argv[],
		t_count *count)
{
	int		index;
	int		size;
	t_list	**b_list;

	index = 0;
	size = ft_lstsize((*a_list));
	b_list = malloc(sizeof(t_list *));
	*b_list = NULL;
	while (index < size)
	{
		if (((*a_list)->index >> count_bits & 1) == 0)
			pb(argv, a_list, b_list, count);
		else
			ra(argv, a_list, count);
		index++;
	}
	push_back(argv, b_list, a_list, count);
	free(b_list);
}

void	radix_sort(char *argv[], t_list **a_list, t_count *count)
{
	int	m_bits;
	int	count_bits;

	m_bits = max_bits(a_list);
	count_bits = 0;
	presort_index(a_list);
	while (count_bits < m_bits)
	{
		radix_logic(count_bits, a_list, argv, count);
		count_bits++;
	}
}
