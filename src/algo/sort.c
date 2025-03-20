/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:15:40 by acosi             #+#    #+#             */
/*   Updated: 2025/03/20 21:44:45 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// 1. Push every number to stack_b by chunk in ascending order.
// 2. Push the last remaining chunk from a to b.
// 3. Sort the last chunk first (chunk value = 0) and push it back to a.
// 4. Sort the remaining chunks starting from the remaning last, and
// push them back to a so that they end up in ascending order.

void	push_swap(t_tree *root, int chunk_size, int total_chunks)
{
	int	i;

	i = 0;
	while (++i < total_chunks)
		push_chunks(&root->a, &root->b, i, chunk_size);
	while (root->a.first)
		push_b(&root->a, &root->b);
	while (root->b.first->chunk == 0 || root->b.last->chunk == 0)
		sort_numbers(&root->a, &root->b, 0);
	i = total_chunks;
	while (--i > 0)
		while (root->b.first && (root->b.first->chunk == i
				|| root->b.last->chunk == i))
			sort_numbers(&root->a, &root->b, i);
}

/* If there are 5 or less number, we use an algorithm designed to handle small
lists. Else, we divide the list into multiples chunks of variable size, 
depending on the size of the list. Each number in the list is assigned the 
correct chunk it belongs to with the assign_chunk() function call. Finally, 
the push_swap() function use the chunks to sort the list efficiently. */

void	sort_stack(t_tree *root, int ac, char **av)
{
	int	chunk_number;
	int	total_chunks;
	int	chunk_size;

	chunk_number = 0;
	total_chunks = 0;
	if (ac == 2)
		ac = count_args(av);
	else
		ac = ac - 1;
	if (ac <= 5)
		sort_small_stack(root, ac);
	if (ac > 5)
	{
		if (ac <= 151)
			total_chunks = 5;
		if (ac > 151)
			total_chunks = 15;
		chunk_size = (ac - 1) / total_chunks;
		while (++chunk_number < total_chunks)
			assign_chunk(root->a.first, chunk_number, chunk_size);
		push_swap(root, chunk_size, total_chunks);
	}
	free (root->head);
}
