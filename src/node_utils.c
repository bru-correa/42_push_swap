/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:50:25 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/10/05 20:06:38 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_create(int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		exit_error();
	node->data = data;
	node->next = node;
	node->prev = node;
	return (node);
}

t_node	**create_stack(void)
{
	t_node	**stack;

	stack = malloc(sizeof(t_node));
	if (stack == NULL)
		exit_error();
	*stack = NULL;
	return (stack);
}
