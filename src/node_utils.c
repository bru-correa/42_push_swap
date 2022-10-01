/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:50:25 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/10/01 17:12:50 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_create(int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		exit_error("Could not allocate memory");
	node->data = data;
	node->next = node;
	node->prev = node;
	return (node);
}

t_node	**create_stack(void)
{
	t_node	**stack;

	stack = malloc(sizeof(t_node));
	if (stack == NULL)
		exit_error("Could not allocate memory");
	*stack = NULL;
	return (stack);
}

void	check_repeated_data(t_node **stack, int data)
{
	t_node	*current_node;

	current_node = *stack;
	if (current_node->data == data)
	{
		node_clear(stack);
		exit_error("The list contains repeated numbers");
	}
	current_node = current_node->next;
	while (current_node != *stack)
	{
		if (current_node->data == data)
		{
			node_clear(stack);
			exit_error("The list contains repeated numbers");
		}
		current_node = current_node->next;
	}
}

