#include "../push_swap.h"

int	max_bits(t_list **list)
{
	int		max;
	int		bits;
	t_list	*tmp;

	bits = 0;
	tmp = (*list);
	max = tmp->data;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	while (max > 0)
	{
		max /= 2;
		bits++;
	}
	return (bits);
}

// int	getBits(int digit, int pos)
// {
// 	int	power;
// 	int	count;

// 	count = 0;
// 	power = 1;
// 	while (count < pos)
// 	{
// 		power *= 2;
// 		count++;
// 	}
// 	return ((digit / power) % 2);
// }

void	radix_sort(t_list **b_list, t_list **a_list, t_count *count)
{
	int	m_bits;
	int	size;
	int	count_bits;
	int	index;

	m_bits = max_bits(a_list);
	count_bits = 0;
	while (count_bits < m_bits)
	{
		index = 0;
		size = ft_lstsize((*a_list));
		while (index < size)
		{
			if (!*a_list)
				break ;
			if (((*a_list)->data >> count_bits & 1) == 0)
				pb(a_list, b_list, count);
			else
				ra(a_list, count);
			index++;
		}
		while (*b_list)
			pa(a_list, b_list, count);
		count_bits++;
	}
}
