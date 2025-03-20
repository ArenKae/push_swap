/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:40:51 by acosi             #+#    #+#             */
/*   Updated: 2025/03/20 21:41:59 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate(t_stack *stack, bool is_reverse)
{
	if (is_reverse)
	{
		stack->last->next = stack->first;
		stack->first->prev = stack->last;
		stack->first = stack->first->prev;
		stack->last = stack->last->prev;
	}
	else
	{
		stack->last->next = stack->first;
		stack->first->prev = stack->last;
		stack->last = stack->last->next;
		stack->first = stack->first->next;
	}
	stack->first->prev = NULL;
	stack->last->next = NULL;
}

void	rotate_a(t_stack *stack_a)
{
	rotate(stack_a, false);
	ft_putendl_fd("ra", 1);
}

void	reverse_rotate_a(t_stack *stack_a)
{
	rotate(stack_a, true);
	ft_putendl_fd("rra", 1);
}

void	rotate_b(t_stack *stack_b)
{
	rotate(stack_b, false);
	ft_putendl_fd("rb", 1);
}

void	reverse_rotate_b(t_stack *stack_b)
{
	rotate(stack_b, true);
	ft_putendl_fd("rrb", 1);
}
