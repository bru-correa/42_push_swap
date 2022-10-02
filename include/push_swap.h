/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 01:54:18 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/10/01 22:41:40 by bcorrea-         ###   ########.fr       */
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
  Print Error\n and exit
**/
void		exit_error(void);

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
void		swap_a(t_node **stack_a, t_operation **ops);

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
  Sort the values array by using the "divide and conquer" logic.
  It recursively divides the array in two sides,
  the values that are smaller than the pivot will be at the left side,
  the values that are larger than the pivot will be at the right side,
  and the pivot value will be between the two, in the correct index.
  The pivot is defined by the partition function.
  `left` is the start index.
  `right` is the end index.
**/
void		quick_sort(int *values, int left, int right);

/**
  Get the middle number of the stack by using the quick sort algorithm
**/
int			find_median(t_node **stack);

/**
  Read `argv` and create Stack A and Stack B
**/
t_stacks	*create_stacks_from_args(char **argv);

int			is_sorted(t_node **stack_a);

int			find_smallest_number(t_node **stack);

int			find_largest_number(t_node **stack);

void		print_operations(t_operation **operations);

/********* MAIN SORTING **********/

/**
  Divide Stack B recursively until it only contains 3 or less elements,
  then sort them by pushing the smallest to the bottom of Stack A.
  If Stack A is empty, get `split_count` elements from Stack A.
**/
void		sort_b(t_stacks *stacks, t_operation **ops, int split_count);

/**
  Get the median of Stack B,
  then send the elements larger than the median to the top of Stack A.
  Returns the amount of elements sent to Stack A.
**/
int			split_b(t_stacks *stacks, t_operation **ops);

/**
  Get the median of Stack A, then split the array in half.
  Push the smaller half to Stack B and then sort it back to Stack A.
  Then, push the larger half to Stack B and then sort it back to Stack A.
**/
void		split_sort(t_stacks *stacks, t_operation **ops);

/********** SMALL SORTING **********/

void		sort_two(t_stacks *stacks, t_operation **ops);

void		sort_three(t_node **stack_a, t_operation **ops);

void		sort_five(t_stacks *stacks, t_operation **ops);

#endif
