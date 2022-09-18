/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_middle_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:31:53 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/09/18 04:54:39 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*get_values(t_node **stack, int stack_length);
static void	quick_sort(int *values, int left, int right);
static int	partition(int *values, int left, int right);
static int	get_pivot_index(int *values, int left, int right);
static void	swap_values(int *values, int a, int b);

// TODO: Remember to error check stack outside of this function call
int	find_middle_n(t_node **stack)
{
	int	middle_index;
	int	*values;
	int	stack_length;
	int	middle_n;

	stack_length = node_count(stack);
	middle_index = stack_length / 2;
	values = get_values(stack, stack_length);
	quick_sort(values, 0, stack_length - 1);
	middle_n = values[middle_index];
	free(values);
	return (middle_n);
}

// Copy the data from the stack to an array of integers
static int	*get_values(t_node **stack, int stack_length)
{
	int		*stack_data;
	t_node	*current_node;
	int		i;

	stack_data = malloc(sizeof(int) * stack_length);
	if (stack_data == NULL)
		exit_error("Could not allocate memory");
	current_node = *stack;
	i = 0;
	while (i < stack_length)
	{
		stack_data[i] = current_node->data;
		current_node = current_node->next;
		i++;
	}
	return (stack_data);
}

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
static void	quick_sort(int *values, int left, int right)
{
	int	i;

	if (left < right)
	{
		i = partition(values, left, right);
		quick_sort(values, left, i - 1);
		quick_sort(values, i + 1, right);
	}
}

/**
  Determine the pivot, that will be the point of division of the array,
  and then reorder its elements.
  The values that are smaller than the pivot will be at the left side,
  the larger ones will be at the right side,
  and the pivot will be in the middle, in the correct index
**/
static int	partition(int *values, int left, int right)
{
	int	i;
	int	j;
	int	pivot_index;
	int	pivot;

	pivot_index = get_pivot_index(values, left, right);
	swap_values(values, left, pivot_index);
	pivot = values[left];
	i = left;
	j = left + 1;
	while (j <= right)
	{
		if (values[j] <= pivot)
		{
			i +=1;
			swap_values(values, i, j);
		}
		j++;
	}
	swap_values(values, left, i);
	return (i);
}

/**
  Get the median between the first, the middle, and the last element,
  to increase the probability of getting a good pivot index for quick sort
**/
static int	get_pivot_index(int *values, int left, int right)
{
	int	mid;

	mid = (left + right) / 2;
	if (values[mid] > values[left] && values[mid] < values[right])
		return (mid);
	else if (values[mid] > values[right] && values[mid] < values[left])
		return (mid);
	else if (values[left] > values[mid] && values[left] < values[right])
		return (left);
	else if (values[left] > values[right] && values[left] < values[mid])
		return (left);
	else
		return (right);
}

static void	swap_values(int *values, int a, int b)
{
	int	temp;

	temp = values[a];
	values[a] = values[b];
	values[b] = temp;
}

