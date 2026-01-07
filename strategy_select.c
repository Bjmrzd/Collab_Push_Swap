#include "push_swap.h"

void	init_radix(t_list **a_list, t_count *count)
{
	t_list	**b_list;

	b_list = malloc(sizeof(t_list *));
	radix_sort(b_list, a_list, count);
}

void	adaptive(int argc, char *argv[], t_list **list, t_count *count)
{
	float	dis;

	dis = disorder(list);
	if (dis < 0.2)
		simple_sort(argc, argv, list, count);
	// if (dis >= 0.2 && dis < 0.5)
	// 	chunk_sort();
	if (dis >= 0.5)
		init_radix(list, count);
}

void	strat_select(int argc, char *argv[], t_list **list, t_count *count)
{
	t_flag flag;
	t_flag isbench;

	isbench = arg_error(argc, argv);
	if (isbench == BENCH)
		flag = second_flag(argc, argv);
	else
		flag = arg_error(argc, argv);
	if (flag == ADAPTIVE || flag == NO_FLAG)
		adaptive(argc, argv, list, count);
	if (flag == SIMPLE)
		simple_sort(argc, argv, list, count);
	// else if (flag == MEDIUM)
	// 	chunk_sort();
	else if (flag == COMPLEX)
		init_radix(list, count);
}