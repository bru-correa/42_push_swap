/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bcorrea->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:57:55 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/10/01 22:07:42 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(const char c);
static long	get_result(const char *str, int sign);
static void	check_overflow(long result, int sign);

int	convert_to_int(const char *str)
{
	int		sign;
	long	result;
	int		i;

	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	result = get_result(&str[i], sign);
	return (result * sign);
}

static int	ft_isspace(const char c)
{
	if ((c >= '\t' && c <= '\r') || (c == ' '))
		return (1);
	return (0);
}

static long	get_result(const char *str, int sign)
{
	long	result;
	int		current_decimal;
	int		i;

	result = 0;
	i = 0;
	while (ft_isdigit(str[i]) != '\0')
	{
		current_decimal = (int)(str[i] - '0');
		result = result * 10 + current_decimal;
		check_overflow(result, sign);
		i++;
	}
	return (result);
}

static void	check_overflow(long result, int sign)
{
	if (sign > 0 && result > INT_MAX)
		exit_error();
	else if (sign < 0 && result * sign < INT_MIN)
		exit_error();
}
