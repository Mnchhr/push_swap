/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:20:24 by mkuehl            #+#    #+#             */
/*   Updated: 2022/01/25 21:52:41 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_nodes(t_node *top)
{
	t_node	*temp;

	if (top)
	{
		while (top->next != NULL)
		{
			temp = top;
			top = top->next;
			free(temp);
		}
		free(top);
	}
}

void	ft_free_stk(t_list *stk, char *cmd)
{
	if (stk)
	{
		if (stk->top_a != NULL)
			ft_free_nodes(stk->top_a);
		if (stk->top_b != NULL)
			ft_free_nodes(stk->top_b);
		if (stk)
			free(stk);
	}
	if (cmd)
		free(cmd);
}
