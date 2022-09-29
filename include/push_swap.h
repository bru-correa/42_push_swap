/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 01:54:18 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/09/27 15:00:34 by bcorrea-         ###   ########.fr       */
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

typedef struct s_stacks
{
	t_node	**a;
	t_node	**b;
}	t_stacks;

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
void		operation_append(t_operation **ops, char *name);

/**
  Free all the elements of the list, free `operations` and return NULL
**/
void		operation_clear(t_operation **ops);

/**
  Swap the first two elements at the top of the `stack_a`,
  and store the operation in `operations`.
  If there's one or no elements in the list, just save the operation.
**/
void		swap_a(t_node **stack_a, t_operation **opss);

/**
  Swap the first two elements at the top of the `stack_b`,
  and store the operation in `operations`.
  If there's one or no elements in the list, just save the operation.
**/
void		swap_b(t_node **stack_b, t_operation **ops);

/**
  Swap the first two elements at the top of `stack_a` and `stack_b`,
  and store the operation in `operations`.
  If there's one or no elements in the list, just save the operation.
**/
void		swap_both(t_node **stack_a, t_node **stack_b,
				t_operation **ops);

/**
  Take the first element at the top of `stack_b`
  and put it at the top of `stack_a`.
  If there's one or no elements in the list, just save the operation.
**/
void		push_a(t_node **stack_a, t_node **stack_b,
				t_operation **ops);

/**
  Take the first element at the top of `stack_a`
  and put it at the top of `stack_b`.
  If there's one or no elements in the list, just save the operation.
**/
void		push_b(t_node **stack_a, t_node **stack_b,
				t_operation **ops);

/**
  Shift up all elements of `stack_a` by 1.
  The first element becomes the last one.
  If `stack_a` is empty, just save the operation.
**/
void		rotate_a(t_node **stack_a, t_operation **ops);

/**
  Shift up all elements of `stack_b` by 1.
  The first element becomes the last one.
  If `stack_b` is empty, just save the operation.
**/
void		rotate_b(t_node **stack_b, t_operation **ops);

/**
  Shift up all elements of `stack_a` and `stack_b` by 1.
  The first element becomes the last one.
  If `stack_a` and `stack_b` is empty, just save the operation.
  If one is empty and the other is not, rotate the non empty one.
**/
void		rotate_both(t_node **stack_a, t_node **stack_b,
			t_operation **ops);

/**
  Shift down all elements of `stack_a` by 1.
  The last element becomes the first one.
  If `stack_a` is empty, just save the operation.
**/
void		rev_rotate_a(t_node **stack_a, t_operation **ops);

/**
  Shift down all elements of `stack_b` by 1.
  The last element becomes the first one.
  If `stack_b` is empty, just save the operation.
**/
void		rev_rotate_b(t_node **stack_b, t_operation **ops);

/**
  Shift down all elements of `stack_a` and `stack_b` by 1.
  The last element becomes the first one.
  If the `stack_a` and `stack_b` are empty, just save the operation.
  If one is empty and the other is not, rotate the non empty one.
**/
void		rev_rotate_both(t_node **stack_a, t_node **stack_b,
			t_operation **ops);

/**
  Get the middle number of the stack by using the quick sort algorithm
**/
int			find_median(t_node **stack);

void		split_sort(t_node **stack_a, t_node **stack_b,
				t_operation **ops);

t_stacks	*create_stacks_from_args(char **argv);

int			is_sorted(t_node **stack_a);

int			find_smallest_number(t_node **stack);

void		sort_b(t_stacks *stacks, t_operation **ops, int split_count);

int			split_b(t_stacks *stacks, t_operation **ops);

void		split_sort2(t_stacks *stacks, t_operation **ops);

// PROVISORY

void		test_operations(void);
void		print_operations(t_operation **operations);
void		print_stack(t_node **stack, char *stack_name);
void		test_swap(t_node **stack_a, t_node **stack_b);
void		test_push(t_node **stack_a, t_node **stack_b);
void		test_rotate(t_node **stack_a, t_node **stack_b);

#endif
