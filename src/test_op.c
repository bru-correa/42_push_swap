/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:22:59 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/09/14 19:11:17 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_operations(t_operation **operations);

void	test_operations(void)
{
	t_operation	**operations;

	operations = NULL;
	operations = operation_append(operations, "pa\n");
	operations = operation_append(operations, "pb\n");
	operations = operation_append(operations, "rrr\n");
	print_operations(operations);
	operations = operation_clear(operations);
	print_operations(operations);
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
