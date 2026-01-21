/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjmrzd <bjmrzd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:56:30 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/21 15:17:20 by bjmrzd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	min_index(t_list **list)
{
	int		min;
	int		count;
	int		pos;
	t_list	*tmp;

	tmp = (*list)->next;
	min = (*list)->data;
	pos = 0;
	count = 1;
	while (tmp)
	{
		if (tmp->data < min)
		{
			min = tmp->data;
			pos = count;
		}
		tmp = tmp->next;
		count++;
	}
	return (pos);
}

// int	min_index(t_list **list)
// {
// 	int		min;
// 	t_list	*tmp;
// 	int		index;

// 	index = 0;
// 	tmp = (*list);
// 	min = get_min(list);
// 	while (tmp)
// 	{
// 		if (tmp->data == min)
// 			return (index);
// 		index++;
// 		tmp = tmp->next;
// 	}
// 	return (index);
// }
