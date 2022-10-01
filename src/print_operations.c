/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:43:14 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/10/01 18:44:23 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operations(t_operation **ops)
{
	t_operation	*current_op;

	if (ops == NULL)
		return ;
	current_op = *ops;
	while (current_op != NULL)
	{
		ft_printf("%s\n", current_op->name);
		current_op = current_op->next;
	}
}
