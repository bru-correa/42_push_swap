/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:13:16 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/10/01 22:15:37 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition(int *values, int left, int right);
static int	get_pivot_index(int *values, int left, int right);
static void	swap_values(int *values, int a, int b);

void	quick_sort(int *values, int left, int right)
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
			i += 1;
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
