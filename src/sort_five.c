/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:29:24 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/10/01 18:23:37 by bcorrea-         ###   ########.fr       */
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

// static void	small_sort_a(t_stacks *stacks, t_operation **ops)
// {
// 	t_node	*first_node;
// 	t_node	*second_node;
//
// 	first_node = (*stacks->a);
// 	second_node = (*stacks->a)->next;
// 	if (first_node->data > second_node->data)
// 		swap_a(stacks->a, ops);
// }

// static void	small_sort_b(t_stacks *stacks, t_operation **ops)
// {
// 	int largest;
// 	int	rotations;
// 	
// 	while (node_count(stacks->b) > 0)
// 	{
// 		largest = find_largest_number(stacks->a);
// 		rotations = get_rotations(stacks->b, largest);
// 		while (rotations > 0)
// 		{
// 			rotate_b(stacks->b, ops);
// 			rotations--;
// 		}
// 		while (rotations < 0)
// 		{
// 			rev_rotate_b(stacks->b, ops);
// 			rotations++;
// 		}
// 		push_a(stacks->a, stacks->b, ops);
// 	}
// }
//
// // NOTE: Return a negative value if reverse rotate is more optimal
// static int	get_rotations(t_node **stack, int largest)
// {
// 	int		rotations;
// 	int		length;
// 	t_node	*current_node;
//
// 	length = node_count(stack);
// 	current_node = *stack;
// 	rotations = 0;
// 	while (current_node->data != largest)
// 	{
// 		current_node = current_node->next;
// 		rotations++;
// 	}
// 	if (rotations > length / 2)
// 		rotations = rotations - length;
// 	return (rotations);
// }

