/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:43:07 by acosi             #+#    #+#             */
/*   Updated: 2023/05/20 08:00:40 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Free an entire array of strings.

int	free_array(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	return (0);
}

// Display an error mesage and exit the program, 
// for clean and convenient error handling.

void	exit_error(void)
{
	ft_putendl_fd("Error", 1);
	exit(0);
}

// Count how many numbers are sent to the program when the argument
// is a string under quotations "..."

int	count_args(char **argv)
{
	int		i;
	char	**args;

	args = ft_split(argv[1], ' ');
	i = 0;
	while (args[i] != NULL)
		i++;
	free_array (args);
	return (i);
}
