/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 17:51:18 by mkuehl            #+#    #+#             */
/*   Updated: 2022/01/25 17:52:04 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index_stk(t_list *stk)
{
	t_node	*temp;
	long	*array;
	int		i;

	array = ft_sort(stk->top_a, stk->nums_count);
	temp = stk->top_a;
	i = 0;
	while (temp)
	{
		while (temp->data != array[i])
			i++;
		temp->index = i;
		i = 0;
		temp = temp->next;
	}
	free(array);
}

long	*ft_selection_sort(long *array)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (array[i] != 2147483648)
	{
		min = array[i];
		j = i + 1;
		while (array[j] != 2147483648)
		{
			if (min > array[j])
			{
				min = array[j];
				array[j] = array[i];
				array[i] = min;
			}
			j++;
		}
		i++;
	}
	return (array);
}

long	*ft_sort(t_node *top, int count)
{
	t_node	*temp;
	long	*array;
	int		i;

	array = (long *)malloc(sizeof(long) * (count + 1));
	temp = top;
	i = 0;
	while (temp)
	{
		array[i] = temp->data;
		i++;
		temp = temp->next;
	}
	array[i] = 2147483648;
	return (ft_selection_sort(array));
}

void	ft_sort_3_elems(t_list *stk)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stk->top_a;
	second = stk->top_a->next;
	third = stk->last_a;
	if (second == third)
		ft_swap_a(stk, stk->flag);
	else if (second->data > first->data && second->data > third->data)
	{
		if (first->data < third->data)
			ft_rev_swap_a(stk);
		else
			ft_reverse_a(stk, stk->flag);
	}
	else if (second->data < first->data && second->data < third->data)
	{
		if (first->data < third->data)
			ft_swap_a(stk, stk->flag);
		else
			ft_rotate_a(stk, stk->flag);
	}
	else if (second->data < first->data && second->data > third->data)
		ft_swap_rev_a(stk);
}
