/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 00:49:55 by acosi             #+#    #+#             */
/*   Updated: 2023/05/20 17:20:08 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* This function fills the array with pointers to the elements from stack_a 
that belong to the current chunk, skiping any element which was already assigned 
a chunk. The chunks are assigned in the same order as the list, so this is a 
"stupid" fill. For example, if the list is {1, 2, 12, ...}, the first 3 numbers 
will be assigned to chunk 1, even if '12' belongs to a different chunk. This 
will then be corrected when the sort_chunk() function is called. Moreover,
**biggest is set to point to the biggest element in the current chunk. */

void	put_chunk(t_node **a, t_node **array, int chunk_size, t_node ***biggest)
{
	int	i;

	i = 0;
	while (i < chunk_size)
	{
		if ((*a)->chunk)
		{
			*a = (*a)->next;
			continue ;
		}
		array[i] = *a;
		if (!(*biggest) || (*a)->value > (**biggest)->value)
			*biggest = &array[i];
		*a = (*a)->next;
		i++;
	}
}

/* This function will refine the order in which the pointers to stack_a are 
stored in **array, so that the chunks assignement in the assign_chunk() 
function will be correct. The first if statement will find the first value in the
list that has no chunk, is smaller than biggest and is not in the current chunk.
This is where the "smart" fill begins, since this value should be assigned to the
previous chunk. Thus, we use the pointer to biggest to access the address in
array where this value should be stored (see in fill_chunk) : '*biggest = a;'
After that, **array contains the addresses of each value from stack a that belong
to the current chunk, sorted in the right order.
Finally, we update the value of biggest so that it point to the new biggest value
inside of **array. */

void	sort_chunk(t_node *a, t_node **array, int chunk_size, t_node **biggest)
{
	int	i;

	while (a)
	{
		if (a->chunk || ((a->value >= (*biggest)->value)))
		{
			a = a->next;
			continue ;
		}
		*biggest = a;
		i = -1;
		while (++i < chunk_size)
			if (array[i]->value > (*biggest)->value)
				biggest = &array[i];
		a = a->next;
	}
}

// This function will assign the chunk values for each number on the list.
// *a is a pointer to the first element of the stack, used to parse through it.
// **array is an array of pointers that we use to temporarily store chunks
// of the list while we parse it.
// **biggest represents a pointer to the biggest element of the current chunk.
/* The while loop assigns the chunk value for each node in stack a. This is
possible because **array contains pointers to a that are already sorted so that
they recieve the correct value for chunk when iterating the loop. */

void	assign_chunk(t_node *a_head, int chunk_number, int chunck_size)
{
	t_node	*a;
	t_node	**array;
	t_node	**biggest;
	int		i;

	a = a_head;
	array = malloc(sizeof(*array) * chunck_size);
	if (!array)
		return ;
	biggest = NULL;
	put_chunk(&a, array, chunck_size, &biggest);
	sort_chunk(a, array, chunck_size, biggest);
	i = -1;
	while (++i < chunck_size)
		array[i]->chunk = chunk_number;
	free(array);
}
