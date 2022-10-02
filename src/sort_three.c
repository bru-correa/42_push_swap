/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:00:34 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/10/01 22:09:39 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_largest_top(t_node **stack_a, t_operation **ops, int smallest);
static void	sort_smallest_top(t_node **stack_a, t_operation **ops, int largest);
static void	sort_median_top(t_node **stack_a, t_operation **ops, int smallest);

void	sort_three(t_node **stack_a, t_operation **ops)
{
	int	smallest;
	int	largest;

	smallest = find_smallest_number(stack_a);
	largest = find_largest_number(stack_a);
	if ((*stack_a)->data == largest)
		sort_largest_top(stack_a, ops, smallest);
	else if ((*stack_a)->data == smallest)
		sort_smallest_top(stack_a, ops, largest);
	else
		sort_median_top(stack_a, ops, smallest);
}

static void	sort_largest_top(t_node **stack_a, t_operation **ops, int smallest)
{
	if ((*stack_a)->next->data == smallest)
		rotate_a(stack_a, ops);
	else
	{
		swap_a(stack_a, ops);
		rev_rotate_a(stack_a, ops);
	}
}

static void	sort_smallest_top(t_node **stack_a, t_operation **ops, int largest)
{
	if ((*stack_a)->next->data == largest)
	{
		swap_a(stack_a, ops);
		rotate_a(stack_a, ops);
	}
}

static void	sort_median_top(t_node **stack_a, t_operation **ops, int smallest)
{
	if ((*stack_a)->next->data == smallest)
		swap_a(stack_a, ops);
	else
		rev_rotate_a(stack_a, ops);
}
