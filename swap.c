/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:20:43 by mkuehl            #+#    #+#             */
/*   Updated: 2022/01/25 17:58:08 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node **top)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = *top;
	second = first->next;
	third = second->next;
	if (third != NULL)
		third->prev = first;
	first->next = third;
	first->prev = second;
	second->prev = NULL;
	second->next = first;
	*top = second;
}

int	ft_swap_a(t_list *stk, int flag)
{
	if (stk->length_a > 1)
	{
		ft_swap(&stk->top_a);
		if (flag)
			write(1, "sa\n", 3);
		stk->oper_count++;
		return (1);
	}
	return (0);
}

int	ft_swap_b(t_list *stk, int flag)
{
	if (stk->length_b > 1)
	{
		ft_swap(&stk->top_b);
		if (flag)
			write(1, "sb\n", 3);
		stk->oper_count++;
		return (1);
	}
	return (0);
}

int	ft_swap_both(t_list *stk, int flag)
{
	if (stk->length_a > 1 || stk->length_b > 1)
	{
		if (stk->length_a > 1)
			ft_swap(&stk->top_a);
		if (stk->length_b > 1)
			ft_swap(&stk->top_b);
		if (flag)
			write(1, "ss\n", 3);
		stk->oper_count++;
		return (1);
	}
	return (0);
}
