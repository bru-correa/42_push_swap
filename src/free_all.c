/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:10:40 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/10/05 17:24:16 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stacks *stacks, t_operation **ops)
{
	free_stacks(stacks);
	free_ops(ops);
}

void	free_stacks(t_stacks *stacks)
{
	node_clear(stacks->a);
	free(stacks->a);
	node_clear(stacks->b);
	free(stacks->b);
	free(stacks);
}

void	free_ops(t_operation **ops)
{
	operation_clear(ops);
	free(ops);
}
