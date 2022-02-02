/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:19:12 by mkuehl            #+#    #+#             */
/*   Updated: 2022/01/25 17:54:24 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack_a(char **argv, t_list *stk)
{
	int		i;
	t_node	*temp;

	i = 1;
	temp = (t_node *)malloc(sizeof(t_node));
	if (!temp)
		return ;
	temp->data = ft_atoi(argv[i++]);
	temp->prev = NULL;
	temp->next = NULL;
	stk->top_a = temp;
	stk->last_a = temp;
	stk->nums_count = 1;
	while (argv[i])
	{
		temp = (t_node *)malloc(sizeof(t_node));
		if (!temp)
			return ;
		temp->data = ft_atoi(argv[i++]);
		temp->next = NULL;
		temp->prev = stk->last_a;
		stk->last_a->next = temp;
		stk->last_a = temp;
		stk->nums_count++;
	}
}

t_list	*ft_init_stacks(char **argv)
{
	t_list	*stk;

	stk = (t_list *)malloc(sizeof(t_list));
	if (!stk)
		return (NULL);
	ft_init_stack_a(argv, stk);
	stk->top_b = NULL;
	stk->last_b = NULL;
	stk->length_a = stk->nums_count;
	stk->length_b = 0;
	stk->index_head = NULL;
	stk->greater_head = NULL;
	stk->oper_count = 0;
	return (stk);
}
