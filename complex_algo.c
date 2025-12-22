#include "push_swap.h"

int	getMax(t_list **list) // attrappe la valeur max
{
	int		max;
	t_list	*tmp;

	tmp = (*list);
	max = tmp->data;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

void	sort_digits(t_list **list) // doit trier par unites, etc ...
{
	t_list *tmp;
	int len;

	tmp = (*list);
	len = ft_lstsize(tmp);
	while (tmp)
	{
		if (tmp->data)

			tmp = tmp->next;
	}
}

void	radix_sort(t_list **list) // doit appeler max et sort digit
{
	int max;

	max = getMax(list);
}