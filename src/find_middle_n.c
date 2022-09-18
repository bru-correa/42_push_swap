/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_middle_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:31:53 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/09/18 04:05:15 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*get_values(t_node **stack, int stack_length);
// static int	get_middle_n(int *stack_data, int stack_length, int middle_index);
static void	quick_sort(int *values, int left, int right);
static int	partition(int *values, int left, int right);
static int	get_pivot_index(int *values, int left, int right);
static void	swap_values(int *values, int a, int b);
static void	print_values(int *values, int length);

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
	print_values(values, stack_length);
	// middle_n = get_middle_n(stack_data, stack_length, middle_index);
	free(values);
	return (middle_n);
}

static void	print_values(int *values, int length)
{
	int	i;

	ft_printf("Values:\n");
	i = 0;
	while (i < length)
	{
		ft_printf("%d\n", values[i]);
		i++;
	}
}

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

// static int	get_middle_n(int *stack_data, int stack_length, int middle_index)
// {
// 	int	i;
//
// 	i = 0;
// 	while (i != middle_index)
// 	{
// 		if (i < middle_index)
// 		{
// 			i = partition(stack_data, i + 1, stack_length);
// 		}
// 		else if (i > middle_index)
// 		{
// 			i = partition(stack_data, i - 1, 0);
// 		}
// 	}
// 	return (stack_data[i]);
// }

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

static void	swap_values(int *values, int a, int b)
{
	int	temp;

	temp = values[a];
	values[a] = values[b];
	values[b] = temp;
}

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

