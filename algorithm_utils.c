/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:59:13 by mkuehl            #+#    #+#             */
/*   Updated: 2021/09/08 13:33:30 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_steps_to_top(t_node *top, t_node *last, t_node *chosen)
{
	int	count;

	count = 0;
	if (chosen != top)
	{
		if (ft_rot_by_chosen(top, chosen) <= ft_rev_by_chosen(last, chosen))
			count = ft_rot_by_chosen(top, chosen);
		else
			count = ft_rev_by_chosen(last, chosen);
	}
	return (count);
}

int	ft_steps_to_move_chosen_to_a(t_list *stk, t_node *chosen)
{
	int		count;
	t_node	*place;

	count = ft_steps_to_top(stk->top_b, stk->last_b, chosen);
	place = ft_find_place_in_a(stk->top_a, chosen, stk->nums_count);
	count += ft_steps_to_top(stk->top_a, stk->last_a, place);
	return (count);
}

t_node	*ft_find_place_in_a(t_node *top, t_node *chosen, int num_count)
{
	t_node	*temp;
	t_node	*place;
	int		count;

	place = NULL;
	count = 1;
	while ((count != (num_count - chosen->index)) && !place)
	{
		temp = top;
		while (temp && !place)
		{
			if (temp->index == (chosen->index + count))
				place = temp;
			temp = temp->next;
		}
		count++;
	}
	if (!place)
		place = ft_find_place_biggest_chosen(chosen, top);
	return (place);
}

t_node	*ft_find_place_biggest_chosen(t_node *chosen, t_node *top)
{
	t_node	*place;
	t_node	*temp;
	int		count;

	count = 0;
	place = NULL;
	while ((count != chosen->index) && !place)
	{
		temp = top;
		while (temp && !place)
		{
			if (temp->index == count)
				place = temp;
			temp = temp->next;
		}
		count++;
	}
	return (place);
}
