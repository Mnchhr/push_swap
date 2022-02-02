/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:28:01 by mkuehl            #+#    #+#             */
/*   Updated: 2022/01/26 14:36:44 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_for_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] && argv[i + 1])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) != ft_atoi(argv[j]))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_isnumber(argv[i]))
			return (0);
		i++;
	}
	i = 1;
	while (argv[i])
	{
		if ((ft_atoi(argv[i]) == 0 && ft_strlen(argv[i]) > 9) \
			|| (ft_atoi(argv[i]) == -1 && ft_strlen(argv[i]) > 9))
			return (0);
		i++;
	}
	if (!ft_check_for_duplicates(argv))
		return (0);
	return (1);
}

int	ft_check_if_sorted(t_node *top)
{
	t_node	*temp;

	if (top->next != NULL)
	{
		temp = top->next;
		while (temp != NULL)
		{
			if (temp->prev->data > temp->data)
				return (0);
			temp = temp->next;
		}
		return (1);
	}
	return (0);
}
