/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 01:54:18 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/09/15 17:41:29 by bcorrea-         ###   ########.fr       */
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
t_node		**create_stack(void);

/**
  Alloc memory, create a new node with `data` and return it.
  The node next and prev properties will be the node itself
**/
t_node		*node_create(int data);

/**
  Create a node with `data` and add it at the end of the stack.
  If any node in the list already contains the same `data` value,
  the program will exit.
**/
void		node_append(t_node **stack, int data);

/**
  Create a node with `data` and add it at the start of the stack.
  If any node in the list already contains the same `data` value,
  the program will exit.
  The `stack` will now point to the new node address.
**/
void		node_insert(t_node **stack, int data);

/**
  Remove the first node from the stack and free its memory.
  `stack` will now point to the next node.
  If the stack contains only one element, `stack` will point to NULL
**/
void		node_pop(t_node **stack);

/**
  Free all the allocated nodes from the stack
**/
void		node_clear(t_node **stack);

/**
  Return the length of the stack. If the list is empty returns 0
**/
int			node_count(t_node **stack);

/**
  Check if `data` already exists in the stack
**/
void		check_repeated_data(t_node **stack, int data);

/**
  Print Error\n and `msg` to stderr and exit
**/
void		exit_error(char *msg);

/**
  Alloc memory and create the operations list. The first element is NULL
**/
t_operation	**create_operations(void);

/**
  Alloc memory, create a new operation with `name` and return it.
  The node next property will be the NULL
**/
t_operation	*operation_create(char *name);

/**
  Create an operation with `name` and add it at the end of the list.
**/
void		operation_append(t_operation **operations, char *name);

/**
  Free all the elements of the list, free `operations` and return NULL
**/
void		operation_clear(t_operation **operations);

/**
  Swap the first two elements at the top of the Stack A,
  and store the operation in `operations`.
  If there's one or no elements in the list, just save the operation.
**/
void		swap_a(t_node **stack_a, t_operation **operations);

/**
  Swap the first two elements at the top of the Stack B,
  and store the operation in `operations`.
  If there's one or no elements in the list, just save the operation.
**/
void		swap_b(t_node **stack_b, t_operation **operations);

/**
  Swap the first two elements at the top of Stack A and Stack B,
  and store the operation in `operations`.
  If there's one or no elements in the list, just save the operation.
**/
void		swap_both(t_node **stack_a, t_node **stack_b,
				t_operation **operations);

void		test_operations(void);
void		print_stack(t_node **stack, char *stack_name);
void		test_swap(t_node **stack_a, t_node **stack_b);

#endif
