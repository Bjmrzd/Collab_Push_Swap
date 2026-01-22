/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:44:33 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/22 22:21:03 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	square_root(int size)
{
	int	val;

	val = 0;
	while (val * val <= size)
		val++;
	return (val);
}

// int	max_index(t_list **list)
// {
// 	int		max;
// 	int		pos;
// 	t_list	*tmp;

// 	tmp = (*list);
// 	max = tmp->data;
// 	pos = 0;
// 	while (tmp)
// 	{
// 		if (tmp->data > max)
// 		{
// 			max = tmp->data;
// 			pos = tmp->index;
// 		}
// 		tmp = tmp->next;
// 	}
// 	return (pos);
// }

// void	medium_push_back(char *argv[], t_list **a_list, t_list **b_list,
// 		t_count *count)
// {
// 	int	index_max;
// 	int	size;

// 	presort_index(b_list);
// 	while (*b_list)
// 	{
// 		size = ft_lstsize((*b_list));
// 		index_max = max_index(b_list);
// 		if ((*b_list)->index == index_max)
// 		{
// 			pa(argv, a_list, b_list, count);
// 		}
// 		else if (index_max <= size / 2)
// 			rb(argv, b_list, count);
// 		else
// 			rrb(argv, b_list, count);
// 	}
// 	free(b_list);
// }

// void	bucket_sort(char *argv[], t_list **a_list, t_count *count)
// // doit reduire ops
// {
// 	t_list **b_list;
// 	int bucket_size;
// 	int size;
// 	int nb_values;
// 	int bucket_limit;

// 	b_list = malloc(sizeof(t_list *));
// 	*b_list = NULL;
// 	size = ft_lstsize((*a_list));
// 	nb_values = 0;
// 	bucket_size = square_root(size);
// 	presort_index(a_list);
// 	bucket_limit = bucket_size;
// 	while (nb_values < size)
// 	{
// 		if ((*a_list)->index < bucket_limit)
// 		{
// 			pb(argv, a_list, b_list, count);
// 			nb_values++;
// 		}
// 		else
// 			ra(argv, a_list, count);

// 		if (nb_values == bucket_limit)
// 			bucket_limit += bucket_size;
// 	}
// 	medium_push_back(argv, a_list, b_list, count);
// }

t_list	**sort_loop(char *argv[], t_list **a_list, t_count *count,
		int bucket_size)
{
	int		index;
	int		len;
	int		val;
	t_list	**b_list;

	b_list = malloc(sizeof(t_list *));
	*b_list = NULL;
	len = ft_lstsize((*a_list));
	while (len > bucket_size)
	{
		index = min_index(a_list);
		if (index <= len / 2)
		{
			while (index-- > 0)
				ra(argv, a_list, count);
		}
		else
		{
			val = len - index;
			while (val-- > 0)
				rra(argv, a_list, count);
		}
		pb(argv, a_list, b_list, count);
		len--;
	}
	return (b_list);
}

void	select_sort(char *argv[], t_list **a_list, t_count *count,
		int bucket_size)
{
	t_list	**b_list;

	if (sorted(a_list) == 0)
		return ;
	b_list = sort_loop(argv, a_list, count, bucket_size);
	while (*b_list)
		pa(argv, a_list, b_list, count);
	free(b_list);
}

void	bucket_sort(char *argv[], t_list **a_list, t_count *count)
{
	// t_list **b_list;
	int size;
	int bucket_size;
	int index;
	// b_list = malloc(sizeof(t_list *));
	// *b_list = NULL;
	size = ft_lstsize(*a_list);
	bucket_size = square_root(size);
	index = 0;
	presort_index(a_list);

	while (index * bucket_size <= size)
	{
		select_sort(argv, a_list, count, bucket_size);
		index++;
	}
	// while (*b_list)
	// 	pa(argv, a_list, b_list, count);
	// free(b_list);
}