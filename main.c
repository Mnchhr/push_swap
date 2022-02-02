/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:20:34 by mkuehl            #+#    #+#             */
/*   Updated: 2022/01/26 14:37:43 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_index_algo(t_list *stk, int flag)
{
	stk->flag = flag;
	stk->keep_in_a = ft_index_markup(stk);
	stk->greater_head = NULL;
	ft_push_b_algorithm(stk);
	ft_push_a_algorithm(stk);
	return (stk->oper_count);
}

int	ft_greater_algo(t_list *stk, int flag)
{
	stk->flag = flag;
	stk->keep_in_a = ft_greater_markup(stk);
	stk->index_head = NULL;
	ft_push_b_algorithm(stk);
	ft_push_a_algorithm(stk);
	return (stk->oper_count);
}

void	ft_run_algo(char **argv)
{
	t_list	*stk;
	int		res_index;
	int		res_greater;

	stk = ft_init_stacks(argv);
	ft_index_stk(stk);
	res_index = ft_index_algo(stk, 0);
	ft_free_stk(stk, NULL);
	stk = ft_init_stacks(argv);
	ft_index_stk(stk);
	res_greater = ft_greater_algo(stk, 0);
	ft_free_stk(stk, NULL);
	stk = ft_init_stacks(argv);
	ft_index_stk(stk);
	if (res_index <= res_greater)
		ft_index_algo(stk, 1);
	else
		ft_greater_algo(stk, 1);
	ft_free_stk(stk, NULL);
}

int	main(int argc, char **argv)
{
	t_list	*stk;

	if (argc > 1)
	{
		if (!ft_check_args(argv))
			return (write(1, "Error\n", 6));
		if (argc == 2 && ft_isnumber(argv[1]))
			return (0);
		stk = ft_init_stacks(argv);
		ft_index_stk(stk);
		if (ft_check_if_sorted(stk->top_a) && stk->top_b == NULL)
		{
			ft_free_stk(stk, NULL);
			return (0);
		}
		if (stk->nums_count == 3)
			ft_sort_3_elems(stk);
		ft_free_stk(stk, NULL);
		ft_run_algo(argv);
	}
	return (0);
}
