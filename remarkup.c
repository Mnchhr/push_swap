/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remarkup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:37:42 by mkuehl            #+#    #+#             */
/*   Updated: 2022/01/25 18:59:48 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_remarkup_greater(t_node *head, t_node *top)
{
	t_node	*temp;
	int		count;
	int		if_head;

	if_head = 1;
	count = head->data;
	temp = head->next;
	while (temp)
	{
		if (temp->data > count)
		{
			if_head++;
			count = temp->data;
		}
		temp = temp->next;
	}
	if_head += ft_find_greater_head_from_top(head, top, count);
	return (if_head);
}

int	ft_remarkup_index(t_node *head, t_node *top)
{
	t_node	*temp;
	int		count;
	int		if_head;

	if_head = 1;
	count = 1;
	temp = head->next;
	while (temp)
	{
		if (temp->index == (head->index + count))
		{
			if_head++;
			count++;
		}
		temp = temp->next;
	}
	if_head += ft_find_index_head_from_top(head, top, count);
	return (count);
}

int	ft_swap_and_remarkup(t_list *stk)
{
	int	count;

	ft_swap_a(stk, stk->flag);
	if (stk->greater_head)
		stk->keep_in_a = ft_greater_markup(stk);
	else if (stk->index_head)
		stk->keep_in_a = ft_index_markup(stk);
	count = (stk->length_a - stk->keep_in_a);
	return (count);
}
