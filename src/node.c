/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 01:57:54 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/10/05 19:18:00 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	node_append(t_node **stack, int data)
{
	t_node	*last_node;
	t_node	*new_node;

	if (stack == NULL)
		return ;
	new_node = node_create(data);
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last_node = (*stack)->prev;
	last_node->next = new_node;
	(*stack)->prev = new_node;
	new_node->prev = last_node;
	new_node->next = *stack;
}

void	node_insert(t_node **stack, int data)
{
	t_node	*last_node;

	if (stack == NULL)
		return ;
	node_append(stack, data);
	last_node = (*stack)->prev;
	*stack = last_node;
}

void	node_pop(t_node **stack)
{
	t_node	*second_node;
	t_node	*last_node;

	if (stack == NULL || *stack == NULL)
		return ;
	if ((*stack)->next == *stack)
	{
		free(*stack);
		*stack = NULL;
		return ;
	}
	second_node = (*stack)->next;
	last_node = (*stack)->prev;
	last_node->next = second_node;
	second_node->prev = last_node;
	free(*stack);
	*stack = second_node;
}

void	node_clear(t_node **stack)
{
	if (stack == NULL)
		return ;
	while (*stack != NULL)
		node_pop(stack);
}

int	node_count(t_node **stack)
{
	t_node	*current_node;
	int		length;

	if (stack == NULL || *stack == NULL)
		return (0);
	length = 1;
	current_node = (*stack)->next;
	while (current_node != *stack)
	{
		length++;
		current_node = current_node->next;
	}
	return (length);
}
