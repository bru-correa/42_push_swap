/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:47:22 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/09/24 15:47:26 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	**add_arg_to_stack(t_node **stack, char *arg);
static int		ft_is_number(char *str);

// `i` starts at 1 to ignore the first arg
t_stacks	*create_stacks_from_args(char **argv)
{
	t_stacks	*stacks;
	int			i;

	stacks = malloc(sizeof(t_stacks));
	if (stacks == NULL)
		exit_error("Could not allocate memory");
	stacks->a = create_stack();
	i = 1;
	while (argv[i] != NULL)
	{
		stacks->a = add_arg_to_stack(stacks->a, argv[i]);
		i++;
	}
	stacks->b = create_stack();
	return (stacks);
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
