/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:03:13 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/09/27 20:53:09 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_for_larger(t_node **stack, int median);
static int	get_rotations(t_node **stack, int median);
static void	smart_push(t_stacks *stacks, t_operation **ops, int rotations);
static int	check_smallest(t_stacks *stacks, t_operation **ops, int *smallest);

int	split_b(t_stacks *stacks, t_operation **ops)
{
	int	median;
	int	rotations;
	int	split_count;

	median = find_median(stacks->b);
	split_count = 0;
	while (check_for_larger(stacks->b, median) == TRUE)
	{
		rotations = get_rotations(stacks->b, median);
		smart_push(stacks, ops, rotations);
		split_count++;
	}
	return (split_count);
}

// NOTE: Check if there's any larger number left
static int	check_for_larger(t_node **stack, int median)
{
	t_node	*current_node;

	if ((*stack)->data >= median)
		return (TRUE);
	current_node = (*stack)->next;
	while (current_node != *stack)
	{
		if (current_node->data >= median)
			return (TRUE);
		current_node = current_node->next;
	}
	return (FALSE);
}

// NOTE: Get the rotations needed to get to the closest larger number
static int	get_rotations(t_node **stack, int median)
{
	t_node	*current_node;
	int		rotations;
	int		inv_rotations;

	current_node = *stack;
	rotations = 0;
	if (current_node->data >= median)
		return (0);
	while (current_node->data < median)
	{
		current_node = current_node->next;
		rotations++;
	}
	current_node = *stack;
	inv_rotations = 0;
	while (current_node->data < median)
	{
		current_node = current_node->prev;
		inv_rotations--;
	}
	if (rotations <= inv_rotations * -1)
		return (rotations);
	else
		return (inv_rotations);
}

// NOTE: Smart rotate to the larger number, while pushing the smallest number
static void	smart_push(t_stacks *stacks, t_operation **ops, int rotations)
{
	int	smallest;

	smallest = find_smallest_number(stacks->b);
	while (rotations > 0)
	{
		if (check_smallest(stacks, ops, &smallest) == TRUE)
			continue ;
		else
			rotate_b(stacks->b, ops);
		rotations--;
	}
	while (rotations < 0)
	{
		if (check_smallest(stacks, ops, &smallest) == TRUE)
			continue ;
		else
			rev_rotate_b(stacks->b, ops);
		rotations++;
	}
	push_a(stacks->a, stacks->b, ops);
}

static int	check_smallest(t_stacks *stacks, t_operation **ops, int *smallest)
{
	if ((*stacks->a)->data == *smallest)
	{
		push_a(stacks->a, stacks->b, ops);
		rotate_a(stacks->a, ops);
		*smallest = find_smallest_number(stacks->b);
		return (TRUE);
	}
	return (FALSE);
}

// static void	check_smallest(t_stacks *stacks, t_operation **ops, int smallest);
// static int	get_next_larger(t_node **stack, int median);
// static int	push_next(t_stacks *stacks, t_operation **ops, int median);

// int	split_b(t_stacks *stacks, t_operation **ops)
// {
// 	int	median;
// 	int	split_count;
//
// 	median = find_median(stacks->b);
// 	split_count = 0;
// 	while (push_next(stacks, ops, median) == 1)
// 		split_count++;
// 	return (split_count);
// }

// // NOTE: Return 1 if could push, 0 if not
// static int	push_next(t_stacks *stacks, t_operation **ops, int median)
// {
// 	int	smallest;
// 	int	rotations;
//
// 	smallest = find_smallest_number(stacks->b);
// 	rotations = get_next_larger(stacks->b, median);
// 	if (rotations == 0 && (*stacks->b)->data < median)
// 		return (0);
// 	while (rotations > 0)
// 	{
// 		if ((*stacks->b)->data == smallest)
// 		{
// 			push_a(stacks->a, stacks->b, ops);
// 			rotate_a(stacks->a, ops);
// 			smallest = find_smallest_number(stacks->b);
// 		}
// 		else
// 			rotate_b(stacks->b, ops);
// 		rotations--;
// 	}
// 	while (rotations < 0)
// 	{
// 		if ((*stacks->b)->data == smallest)
// 		{
// 			push_a(stacks->a, stacks->b, ops);
// 			rotate_a(stacks->a, ops);
// 			smallest = find_smallest_number(stacks->b);
// 		}
// 		else
// 			rev_rotate_b(stacks->b, ops);
// 		rotations--;
// 	}
// 	push_a(stacks->a, stacks->b, ops);
// 	return (1);
// }

// // TODO: Optimize this function by removing the second while loop
// // NOTE: Return the rotations count, return a negative number if reverse rotate is more efficient
// static int	get_next_larger(t_node **stack, int median)
// {
// 	int		rotations;
// 	int		max_rotations;
// 	t_node	*current_node;
//
// 	max_rotations = node_count(stack) / 2;
// 	rotations = 0;
// 	current_node = *stack;
// 	if (current_node->data >= median)
// 		return (rotations);
// 	current_node = (*stack)->next;
// 	while (current_node != *stack)
// 	{
// 		if (current_node->data >= median)
// 			return (rotations);
// 		else if (rotations > max_rotations)
// 			break ;
// 		current_node = current_node->next;
// 		rotations++;
// 	}
// 	current_node = (*stack)->prev;
// 	rotations = -1;
// 	while (current_node != *stack)
// 	{
// 		if (current_node->data >= median)
// 			return (rotations);
// 		current_node = current_node->prev;
// 		rotations--;
// 	}
// 	return (0);
// }

// static void	check_smallest(t_stacks *stacks, t_operation **ops, int smallest)
// {
// 	if ((*(stacks->b))->data == smallest)
// 	{
// 		push_a(stacks->a, stacks->b, ops);
// 		rotate_a(stacks->a, ops);
// 	}
// }
