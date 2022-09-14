/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 01:54:18 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/09/14 19:11:59 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/********** INCLUDE **********/

# include "libft.h"
# include <stdlib.h>

/********** MACROS **********/

# define INT_MAX 2147483647
# define INT_MIN -2147483648

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

/**
  The list of push_swap operations to be printed
**/
typedef struct s_operation
{
	struct s_operation	*next;
	char				*name;
}	t_operation;

/********** PROTOTYPES **********/

/**
  Convert `str` to an integer number.
  If the number is larger than int limits, exit the program
**/
int			convert_to_int(const char *str);

/**
  Alloc memory and create the head of the node list.
  The first element of the node list will be NULL.
**/
t_node		**create_start_node(void);

/**
  Alloc memory, create a new node with `data` and return it.
  The node next and prev properties will be the node itself
**/
t_node		*node_create(int data);

/**
  Create a node with `data` and add it at the end of the node list.
  If any node in the list already contains the same `data` value,
  the program will exit. If the list is empty, create a new list and return it
**/
t_node		**node_append(t_node **start_node, int data);

/**
  Create a node with `data` and add it at the start of the node list.
  If any node in the list already contains the same `data` value,
  the program will exit.
  The `start_node` will now point to the new node address.
  If the list is empty, create a new list and return it
**/
t_node		**node_insert(t_node **start_node, int data);

/**
  Remove the first node from the list and free its memory.
  `start_node` will now point to the next node.
  If the node list contains only one element, `start_node` will point to NULL
**/
t_node		**node_pop(t_node **start_node);

/**
  Free all the allocated nodes from the list, free start_node and return NULL
**/
t_node		**node_clear(t_node **start_node);

/**
  Return the length of the node list. If the list is empty returns 0
**/
int			node_count(t_node **start_node);

/**
  Check if `data` already exists in the node list
**/
void		check_repeated_data(t_node **start_node, int data);

/**
  Print Error\n and `msg` to stderr and exit
**/
void		exit_error(char *msg);

/**
  Alloc memory, create a new operation with `name` and return it.
  The node next property will be the NULL
**/
t_operation	*operation_create(char *name);

/**
  Create an operation with `name` and add it at the end of the list.
  If `operations` is NULL, alloc memory and create a new `operations`
**/
t_operation	**operation_append(t_operation **operations, char *name);

/**
  Free all the elements of the list, free `operations` and return NULL
**/
t_operation	**operation_clear(t_operation **operations);

void		test_operations(void);

#endif
