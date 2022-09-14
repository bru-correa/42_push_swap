/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:24:49 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/09/14 19:38:47 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		print_stack(t_node **start_node);
static t_node	**create_stack(char **argv);
static int		ft_is_number(char *str);
static t_node	**add_arg_to_stack(t_node **stack, char *arg);

int	main(int argc, char *argv[])
{
	t_node			**stack_a;

	if (argc <= 1)
		return (0);
	stack_a = create_stack(argv);
	if (node_count(stack_a) == 1)
		return (0);
	print_stack(stack_a);
	stack_a = node_clear(stack_a);
	test_operations();
	return (0);
}

// `i` starts at 1 to ignore the first arg
static t_node	**create_stack(char **argv)
{
	t_node	**stack;
	int		i;

	stack = NULL;
	i = 1;
	while (argv[i] != NULL)
	{
		stack = add_arg_to_stack(stack, argv[i]);
		i++;
	}
	return (stack);
}

static t_node	**add_arg_to_stack(t_node **stack, char *arg)
{
	int	number;

	if (ft_is_number(arg) == TRUE)
	{
		number = convert_to_int(arg);
		stack = node_append(stack, number);
	}
	else
		exit_error("Invalid arguments");
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

static void	print_stack(t_node **start_node)
{
	t_node	*current_node;

	if (start_node == NULL)
	{
		ft_printf("The stack is empty\n");
		return ;
	}
	ft_printf("Stack A:\n");
	current_node = (*start_node);
	ft_printf("%d\n", current_node->data);
	current_node = current_node->next;
	while (current_node != *start_node)
	{
		ft_printf("%d\n", current_node->data);
		current_node = current_node->next;
	}
}
