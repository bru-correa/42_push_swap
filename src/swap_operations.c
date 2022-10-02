/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:57:32 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/10/01 22:38:33 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **stack);

void	swap_a(t_node **stack_a, t_operation **operations)
{
	swap(stack_a);
	operation_append(operations, "sa");
}

void	swap_b(t_node **stack_b, t_operation **operations)
{
	swap(stack_b);
	operation_append(operations, "sb");
}

void	swap_both(t_node **stack_a, t_node **stack_b, t_operation **operations)
{
	swap(stack_a);
	swap(stack_b);
	operation_append(operations, "ss");
}

static void	swap(t_node **stack)
{
	t_node	*first_node;
	t_node	*second_node;
	int		temp_data;

	if (stack == NULL)
	{
		exit_error();
		return ;
	}
	if (*stack == (*stack)->next)
		return ;
	first_node = *stack;
	second_node = (*stack)->next;
	temp_data = first_node->data;
	first_node->data = second_node->data;
	second_node->data = temp_data;
}
