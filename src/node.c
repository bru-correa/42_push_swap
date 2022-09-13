/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 01:57:54 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/09/13 17:49:22 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_node	**node_append(t_node **start_node, int data)
{
	t_node	*last_node;
	t_node	*new_node;

	if (start_node == NULL)
		start_node = create_start_node();
	new_node = node_create(data);
	if (*start_node == NULL)
	{
		*start_node = new_node;
		return (start_node);
	}
	check_repeated_data(start_node, data);
	last_node = (*start_node)->prev;
	last_node->next = new_node;
	(*start_node)->prev = new_node;
	new_node->prev = last_node;
	new_node->next = *start_node;
	return (start_node);
}

t_node	**node_insert(t_node **start_node, int data)
{
	t_node	*last_node;

	// if (start_node == NULL)
	// 	return ;
	start_node = node_append(start_node, data);
	last_node = (*start_node)->prev;
	*start_node = last_node;
	return (start_node);
}

t_node	**node_pop(t_node **start_node)
{
	t_node	*second_node;
	t_node	*last_node;

	if (start_node == NULL || *start_node == NULL)
		return (start_node);
	if ((*start_node)->next == *start_node)
	{
		free(*start_node);
		*start_node = NULL;
		return (start_node);
	}
	second_node = (*start_node)->next;
	last_node = (*start_node)->prev;
	last_node->next = second_node;
	second_node->prev = last_node;
	free(*start_node);
	*start_node = second_node;
	return (start_node);
}

t_node	**node_clear(t_node **start_node)
{
	if (start_node == NULL)
		return (start_node);
	while (*start_node != NULL)
		node_pop(start_node);
	free(start_node);
	return (NULL);
}

int	node_count(t_node **start_node)
{
	t_node	*current_node;
	int		length;

	if (start_node == NULL || *start_node == NULL)
		return (0);
	length = 1;
	current_node = (*start_node)->next;
	while (current_node != *start_node)
	{
		length++;
		current_node = current_node->next;
	}
	return (length);
}

