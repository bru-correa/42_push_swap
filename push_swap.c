/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:24:49 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/09/28 21:26:48 by bcorrea-         ###   ########.fr       */
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
	// split_sort(stack_a, stack_b, ops);
	// split_sort2(stacks, ops);
	// print_stack(stacks->a, "A");
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
		sort_two();
	else if (length <= 5)
		small_sort();
	else
		split_sort2(stacks, ops);
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

void	print_stack(t_node **stack, char *stack_name)
{
	t_node	*current_node;

	if (*stack == NULL)
	{
		ft_printf("The stack %s is empty\n", stack_name);
		return ;
	}
	ft_printf("Stack %s:\n", stack_name);
	current_node = *stack;
	ft_printf("%d\n", current_node->data);
	current_node = current_node->next;
	while (current_node != *stack)
	{
		ft_printf("%d\n", current_node->data);
		current_node = current_node->next;
	}
}
