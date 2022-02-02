/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:28:58 by mkuehl            #+#    #+#             */
/*   Updated: 2021/09/06 16:40:51 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_find_head_by_index(t_node *top)
{
	t_node	*head;
	t_node	*temp;
	int		count;

	head = top;
	while (head)
	{
		temp = head->next;
		head->if_head = 1;
		count = 1;
		while (temp)
		{
			if (temp->index == (head->index + count))
			{
				head->if_head++;
				count++;
			}
			temp = temp->next;
		}
		head->if_head += ft_find_index_head_from_top(head, top, count);
		head = head->next;
	}
	head = ft_find_head(top);
	return (head);
}

t_node	*ft_find_head_by_greater(t_node *top)
{
	t_node	*head;
	t_node	*temp;
	int		count;

	head = top;
	while (head)
	{
		head->if_head = 1;
		count = head->data;
		temp = head->next;
		while (temp)
		{
			if (temp->data > count)
			{
				head->if_head++;
				count = temp->data;
			}
			temp = temp->next;
		}
		head->if_head += ft_find_greater_head_from_top(head, top, count);
		head = head->next;
	}
	head = ft_find_head(top);
	return (head);
}

t_node	*ft_find_head(t_node *top)
{
	t_node	*head;
	t_node	*temp;

	temp = top;
	head = top;
	while (temp)
	{
		if ((temp->if_head > head->if_head) || \
			(temp->if_head == head->if_head && temp->index < head->index))
			head = temp;
		temp = temp->next;
	}
	return (head);
}

int	ft_find_greater_head_from_top(t_node *head, t_node *top, int count)
{
	t_node	*temp;
	int		if_head;

	if_head = 0;
	temp = top;
	while (temp && temp != head)
	{
		if (temp->data > count)
		{
			if_head++;
			count = temp->data;
		}
		temp = temp->next;
	}
	return (if_head);
}

int	ft_find_index_head_from_top(t_node *head, t_node *top, int count)
{
	t_node	*temp;
	int		if_head;

	if_head = 0;
	temp = top;
	while (temp && temp != head)
	{
		if (temp->index == (head->index + count))
		{
			if_head++;
			count++;
		}
		temp = temp->next;
	}
	return (if_head);
}
