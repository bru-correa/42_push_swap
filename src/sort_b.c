/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:37:56 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/09/27 16:10:22 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_from_stack_a(t_stacks *stacks, t_operation **ops, int count);
static void	push_sorted_to_a(t_stacks *stacks, t_operation **ops);

void	sort_b(t_stacks *stacks, t_operation **ops, int split_count)
{
	int	length;

	if (*(stacks->b) == NULL)
		get_from_stack_a(stacks, ops, split_count);
	length = node_count(stacks->b);
	while (length > 3)
	{
		split_count = split_b(stacks, ops);
		sort_b(stacks, ops, split_count);
		if (*(stacks->b) == NULL)
			get_from_stack_a(stacks, ops, split_count);
		length = node_count(stacks->b);
	}
	push_sorted_to_a(stacks, ops);
}

static void	get_from_stack_a(t_stacks *stacks, t_operation **ops, int count)
{
	while (count > 0)
	{
		push_b(stacks->a, stacks->b, ops);
		count--;
	}
}

static void	push_sorted_to_a(t_stacks *stacks, t_operation **ops)
{
	int	smallest_n;

	while (*(stacks->b) != NULL)
	{
		smallest_n = find_smallest_number(stacks->b);
		if ((*(stacks->b))->data == smallest_n)
		{
			push_a(stacks->a, stacks->b, ops);
			rotate_a(stacks->a, ops);
		}
		else if ((*(stacks->b))->next->data == smallest_n)
		{
			rotate_b(stacks->b, ops);
			push_a(stacks->a, stacks->b, ops);
			rotate_a(stacks->a, ops);
		}
		else
		{
			rev_rotate_b(stacks->b, ops);
			push_a(stacks->a, stacks->b, ops);
			rotate_a(stacks->a, ops);
		}
	}
}

