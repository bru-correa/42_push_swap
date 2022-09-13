/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:24:49 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/09/13 17:57:52 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

void	print_stack(t_node **start_node);
t_node	**create_stack(char **argv);
int		ft_is_number(char *str);

int	main(int argc, char *argv[])
{
	t_node	**start_node;

	if (argc == 0)
		return (0);
	start_node = create_stack(argv);
	print_stack(start_node);
	return (0);
}

// `i` starts at 1 to ignore the first arg
t_node	**create_stack(char **argv)
{
	t_node	**start_node;
	int		i;
	int		number;

	start_node = NULL;
	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_is_number(argv[i]) == TRUE)
		{
			number = ft_atoi(argv[i]);
			start_node = node_append(start_node, number);
		}
		else
		{
			ft_putstr_fd("Error\nInvalid arguments\n", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (start_node);
}

/**
  Check if `str` is an integer.
  It does not check if the number is larger than max int
  or smaller than min int.
  Return 0 if false and 1 if true
**/
int	ft_is_number(char *str)
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

void	print_stack(t_node **start_node)
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
