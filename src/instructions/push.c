/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:30:55 by acosi             #+#    #+#             */
/*   Updated: 2025/03/20 21:41:57 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push(t_stack *src, t_stack *dest)
{
	if (!dest->first)
	{
		src->first->next->prev = NULL;
		dest->first = src->first;
		src->first = src->first->next;
		dest->first->next = NULL;
		dest->last = dest->first;
		return ;
	}
	if (src->first == src->last)
	{
		dest->first->prev = src->first;
		src->first->next = dest->first;
		dest->first = src->first;
		src->first = NULL;
		src->last = NULL;
		return ;
	}
	src->first->next->prev = NULL;
	dest->first->prev = src->first;
	src->first = src->first->next;
	dest->first->prev->next = dest->first;
	dest->first = dest->first->prev;
	dest->first->prev = NULL;
}

void	push_a(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_putendl_fd("pa", 1);
}

void	push_b(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_putendl_fd("pb", 1);
}
