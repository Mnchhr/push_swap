/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markups.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:26:41 by mkuehl            #+#    #+#             */
/*   Updated: 2021/09/06 17:02:28 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_index_markup(t_list *stk)
{
	t_node	*temp;
	int		count;

	stk->index_head = ft_find_head_by_index(stk->top_a);
	stk->index_head->markup = 1;
	count = 1;
	temp = stk->index_head->next;
	while (temp)
	{
		if (temp->index == (stk->index_head->index + count))
		{
			temp->markup = 1;
			count++;
		}
		else
			temp->markup = 0;
		temp = temp->next;
	}
	ft_index_markup_from_top(stk->index_head, stk->top_a, count);
	return (stk->index_head->if_head);
}

int	ft_greater_markup(t_list *stk)
{
	t_node	*temp;
	int		count;

	stk->greater_head = ft_find_head_by_greater(stk->top_a);
	stk->greater_head->markup = 1;
	temp = stk->greater_head->next;
	count = stk->greater_head->data;
	while (temp)
	{
		if (temp->data > count)
		{
			temp->markup = 1;
			count = temp->data;
		}
		else
			temp->markup = 0;
		temp = temp->next;
	}
	ft_greater_markup_from_top(stk->greater_head, stk->top_a, count);
	return (stk->greater_head->if_head);
}

void	ft_greater_markup_from_top(t_node *head, t_node *top, int count)
{
	t_node	*temp;

	temp = top;
	while (temp && temp != head)
	{
		if (temp->data > count)
		{
			temp->markup = 1;
			count = temp->data;
		}
		else
			temp->markup = 0;
		temp = temp->next;
	}
}

void	ft_index_markup_from_top(t_node *head, t_node *top, int count)
{
	t_node	*temp;

	temp = top;
	while (temp && temp != head)
	{
		if (temp->index == (head->index + count))
		{
			temp->markup = 1;
			count++;
		}
		else
			temp->markup = 0;
		temp = temp->next;
	}
}
