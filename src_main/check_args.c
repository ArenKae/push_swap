/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:30:39 by acosi             #+#    #+#             */
/*   Updated: 2025/03/20 07:29:05 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Check if the argument is a number.

bool	is_num(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (false);
		i++;
	}
	return (true);
}

// Check for overflow values.

bool	is_overflow(long tmp, char *arg)
{
	if (tmp > INT_MAX || tmp < INT_MIN)
		return (true);
	if (arg[0] == '-' && ft_strlen(arg) > 11)
		return (true);
	if (arg[0] != '-' && ft_strlen(arg) > 10)
		return (true);
	return (false);
}

// Check for duplicates among all arguments.

bool	duplicates(int tmp, char **args, int i)
{
	i++;
	while (args[i])
	{
		if (ft_atoi(args[i]) == tmp)
			return (true);
		i++;
	}
	return (false);
}

// Parse the arguments and check if there are only numbers, and if
// there are no duplicates. The first if conditon allows double quote parsing :
// since the arguments inside the "..." are treated as a single string,
// ft_split is used to format it as an array without spaces.
// i needs to start at 1 when argv is not pre-formated by ft_split in order
// to skip argv[0] which is the name of th program.

void	check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (is_num(args[i]) == false || is_overflow(tmp, args[i]) == true
			|| duplicates(tmp, args, i) == true)
		{
			if (argc == 2)
				free_array(args);
			exit_error();
		}
		i++;
	}
	if (argc == 2)
		free_array(args);
}

// Check if the arguments are already sorted.

bool	is_sorted(int argc, char **argv)
{
	int		i;
	char	**args;
	bool	ret;

	i = 0;
	ret = true;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i] && args[i + 1] != NULL)
	{
		if (ft_atoi(args[i]) > ft_atoi(args[i + 1]))
		{
			ret = false;
			break ;
		}
		i++;
	}
	if (argc == 2)
		free_array(args);
	return (ret);
}
