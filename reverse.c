/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:35:05 by mkuehl            #+#    #+#             */
/*   Updated: 2022/01/25 17:57:34 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse(t_node **top, t_node **last, int length)
{
	t_node	*temp;

	if (length > 2)
	{
		temp = (*last)->prev;
		(*last)->next = *top;
		(*last)->prev = NULL;
		(*top)->prev = *last;
		*top = *last;
		*last = temp;
		(*last)->next = NULL;
	}
	else if (length == 2)
	{
		(*last)->prev = NULL;
		(*top)->next = NULL;
		(*top)->prev = *last;
		(*last)->next = *top;
		*top = *last;
		*last = (*top)->next;
	}
}

int	ft_reverse_a(t_list *stk, int flag)
{
	if (stk->length_a >= 2)
	{
		ft_reverse(&stk->top_a, &stk->last_a, stk->length_a);
		if (flag)
			write(1, "rra\n", 4);
		stk->oper_count++;
		return (1);
	}
	return (0);
}

int	ft_reverse_b(t_list *stk, int flag)
{
	if (stk->length_b >= 2)
	{
		ft_reverse(&stk->top_b, &stk->last_b, stk->length_b);
		if (flag)
			write(1, "rrb\n", 4);
		stk->oper_count++;
		return (1);
	}
	return (0);
}

int	ft_reverse_both(t_list *stk, int flag)
{
	if (stk->length_a >= 2)
		ft_reverse(&stk->top_a, &stk->last_a, stk->length_a);
	if (stk->length_b >= 2)
		ft_reverse(&stk->top_b, &stk->last_b, stk->length_b);
	if (flag)
		write(1, "rrr\n", 4);
	stk->oper_count++;
	return (1);
}
