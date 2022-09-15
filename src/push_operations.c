/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:44:46 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/09/15 17:59:06 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_node **stack_a, t_node **stack_b, t_operation **operations)
{
	int	data;

	if (*stack_b == NULL)
	{
		operation_append(operations, "pa");
		return ;
	}
	data = (*stack_b)->data;
	node_pop(stack_b);
	node_insert(stack_a, data);
	operation_append(operations, "pa");
}

void	push_b(t_node **stack_a, t_node **stack_b, t_operation **operations)
{
	int	data;

	if (*stack_a == NULL)
	{
		operation_append(operations, "pb");
		return ;
	}
	data = (*stack_a)->data;
	node_pop(stack_a);
	node_insert(stack_b, data);
	operation_append(operations, "pb");
}
