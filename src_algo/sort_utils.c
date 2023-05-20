/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 06:03:47 by acosi             #+#    #+#             */
/*   Updated: 2023/05/18 06:45:44 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* For i varying from 0 to the total number of chunks, this function
pushes every number from a to b, chunk by chunk. As a result, everything
will be sorted by ascending chunk number in stack b.
The 'rotate_a' instruction allows parsing through the entirety of stack a. */

void	push_chunks(t_stack *stack_a, t_stack *stack_b, int i, int chunk_size)
{
	int	count;

	count = 0;
	while (count != chunk_size)
	{
		if (stack_a->first->chunk == i)
		{
			push_b(stack_a, stack_b);
			count += 1;
			continue ;
		}
		rotate_a(stack_a);
	}
}

/* This function iterates through stack b in both directions to find the biggest
value (starting the comparison with INT_MIN) and determine if it is closer from
the start or the end of the stack. Returns true if it's closer from the start, 
indicating that the stack should be rotated clockwise, or false if it's closer 
from the end, indicating that a counter_clockwise rotation is prefered. */

bool	get_clockwise(t_stack *stack_b, int chunk, int *biggest)
{
	t_node	*first_node;
	t_node	*last_node;
	bool	clockwise;

	clockwise = 0;
	first_node = stack_b->first;
	last_node = stack_b->last;
	while ((first_node->next && first_node->chunk == chunk)
		|| (last_node->prev && last_node->chunk == chunk))
	{
		if (first_node->value > *biggest)
		{
			*biggest = first_node->value;
			clockwise = true;
		}
		first_node = first_node->next;
		if (last_node->value > *biggest)
		{
			*biggest = last_node->value;
			clockwise = false;
		}
		last_node = last_node->prev;
	}
	return (clockwise);
}

/* This function will get the biggest value of a given chunk. After determining
if the value is closer to the start or the end of the stack via the 
get_clockwise() function, it will rotate b untill the biggest value is at the top
of the stack. Finally, the biggest value is pushed to a, and the loop continues
on the next biggest value. */

void	sort_numbers(t_stack *stack_a, t_stack *stack_b, int chunk_number)
{
	int		biggest;
	bool	clockwise;

	biggest = INT_MIN;
	clockwise = get_clockwise(stack_b, chunk_number, &biggest);
	if (!stack_b->first)
		return ;
	if (stack_b->first == stack_b->last)
	{
		push_a(stack_a, stack_b);
		return ;
	}
	if (clockwise == true)
	{
		while (stack_b->first->value != biggest)
			rotate_b(stack_b);
		push_a(stack_a, stack_b);
	}
	else
	{
		while (stack_b->first->value != biggest)
			reverse_rotate_b(stack_b);
		push_a(stack_a, stack_b);
	}
}
