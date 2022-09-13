/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 01:54:18 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/09/13 18:07:51 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/********** INCLUDE **********/

# include "libft.h"

/********** STRUCTS **********/

/**
  The node list that will be used to implement the 'stack'
**/
typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/********** PROTOTYPES **********/

/**
  Alloc memory and create the head of the node list.
  The first element of the node list will be NULL.
**/
t_node	**create_start_node(void);

/**
  Alloc memory, create a new node with `data` and return it.
  The node next and prev properties will be the node itself
**/
t_node	*node_create(int data);

/**
  Create a node with `data` and add it at the end of the node list.
  If any node in the list already contains the same `data` value,
  the program will exit. If the list is empty, create a new list and return it
**/
t_node	**node_append(t_node **start_node, int data);

/**
  Create a node with `data` and add it at the start of the node list.
  If any node in the list already contains the same `data` value,
  the program will exit.
  The `start_node` will now point to the new node address.
  If the list is empty, create a new list and return it
**/
t_node	**node_insert(t_node **start_node, int data);

/**
  Remove the first node from the list and free its memory.
  `start_node` will now point to the next node.
  If the node list contains only one element, `start_node` will point to NULL
**/
t_node	**node_pop(t_node **start_node);

/**
  Free all the allocated nodes from the list, free start_node and return NULL
**/
t_node	**node_clear(t_node **start_node);

/**
  Return the length of the node list. If the list is empty returns 0
**/
int		node_count(t_node **start_node);

/**
  Check if `data` already exists in the node list
**/
void	check_repeated_data(t_node **start_node, int data);

#endif
