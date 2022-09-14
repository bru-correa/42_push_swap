/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 01:45:22 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/09/14 19:40:16 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_operation	*operation_create(char *name)
{
	t_operation	*operation;

	operation = malloc(sizeof(t_operation));
	if (operation == NULL)
		exit_error("Could not allocate memory");
	operation->name = name;
	operation->next = NULL;
	return (operation);
}

t_operation	**operation_append(t_operation **operations, char *name)
{
	t_operation	*current_op;
	t_operation	*new_op;

	if (operations == NULL)
	{
		operations = malloc(sizeof(t_operation));
		if (operations == NULL)
			exit_error("Could not allocate memory");
		*operations = NULL;
	}
	new_op = operation_create(name);
	if (*operations == NULL)
	{
		*operations = new_op;
		return (operations);
	}
	current_op = *operations;
	while (current_op->next != NULL)
		current_op = current_op->next;
	current_op->next = new_op;
	return (operations);
}

t_operation	**operation_clear(t_operation **operations)
{
	t_operation	*current_op;
	t_operation	*last_op;

	if (operations == NULL)
		return (operations);
	else if (*operations == NULL)
	{
		free(operations);
		return (NULL);
	}
	current_op = *operations;
	while (current_op != NULL)
	{
		last_op = current_op;
		current_op = current_op->next;
		free(last_op);
	}
	free(operations);
	return (NULL);
}


