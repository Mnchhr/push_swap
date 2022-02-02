/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:19:57 by mkuehl            #+#    #+#             */
/*   Updated: 2022/01/25 19:48:42 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_by_rot_both(t_list *stk, t_node *chosen, t_node *place)
{
	while (chosen != stk->top_b && place != stk->top_a)
		ft_rotate_both(stk, stk->flag);
	while (chosen != stk->top_b)
		ft_rotate_b(stk, stk->flag);
	while (place != stk->top_a)
		ft_rotate_a(stk, stk->flag);
	ft_push_a(stk, stk->flag);
}

void	ft_move_by_rev_both(t_list *stk, t_node *chosen, t_node *place)
{
	while (chosen != stk->top_b && place != stk->top_a)
		ft_reverse_both(stk, stk->flag);
	while (chosen != stk->top_b)
		ft_reverse_b(stk, stk->flag);
	while (place != stk->top_a)
		ft_reverse_a(stk, stk->flag);
	ft_push_a(stk, stk->flag);
}

void	ft_move_by_rot_rev(t_list *stk, t_node *chosen, t_node *place)
{
	while (chosen != stk->top_b)
		ft_rotate_b(stk, stk->flag);
	while (place != stk->top_a)
		ft_reverse_a(stk, stk->flag);
	ft_push_a(stk, stk->flag);
}

void	ft_move_by_rev_rot(t_list *stk, t_node *chosen, t_node *place)
{
	while (chosen != stk->top_b)
		ft_reverse_b(stk, stk->flag);
	while (place != stk->top_a)
		ft_rotate_a(stk, stk->flag);
	ft_push_a(stk, stk->flag);
}
