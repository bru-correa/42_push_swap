/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 04:57:05 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/09/24 15:51:24 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	partition(t_node **stack_a, t_node **stack_b,
				t_operation **operations);
static void	divide_stack_a(t_node **stack_a, t_node **stack_b,
				t_operation **operations, int median);
static void	sort_smaller_half(t_node **stack_a, t_node **stack_b,
				t_operation **operations, int median);
static void	sort_larger_half(t_node **stack_a, t_node **stack_b,
				t_operation **operations, int smallest_n);

// WARNING: Error check the stacks before calling this!!!
void	split_sort(t_node **stack_a, t_node **stack_b, t_operation **operations)
{
	int	median;
	int	smallest_n;

	median = find_median(stack_a);
	smallest_n = find_smallest_number(stack_a);
	divide_stack_a(stack_a, stack_b, operations, median);
	sort_smaller_half(stack_a, stack_b, operations, median);
	sort_larger_half(stack_a, stack_b, operations, smallest_n);
}

// TODO: Middle -1 for even numbers
static void	partition(t_node **stack_a, t_node **stack_b,
		t_operation **operations)
{
	int	median;
	int	smallest_n;

	if (*stack_b == NULL)
		return ;
	median = find_median(stack_b);
	smallest_n = find_smallest_number(stack_b);
	while (*stack_b != NULL)
	{
		if ((*stack_b)->data > median)
			push_a(stack_a, stack_b, operations);
		else if ((*stack_b)->data == smallest_n)
		{
			push_a(stack_a, stack_b, operations);
			rotate_a(stack_a, operations);
			if (*stack_b != NULL)
				smallest_n = find_smallest_number(stack_b);
		}
		else
			rotate_b(stack_b, operations);
	}
}

static void	divide_stack_a(t_node **stack_a, t_node **stack_b,
		t_operation **operations, int median)
{
	int	counter;

	counter = (node_count(stack_a) / 2) + 1;
	while (counter > 0)
	{
		if ((*stack_a)->data <= median)
		{
			push_b(stack_a, stack_b, operations);
			counter--;
		}
		else
			rotate_a(stack_a, operations);
	}
}

static void	sort_smaller_half(t_node **stack_a, t_node **stack_b,
		t_operation **operations, int median)
{
	partition(stack_a, stack_b, operations);
	if ((*stack_a)->prev->data != median)
	{
		// while ((*stack_a)->data != smallest_n)
		// {
		// 	if ((*stack_a)->data <= median)
		// 		push_b(stack_a, stack_b, operations);
		// 	else
		// 		break ;
		// }
		while ((*stack_a)->data <= median)
			push_b(stack_a, stack_b, operations);
		sort_smaller_half(stack_a, stack_b, operations, median);
	}
}

static void	sort_larger_half(t_node **stack_a, t_node **stack_b,
		t_operation **operations, int smallest_n)
{
	while ((*stack_a)->data != smallest_n)
		push_b(stack_a, stack_b, operations);
	partition(stack_a, stack_b, operations);
	if ((*stack_a)->data != smallest_n)
		sort_larger_half(stack_a, stack_b, operations, smallest_n);
}
