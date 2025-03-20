/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:04:36 by acosi             #+#    #+#             */
/*   Updated: 2025/03/20 21:42:01 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap(t_stack *stack)
{
	stack->first->prev = stack->first->next;
	stack->first->next = stack->first->prev->next;
	stack->first->prev->next = stack->first;
	stack->first = stack->first->prev;
	stack->first->prev = NULL;
}

void	swap_a(t_stack *a)
{
	swap(a);
	ft_putendl_fd("sa", 1);
}

void	swap_b(t_stack *b)
{
	swap(b);
	ft_putendl_fd("sb", 1);
}
