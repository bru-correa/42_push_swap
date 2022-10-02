/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:11:12 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/10/01 22:09:33 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stacks *stacks, t_operation **ops)
{
	t_node	*first_node;
	t_node	*second_node;

	first_node = (*stacks->a);
	second_node = (*stacks->a)->next;
	if (first_node->data > second_node->data)
		swap_a(stacks->a, ops);
}
