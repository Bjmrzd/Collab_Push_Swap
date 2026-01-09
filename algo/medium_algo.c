#include "../push_swap.h"

void	chunk_sort(t_list **a_list) // marche pas doit faire fonctionner
{
	int **tab;
	int size;
	int index;
	int index2;
	t_list *tmp;

	tmp = (*a_list);
	size = ft_lstsize((*a_list));
	tab = malloc((size / 5) * sizeof(int *));
	if (!tab)
		return ;
	index = 0;
	index2 = 0;
	while (index < 5)
		tab[index++] = malloc(5 * sizeof(int));
	index = 0;
	while (tmp)
	{
		if (index2 % 5 == 0)
			index++;
		tab[index][index2++] = tmp->data;
		tmp = tmp->next;
	}
}