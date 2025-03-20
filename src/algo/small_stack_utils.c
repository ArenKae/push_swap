/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:31:05 by acosi             #+#    #+#             */
/*   Updated: 2025/03/20 21:41:43 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* Parse stack_a to find the biggest/lowest number on the list. The value of
the result is stored in the 2nd argument of the function via a pointer. The
function returns the position of the result to handle instructions more
efficiently, depending on if the result is closer to the start or the end 
of the list. */

int	find_lowest(t_stack *stack_a, int *lowest)
{
	t_node	*tmp;
	t_node	*check_position;
	int		position;

	tmp = stack_a->first;
	check_position = stack_a->first;
	*lowest = tmp->value;
	position = 0;
	while (tmp->next)
	{
		if (tmp->value < *lowest)
			*lowest = tmp->value;
		tmp = tmp->next;
	}
	if (tmp->value < *lowest)
		*lowest = tmp->value;
	while (check_position->next)
	{
		if (check_position->value == *lowest)
			break ;
		position++;
		check_position = check_position->next;
	}
	return (position);
}

int	find_biggest(t_stack *stack_a, int *biggest)
{
	t_node	*tmp;
	t_node	*check_position;
	int		position;

	tmp = stack_a->first;
	check_position = stack_a->first;
	*biggest = tmp->value;
	position = 0;
	while (tmp->next)
	{
		if (tmp->value > *biggest)
			*biggest = tmp->value;
		tmp = tmp->next;
	}
	if (tmp->value > *biggest)
		*biggest = tmp->value;
	while (check_position->next)
	{
		if (check_position->value == *biggest)
			break ;
		position++;
		check_position = check_position->next;
	}
	return (position);
}
