/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:22:59 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/09/15 04:09:47 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_operations(t_operation **operations);

void	test_operations(void)
{
	t_operation	**operations;

	operations = NULL;
	operation_append(operations, "pa\n");
	operation_append(operations, "pb\n");
	operation_append(operations, "rrr\n");
	print_operations(operations);
	operation_clear(operations);
	print_operations(operations);
}

void	test_swap(t_node **stack_a, t_node **stack_b)
{
	t_operation	**operations;

	operations = NULL;
	swap_a(stack_a, operations);
	swap_b(stack_b, operations);
	print_operations(operations);
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");
	swap_both(stack_a, stack_b, operations);
	print_operations(operations);
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");
	operation_clear(operations);
	free(operations);
}

static void	print_operations(t_operation **operations)
{
	t_operation	*current_op;

	if (operations == NULL)
		return ;
	current_op = *operations;
	while (current_op != NULL)
	{
		ft_printf("%s", current_op->name);
		current_op = current_op->next;
	}
}
