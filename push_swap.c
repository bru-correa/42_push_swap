/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:24:49 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/10/05 17:26:46 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_stacks *stacks, t_operation **ops);

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;
	t_operation	**ops;

	if (argc <= 1)
		return (0);
	stacks = create_stacks_from_args(argv);
	if (is_sorted(stacks->a) == TRUE)
	{
		free_stacks(stacks);
		return (0);
	}
	ops = create_operations();
	sort(stacks, ops);
	print_operations(ops);
	free_all(stacks, ops);
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
