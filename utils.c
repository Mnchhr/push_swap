/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:27:19 by mkuehl            #+#    #+#             */
/*   Updated: 2022/01/25 21:49:04 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rot_by_chosen(t_node *top, t_node *chosen)
{
	int		count;
	t_node	*temp;

	count = 0;
	temp = top;
	if (temp->next)
	{
		while (temp != chosen)
		{
			temp = temp->next;
			count++;
		}
	}
	return (count);
}

int	ft_rev_by_chosen(t_node *last, t_node *chosen)
{
	int		count;
	t_node	*temp;

	count = 1;
	temp = last;
	if (temp->prev)
	{
		while (temp != chosen)
		{
			temp = temp->prev;
			count++;
		}
	}
	return (count);
}

int	ft_rot_by_markup(t_node *top)
{
	int		count;
	t_node	*temp;

	count = 0;
	temp = top;
	while (temp && temp->markup != 0)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int	ft_rev_by_markup(t_node *last)
{
	int		count;
	t_node	*temp;

	count = 1;
	temp = last;
	while (temp && temp->markup != 0)
	{
		count++;
		temp = temp->prev;
	}
	return (count);
}

int	ft_is_swap_needed(t_list *stk)
{
	ft_swap(&stk->top_a);
	if (stk->greater_head)
	{
		if (ft_remarkup_greater(stk->greater_head, stk->top_a) > \
			stk->greater_head->if_head)
		{
			ft_swap(&stk->top_a);
			return (1);
		}
	}
	else if (stk->index_head)
	{
		if (ft_remarkup_index(stk->index_head, stk->top_a) > \
			stk->index_head->if_head)
		{
			ft_swap(&stk->top_a);
			return (1);
		}
	}
	ft_swap(&stk->top_a);
	return (0);
}
