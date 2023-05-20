/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:23:43 by acosi             #+#    #+#             */
/*   Updated: 2023/05/19 08:26:34 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Simply swap stack_a to sort a list of 2 numbers.

void	sort_two(t_stack *stack_a)
{
	if (stack_a->first->value > stack_a->first->next->value)
		swap_a(stack_a);
}

/* The sort_number() functions first identify the smallest/biggest number of
the list in order to determine what to do. The find_xxx() functions return the
the position of the number they found in the stack. This is used to handle 
instructions more efficiently, depending on if the result is closer to the 
start or the end of the list. */

void	sort_three(t_stack *stack_a)
{
	int	position;
	int	biggest;

	position = find_biggest(stack_a, &biggest);
	if (position == 0)
		rotate_a(stack_a);
	if (position == 1)
		reverse_rotate_a(stack_a);
	sort_two(stack_a);
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	position;
	int	biggest;

	position = find_biggest(stack_a, &biggest);
	if (position <= 1)
	{
		while (stack_a->first->value != biggest)
			rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
	if (position > 1)
	{
		while (stack_a->first->value != biggest)
			reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	push_a(stack_a, stack_b);
	rotate_a(stack_a);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	position;
	int	lowest;

	position = find_lowest(stack_a, &lowest);
	if (position <= 1)
	{
		while (stack_a->first->value != lowest)
			rotate_a(stack_a);
	}
	if (position > 1)
	{
		while (stack_a->first->value != lowest)
			reverse_rotate_a(stack_a);
	}
	push_b(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

// Sort a small stack when 5 or less arguments are passed.
// Each case uses a dedicated function for optimization.

void	sort_small_stack(t_tree *root, int ac)
{
	if (ac == 2)
		sort_two(&root->a);
	if (ac == 3)
		sort_three(&root->a);
	if (ac == 4)
		sort_four(&root->a, &root->b);
	if (ac == 5)
		sort_five(&root->a, &root->b);
}
