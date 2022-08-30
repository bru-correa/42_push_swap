/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:50:25 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/08/29 16:50:30 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_create(int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
	{
		ft_putstr_fd("Error\n Could not allocate memory\n", 2);
		exit(EXIT_FAILURE);
	}
	node->data = data;
	node->next = node;
	node->prev = node;
	return (node);
}

void	check_repeated_data(t_node **start_node, int data)
{
	t_node	*current_node;

	current_node = *start_node;
	if (current_node->data == data)
	{
		node_clear(start_node);
		ft_putstr_fd("Error\n The list contains repeated numbers\n", 2);
		exit(EXIT_FAILURE);
	}
	current_node = current_node->next;
	while (current_node != *start_node)
	{
		if (current_node->data == data)
		{
			node_clear(start_node);
			ft_putstr_fd("Error\n The list contains repeated numbers\n", 2);
			exit(EXIT_FAILURE);
		}
		current_node = current_node->next;
	}
}

