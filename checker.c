/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:17:51 by mkuehl            #+#    #+#             */
/*   Updated: 2022/01/26 14:55:46 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_valid_cmd(char *cmd)
{
	if (!ft_strcmp(cmd, "sa") && ft_strlen(cmd) == 2)
		return (1);
	else if (!ft_strcmp(cmd, "sb") && ft_strlen(cmd) == 2)
		return (1);
	else if (!ft_strcmp(cmd, "ss") && ft_strlen(cmd) == 2)
		return (1);
	else if (!ft_strcmp(cmd, "pa") && ft_strlen(cmd) == 2)
		return (1);
	else if (!ft_strcmp(cmd, "pb") && ft_strlen(cmd) == 2)
		return (1);
	else if (!ft_strcmp(cmd, "ra") && ft_strlen(cmd) == 2)
		return (1);
	else if (!ft_strcmp(cmd, "rb") && ft_strlen(cmd) == 2)
		return (1);
	else if (!ft_strcmp(cmd, "rr") && ft_strlen(cmd) == 2)
		return (1);
	else if (!ft_strcmp(cmd, "rra") && ft_strlen(cmd) == 3)
		return (1);
	else if (!ft_strcmp(cmd, "rrb") && ft_strlen(cmd) == 3)
		return (1);
	else if (!ft_strcmp(cmd, "rrr") && ft_strlen(cmd) == 3)
		return (1);
	return (0);
}

void	ft_exec_cmd(t_list *stk, char *cmd)
{
	if (!ft_strcmp(cmd, "sa"))
		ft_swap_a(stk, 0);
	else if (!ft_strcmp(cmd, "sb"))
		ft_swap_b(stk, 0);
	else if (!ft_strcmp(cmd, "ss"))
		ft_swap_both(stk, 0);
	else if (!ft_strcmp(cmd, "pa"))
		ft_push_a(stk, 0);
	else if (!ft_strcmp(cmd, "pb"))
		ft_push_b(stk, 0);
	else if (!ft_strcmp(cmd, "ra"))
		ft_rotate_a(stk, 0);
	else if (!ft_strcmp(cmd, "rb"))
		ft_rotate_b(stk, 0);
	else if (!ft_strcmp(cmd, "rr"))
		ft_rotate_both(stk, 0);
	else if (!ft_strcmp(cmd, "rra"))
		ft_reverse_a(stk, 0);
	else if (!ft_strcmp(cmd, "rrb"))
		ft_reverse_b(stk, 0);
	else if (!ft_strcmp(cmd, "rrr"))
		ft_reverse_both(stk, 0);
	free(cmd);
}

int	ft_error_exit(t_list *stk, char *cmd, char *message)
{
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	ft_free_stk(stk, cmd);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stk;
	char	*cmd;

	cmd = NULL;
	if (argc == 1)
		return (0);
	if (!ft_check_args(argv))
		return (ft_error_exit(NULL, cmd, "Error"));
	stk = ft_init_stacks(argv);
	if (!stk)
		return (ft_error_exit(stk, cmd, "Error"));
	while (get_next_line(0, &cmd) > 0)
	{
		if (ft_valid_cmd(cmd))
			ft_exec_cmd(stk, cmd);
		else
			return (ft_error_exit(stk, cmd, "Error"));
	}
	if (ft_check_if_sorted(stk->top_a) && !stk->top_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stk(stk, cmd);
	return (0);
}
