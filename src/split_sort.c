/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:43:34 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/10/01 18:14:56 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_smaller_half(t_stacks *stacks, t_operation **ops, int median);
static int	push_larger_half(t_stacks *stacks, t_operation **ops);

void	split_sort(t_stacks *stacks, t_operation **ops)
{
	int	median;
	int	split_count;

	median = find_median(stacks->a);
	split_count = push_smaller_half(stacks, ops, median);
	sort_b(stacks, ops, split_count);
	split_count = push_larger_half(stacks, ops);
	sort_b(stacks, ops, split_count);
}

static int	push_smaller_half(t_stacks *stacks, t_operation **ops, int median)
{
	int		count;
	int		half_length;

	count = 0;
	half_length = node_count(stacks->a) / 2 + 1;
	while (count < half_length)
	{
		if ((*stacks->a)->data <= median)
		{
			push_b(stacks->a, stacks->b, ops);
			count++;
		}
		else
			rotate_a(stacks->a, ops);
	}
	return (count);
}

static int	push_larger_half(t_stacks *stacks, t_operation **ops)
{
	int		smallest;
	int		count;

	smallest = find_smallest_number(stacks->a);
	count = 0;
	while ((*stacks->a)->data != smallest)
	{
		push_b(stacks->a, stacks->b, ops);
		count++;
	}
	return (count);
}
