/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 01:57:54 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/08/14 21:33:57 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO: Check if this is correct
t_node	*create_new_node(int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

// FIX: Not working, the linked_list must be circulular
void	add_node_back(t_node *node, int data)
{
	t_node	*current_node;

	current_node = node;
	while (current_node->next != node)
		current_node = node->next;
	current_node->data = data;
	current_node->next = node;
}
