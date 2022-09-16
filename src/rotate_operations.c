/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:25:52 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/09/16 19:01:55 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_node **stack_a, t_operation **operations)
{
	if (stack_a == NULL || *stack_a == NULL)
		return ;
	*stack_a = (*stack_a)->next;
	operation_append(operations, "ra");
}

void	rotate_b(t_node **stack_b, t_operation **operations)
{
	if (stack_b == NULL || *stack_b == NULL)
		return ;
	*stack_b = (*stack_b)->next;
	operation_append(operations, "rb");
}

void	rotate_both(t_node **stack_a, t_node **stack_b,
		t_operation **operations)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (*stack_a != NULL)
		*stack_a = (*stack_a)->next;
	if (*stack_b != NULL)
		*stack_b = (*stack_b)->next;
	operation_append(operations, "rr");
}
