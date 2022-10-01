/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:52:43 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/10/01 17:10:26 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node **stack_a)
{
	t_node	*current_node;
	int		length;

	length = node_count(stack_a);
	if (length <= 1)
		return (TRUE);
	current_node = *stack_a;
	while (length > 1)
	{
		if (current_node->data > current_node->next->data)
			return (FALSE);
		current_node = current_node->next;
		length--;
	}
	return (TRUE);
}

int	find_smallest_number(t_node **stack)
{
	int		smallest_n;
	t_node	*current_node;

	smallest_n = (*stack)->data;
	current_node = (*stack)->next;
	while (current_node != *stack)
	{
		if (current_node->data < smallest_n)
			smallest_n = current_node->data;
		current_node = current_node->next;
	}
	return (smallest_n);
}

// WARNING: Break if stack is empty, check if it's empty before calling this!
int	find_largest_number(t_node **stack)
{
	t_node	*current_node;
	int		largest;

	current_node = *stack;
	largest = current_node->data;
	current_node = current_node->next;
	while (current_node != *stack)
	{
		if (current_node->data > largest)
			largest = current_node->data;
		current_node = current_node->next;
	}
	return (largest);
}

