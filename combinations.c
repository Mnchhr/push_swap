/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:28:09 by mkuehl            #+#    #+#             */
/*   Updated: 2022/01/25 19:20:57 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_rev_a(t_list *stk)
{
	ft_swap_a(stk, stk->flag);
	ft_reverse_a(stk, stk->flag);
}

void	ft_rev_swap_a(t_list *stk)
{
	ft_reverse_a(stk, stk->flag);
	ft_swap_a(stk, stk->flag);
}

void	ft_swap_a_push_b(t_list *stk)
{
	ft_swap_a(stk, stk->flag);
	ft_push_b(stk, stk->flag);
}
