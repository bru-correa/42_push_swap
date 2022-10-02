/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:31:53 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/10/01 22:14:14 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*get_values(t_node **stack, int stack_length);

int	find_median(t_node **stack)
{
	int	median_index;
	int	*values;
	int	stack_length;
	int	median;

	stack_length = node_count(stack);
	median_index = stack_length / 2;
	values = get_values(stack, stack_length);
	quick_sort(values, 0, stack_length - 1);
	median = values[median_index];
	free(values);
	return (median);
}

// Copy the data from the stack to an array of integers
static int	*get_values(t_node **stack, int stack_length)
{
	int		*stack_data;
	t_node	*current_node;
	int		i;

	stack_data = malloc(sizeof(int) * stack_length);
	if (stack_data == NULL)
		exit_error();
	current_node = *stack;
	i = 0;
	while (i < stack_length)
	{
		stack_data[i] = current_node->data;
		current_node = current_node->next;
		i++;
	}
	return (stack_data);
}
