/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:02:05 by mkuehl            #+#    #+#             */
/*   Updated: 2022/01/25 17:57:51 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_node **top, t_node **last, int length)
{
	if (length > 2)
	{
		(*last)->next = *top;
		(*top)->prev = *last;
		*top = (*top)->next;
		(*top)->prev = NULL;
		*last = (*last)->next;
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

int	ft_rotate_a(t_list *stk, int flag)
{
	if (stk->length_a >= 2)
	{
		ft_rotate(&stk->top_a, &stk->last_a, stk->length_a);
		if (flag)
			write(1, "ra\n", 3);
		stk->oper_count++;
		return (1);
	}
	return (0);
}

int	ft_rotate_b(t_list *stk, int flag)
{
	if (stk->length_b >= 2)
	{
		ft_rotate(&stk->top_b, &stk->last_b, stk->length_b);
		if (flag)
			write(1, "rb\n", 3);
		stk->oper_count++;
		return (1);
	}
	return (0);
}

int	ft_rotate_both(t_list *stk, int flag)
{
	if (stk->length_a >= 2 || stk->length_b >= 2)
	{
		ft_rotate(&stk->top_a, &stk->last_a, stk->length_a);
		ft_rotate(&stk->top_b, &stk->last_b, stk->length_b);
		if (flag)
			write(1, "rr\n", 3);
		stk->oper_count++;
		return (1);
	}
	return (0);
}
