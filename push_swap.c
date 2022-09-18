/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:24:49 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/09/18 03:46:49 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	**create_stack_from_args(char **argv);
static int		ft_is_number(char *str);
static t_node	**add_arg_to_stack(t_node **stack, char *arg);

int	main(int argc, char *argv[])
{
	t_node	**stack_a;
	t_node	**stack_b;

	if (argc <= 1)
		return (0);
	stack_a = create_stack_from_args(argv);
	if (node_count(stack_a) == 1)
		return (0);
	stack_b = create_stack();
	// print_stack(stack_a, "A");
	// node_append(stack_b, 20);
	// node_append(stack_b, 30);
	// print_stack(stack_b, "B");
	// test_swap(stack_a, stack_b);
	// test_push(stack_a, stack_b);
	// test_rotate(stack_a, stack_b);
	ft_printf("Middle Number: %d\n", find_middle_n(stack_a));
	node_clear(stack_a);
	free(stack_a);
	node_clear(stack_b);
	free(stack_b);
	return (0);
}

// `i` starts at 1 to ignore the first arg
static t_node	**create_stack_from_args(char **argv)
{
	t_node	**stack;
	int		i;

	stack = create_stack();
	i = 1;
	while (argv[i] != NULL)
	{
		stack = add_arg_to_stack(stack, argv[i]);
		i++;
	}
	return (stack);
}

// TODO: Fix memory leak when exit_error in operations
static t_node	**add_arg_to_stack(t_node **stack, char *arg)
{
	int	number;

	if (ft_is_number(arg) == TRUE)
	{
		number = convert_to_int(arg);
		node_append(stack, number);
	}
	else
	{
		node_clear(stack);
		free(stack);
		exit_error("Invalid arguments");
	}
	return (stack);
}

/**
  Check if `str` is an integer.
  It does not check if the number is larger than max int
  or smaller than min int.
  Return 0 if false and 1 if true
**/
static int	ft_is_number(char *str)
{
	if (str == NULL)
		return (FALSE);
	else if (*str == '-')
		str++;
	while (*str != '\0')
	{
		if (ft_isdigit(*str) == FALSE)
			return (FALSE);
		str++;
	}
	return (TRUE);
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
