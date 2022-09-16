/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:22:59 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/09/16 19:21:47 by bcorrea-         ###   ########.fr       */
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

	operations = create_operations();
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

void	test_push(t_node **stack_a, t_node **stack_b)
{
	t_operation	**operations;

	operations = create_operations();
	ft_printf("Push A\n");
	push_a(stack_a, stack_b, operations);
	print_operations(operations);
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");
	ft_printf("Push B\n");
	push_b(stack_a, stack_b, operations);
	push_b(stack_a, stack_b, operations);
	push_b(stack_a, stack_b, operations);
	push_b(stack_a, stack_b, operations);
	push_b(stack_a, stack_b, operations);
	push_b(stack_a, stack_b, operations);
	print_operations(operations);
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");
	operation_clear(operations);
	free(operations);
}

void	test_rotate(t_node **stack_a, t_node **stack_b)
{
	t_operation	**operations;

	operations = create_operations();
	ft_printf("Rotate A\n");
	rotate_a(stack_a, operations);
	print_stack(stack_a, "A");
	ft_printf("Rotate B\n");
	rotate_b(stack_b, operations);
	print_stack(stack_b, "B");
	ft_printf("Rotate Both\n");
	rotate_both(stack_a, stack_b, operations);
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");
	ft_printf("Reverse Rotate A\n");
	rev_rotate_a(stack_a, operations);
	print_stack(stack_a, "A");
	ft_printf("Reverse Rotate B\n");
	rev_rotate_b(stack_b, operations);
	print_stack(stack_b, "B");
	ft_printf("Reverse Rotate Both\n");
	rev_rotate_both(stack_a, stack_b, operations);
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");
	print_operations(operations);
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
		ft_printf("%s\n", current_op->name);
		current_op = current_op->next;
	}
}
