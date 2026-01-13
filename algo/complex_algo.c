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

// void presort_index(t_list **a_list)
// {
// 	t_list	*tmp;
// 	int		size;

// 	tmp = (*a_list);
// 	size = ft_lstsize((*a_list));
// 	while (size < 0)
// 	{
// 		while (tmp)
// 		{
// 			if (tmp->data > tmp->next->data)
// 				(*a_list)->index++;
// 			else
// 				(*a_list)->next->index++;
// 			tmp = tmp->next;
// 		}
// 		size--;
// 	}
// 	printf("index = %d\n", (*a_list)->index);
// }
int	check_negative(t_list **a_list, int count_bits)
{
	int	val;
	int	min_val;
	int	res;
	int	move;
	// presort_index(a_list);
	min_val = get_min(a_list);
	val = (*a_list)->data;
	if (val < 0)
		res = val - min_val;
	else
		res = val;
	move = res >> count_bits & 1;
	return (move);
}

void	push_back(char *argv[], t_list **b_list, t_list **a_list,
		t_count *count)
{
	while (*b_list)
		pa(argv, a_list, b_list, count);
}

void	radix_sort(char *argv[], t_list **a_list, t_count *count)
// sort negative but problem if there is a 1
// leak memory of size 8
{
	int m_bits;
	int size;
	int count_bits;
	int index;
	t_list **b_list;

	b_list = malloc(sizeof(t_list *));
	*b_list = NULL;
	m_bits = max_bits(a_list);
	count_bits = 0;
	while (count_bits < m_bits)
	{
		index = 0;
		size = ft_lstsize((*a_list));
		while (index < size)
		{
			if ((check_negative(a_list, count_bits)) == 0)
				pb(argv, a_list, b_list, count);
			else
				ra(argv, a_list, count);
			index++;
		}
		push_back(argv, b_list, a_list, count);
		count_bits++;
	}
}
