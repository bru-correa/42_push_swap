/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:24:49 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/10/01 22:06:43 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_stacks *stacks, t_operation **ops);
static void	free_lists(t_stacks *stacks, t_operation **ops);

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;
	t_operation	**ops;

	if (argc <= 1)
		return (0);
	stacks = create_stacks_from_args(argv);
	if (is_sorted(stacks->a) == TRUE)
		return (0);
	ops = create_operations();
	sort(stacks, ops);
	print_operations(ops);
	free_lists(stacks, ops);
	return (0);
}

static void	sort(t_stacks *stacks, t_operation **ops)
{
	int	length;

	length = node_count(stacks->a);
	if (length == 1)
		return ;
	else if (length == 2)
		sort_two(stacks, ops);
	else if (length == 3)
		sort_three(stacks->a, ops);
	else if (length <= 5)
		sort_five(stacks, ops);
	else
		split_sort(stacks, ops);
}

static void	free_lists(t_stacks *stacks, t_operation **ops)
{
	node_clear(stacks->a);
	free(stacks->a);
	node_clear(stacks->b);
	free(stacks->b);
	free(stacks);
	operation_clear(ops);
	free(ops);
}
