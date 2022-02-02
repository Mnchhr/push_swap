/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:20:52 by mkuehl            #+#    #+#             */
/*   Updated: 2022/01/25 21:35:43 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct node
{
	int			data;
	int			index;
	int			markup;
	int			if_head;
	struct node	*prev;
	struct node	*next;
}				t_node;

typedef struct list
{
	t_node	*top_a;
	t_node	*top_b;
	t_node	*last_a;
	t_node	*last_b;
	t_node	*index_head;
	t_node	*greater_head;
	int		flag;
	int		oper_count;
	int		keep_in_a;
	int		nums_count;
	int		length_a;
	int		length_b;
}			t_list;

t_list	*ft_init_stacks(char **argv);
t_node	*ft_find_place_in_a(t_node *top, t_node *chosen, int num_count);
t_node	*ft_find_place_biggest_chosen(t_node *chosen, t_node *top);
t_node	*ft_find_head(t_node *top);
t_node	*ft_find_head_by_index(t_node *top);
t_node	*ft_find_head_by_greater(t_node *top);
t_node	*ft_find_chosen(t_list *stk);
size_t	ft_strlen(const char *s);
void	ft_greater_markup_from_top(t_node *head, t_node *top, int count);
void	ft_index_markup_from_top(t_node *head, t_node *top, int count);
void	ft_move_elem_to_a(t_list *stk, t_node *place, t_node *chosen);
void	ft_reverse(t_node **top, t_node **last, int length);
void	ft_rotate(t_node **top, t_node **last, int length);
void	ft_swap(t_node **top);
void	ft_rev_swap_a(t_list *stk);
void	ft_swap_rev_a(t_list *stk);
void	ft_swap_a_push_b(t_list *stk);
void	ft_init_stack_a(char **argv, t_list *stk);
void	ft_free_nodes(t_node *top);
void	ft_free_stk(t_list *stk, char *cmd);
void	ft_sort_3_elems(t_list *stk);
void	ft_index_stk(t_list *stk);
void	ft_push_b_algorithm(t_list *stk);
void	ft_push_a_algorithm(t_list *stk);
void	ft_align_stack(t_list *stk);
void	ft_align_stk_b(t_list *stk);
void	ft_move_by_rev_rot(t_list *stk, t_node *chosen, t_node *place);
void	ft_move_by_rot_rev(t_list *stk, t_node *chosen, t_node *place);
void	ft_move_by_rev_both(t_list *stk, t_node *chosen, t_node *place);
void	ft_move_by_rot_both(t_list *stk, t_node *chosen, t_node *place);
long	*ft_selection_sort(long *array);
long	*ft_sort(t_node *top, int count);
int		ft_push_a(t_list *stk, int flag);
int		ft_push_b(t_list *stk, int flag);
int		ft_reverse_a(t_list *stk, int flag);
int		ft_reverse_b(t_list *stk, int flag);
int		ft_reverse_both(t_list *stk, int flag);
int		ft_rotate_a(t_list *stk, int flag);
int		ft_rotate_b(t_list *stk, int flag);
int		ft_rotate_both(t_list *stk, int flag);
int		ft_swap_a(t_list *stk, int flag);
int		ft_swap_b(t_list *stk, int flag);
int		ft_swap_both(t_list *stk, int flag);
int		ft_check_for_duplicates(char **argv);
int		ft_check_args(char **argv);
int		ft_check_if_sorted(t_node *top);
int		ft_index_markup(t_list *stk);
int		ft_greater_markup(t_list *stk);
int		ft_remarkup_greater(t_node *head, t_node *top);
int		ft_remarkup_index(t_node *head, t_node *top);
int		ft_rot_by_markup(t_node *top);
int		ft_rev_by_markup(t_node *last);
int		ft_rot_by_chosen(t_node *top, t_node *chosen);
int		ft_rev_by_chosen(t_node *last, t_node *chosen);
int		ft_is_swap_needed(t_list *stk);
int		ft_swap_and_remarkup(t_list *stk);
int		ft_steps_to_move_chosen_to_a(t_list *stk, t_node *chosen);
int		ft_steps_to_top(t_node *top, t_node *last, t_node *chosen);
int		ft_find_greater_head_from_top(t_node *head, t_node *top, int count);
int		ft_find_index_head_from_top(t_node *head, t_node *top, int count);

#endif
