/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:47:22 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/10/05 20:03:31 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	**add_arg_to_stack_a(t_stacks *stacks, char *arg);
static int		ft_is_number(char *str);
static void		check_repeated_data(t_stacks *stacks, int data);

// `i` starts at 1 to ignore the first arg
t_stacks	*create_stacks_from_args(char **argv)
{
	t_stacks	*stacks;
	int			i;

	stacks = malloc(sizeof(t_stacks));
	if (stacks == NULL)
		exit_error();
	stacks->a = create_stack();
	stacks->b = create_stack();
	i = 1;
	while (argv[i] != NULL)
	{
		stacks->a = add_arg_to_stack_a(stacks, argv[i]);
		i++;
	}
	return (stacks);
}

static t_node	**add_arg_to_stack_a(t_stacks *stacks, char *arg)
{
	int	number;

	if (ft_is_number(arg) == TRUE)
	{
		number = convert_to_int(arg);
		node_append(stacks->a, number);
		check_repeated_data(stacks, number);
	}
	else
	{
		free_stacks(stacks);
		exit_error();
	}
	return (stacks->a);
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

static void	check_repeated_data(t_stacks *stacks, int data)
{
	t_node	*current_node;

	if (*stacks->a == (*stacks->a)->prev)
		return ;
	current_node = *stacks->a;
	while (current_node != (*stacks->a)->prev)
	{
		if (current_node->data == data)
		{
			free_stacks(stacks);
			exit_error();
		}
		current_node = current_node->next;
	}
}
