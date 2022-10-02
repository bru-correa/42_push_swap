/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:29:24 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/10/01 22:41:03 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_smaller_half(t_stacks *stacks, t_operation **ops);
static void	sort_smaller_half(t_stacks *stacks, t_operation **ops);

void	sort_five(t_stacks *stacks, t_operation **ops)
{
	int	length;

	push_smaller_half(stacks, ops);
	length = node_count(stacks->a);
	if (length == 2)
		sort_two(stacks, ops);
	else
		sort_three(stacks->a, ops);
	sort_smaller_half(stacks, ops);
}

static void	push_smaller_half(t_stacks *stacks, t_operation **ops)
{
	int	median;
	int	count;

	median = find_median(stacks->a);
	count = 0;
	while (count < 2)
	{
		if ((*stacks->a)->data < median)
		{
			push_b(stacks->a, stacks->b, ops);
			count++;
		}
		else
			rotate_a(stacks->a, ops);
	}
}

static void	sort_smaller_half(t_stacks *stacks, t_operation **ops)
{
	int	largest;

	largest = find_largest_number(stacks->b);
	if ((*stacks->b)->data != largest)
		swap_b(stacks->b, ops);
	while ((*stacks->b) != NULL)
		push_a(stacks->a, stacks->b, ops);
}
