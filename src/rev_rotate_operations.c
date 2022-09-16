/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:46:06 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/09/16 19:00:44 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_node **stack_a, t_operation **operations)
{
	if (stack_a == NULL || *stack_a == NULL)
		return ;
	*stack_a = (*stack_a)->prev;
	operation_append(operations, "rra");
}

void	rev_rotate_b(t_node **stack_b, t_operation **operations)
{
	if (stack_b == NULL || *stack_b == NULL)
		return ;
	*stack_b = (*stack_b)->prev;
	operation_append(operations, "rrb");
}

void	rev_rotate_both(t_node **stack_a, t_node **stack_b,
		t_operation **operations)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (*stack_a != NULL)
		*stack_a = (*stack_a)->prev;
	if (*stack_b != NULL)
		*stack_b = (*stack_b)->prev;
	operation_append(operations, "rrr");
}
