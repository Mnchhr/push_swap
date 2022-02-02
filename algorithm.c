/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:19:28 by mkuehl            #+#    #+#             */
/*   Updated: 2022/01/25 21:02:24 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_b_algorithm(t_list *stk)
{
	int		count;

	count = (stk->length_a - stk->keep_in_a);
	while (count && !ft_check_if_sorted(stk->top_a))
	{
		if (ft_is_swap_needed(stk) && !ft_check_if_sorted(stk->top_a))
			count = ft_swap_and_remarkup(stk);
		if (stk->top_a->markup == 0 && !ft_check_if_sorted(stk->top_a))
		{
			ft_push_b(stk, stk->flag);
			count--;
		}
		else if (!ft_check_if_sorted(stk->top_a))
			ft_rotate_a(stk, stk->flag);
	}
}

void	ft_push_a_algorithm(t_list *stk)
{
	t_node	*chosen;
	t_node	*place;

	while (stk->length_b)
	{
		chosen = ft_find_chosen(stk);
		place = ft_find_place_in_a(stk->top_a, chosen, stk->nums_count);
		ft_move_elem_to_a(stk, place, chosen);
	}
	ft_align_stack(stk);
}

void	ft_align_stack(t_list *stk)
{
	t_node	*temp;

	temp = stk->top_a;
	while (temp->index != 0)
		temp = temp->next;
	if ((ft_rot_by_chosen(stk->top_a, temp)) <= \
			((ft_rev_by_chosen(stk->last_a, temp))))
	{
		while (temp != stk->top_a)
			ft_rotate_a(stk, stk->flag);
	}
	else
	{
		while (temp != stk->top_a)
			ft_reverse_a(stk, stk->flag);
	}
}

t_node	*ft_find_chosen(t_list *stk)
{
	t_node	*chosen;
	t_node	*temp;

	chosen = stk->top_b;
	temp = stk->top_b;
	while (temp)
	{
		if ((ft_steps_to_move_chosen_to_a(stk, temp)) < \
			ft_steps_to_move_chosen_to_a(stk, chosen))
			chosen = temp;
		temp = temp->next;
	}
	return (chosen);
}

void	ft_move_elem_to_a(t_list *stk, t_node *place, t_node *chosen)
{
	int	rotate_b;
	int	reverse_b;
	int	rotate_a;
	int	reverse_a;

	rotate_a = ft_rot_by_chosen(stk->top_a, place);
	reverse_a = ft_rev_by_chosen(stk->last_a, place);
	rotate_b = ft_rot_by_chosen(stk->top_b, chosen);
	reverse_b = ft_rev_by_chosen(stk->last_b, chosen);
	if (rotate_b <= reverse_b && rotate_a <= reverse_a)
		ft_move_by_rot_both(stk, chosen, place);
	else if (rotate_b > reverse_b && rotate_a > reverse_a)
		ft_move_by_rev_both(stk, chosen, place);
	else if (rotate_b <= reverse_b && rotate_a > reverse_a)
		ft_move_by_rot_rev(stk, chosen, place);
	else if (rotate_b > reverse_b && rotate_a <= reverse_a)
		ft_move_by_rev_rot(stk, chosen, place);
}
