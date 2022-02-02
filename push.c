/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:56:34 by mkuehl            #+#    #+#             */
/*   Updated: 2022/01/25 17:56:59 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_a(t_list *stk, int flag)
{
	t_node	*temp;

	if (stk->top_b)
	{
		temp = stk->top_b;
		if (stk->top_b->next == NULL)
			stk->last_b = NULL;
		stk->top_b = stk->top_b->next;
		if (stk->top_b != NULL)
			stk->top_b->prev = NULL;
		temp->next = stk->top_a;
		temp->prev = NULL;
		stk->top_a->prev = temp;
		stk->top_a = temp;
		stk->length_a++;
		stk->length_b--;
		stk->oper_count++;
		if (flag)
			write(1, "pa\n", 3);
		return (1);
	}
	return (0);
}

int	ft_push_b(t_list *stk, int flag)
{
	t_node	*temp;

	if (stk->top_a)
	{
		temp = stk->top_a;
		stk->top_a = stk->top_a->next;
		stk->top_a->prev = NULL;
		temp->next = stk->top_b;
		temp->prev = NULL;
		if (stk->top_b != NULL)
			stk->top_b->prev = temp;
		stk->top_b = temp;
		if (stk->last_b == NULL)
			stk->last_b = stk->top_b;
		stk->length_b++;
		stk->length_a--;
		stk->oper_count++;
		if (flag)
			write(1, "pb\n", 3);
		return (1);
	}
	return (0);
}
