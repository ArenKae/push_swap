/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:57:53 by acosi             #+#    #+#             */
/*   Updated: 2025/03/20 21:57:49 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

// LINKED LIST STRUCTURE
// A node is composed of :
//   value = the value of the number to sort.
//   chunk = the chunk number in which the element is placed.
// There are 2 stacks : a and b. They are made of multiples nodes, 
// and are delimited by their first and last element.
// The tree is the root structure composed of the 2 stacks a and b.

typedef struct s_node
{
	struct s_node	*prev;
	int				value;
	int				chunk;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	struct s_node	*first;
	struct s_node	*last;
}					t_stack;

typedef struct s_tree
{
	struct s_stack	a;
	struct s_stack	b;
	struct s_node	*head;
}					t_tree;

// Linked list initialization
int		init_stack(t_tree *root, int ac, char **av);
int		create_nodes(t_tree *root, int size, char **args);

// Instructions
void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	reverse_rotate_a(t_stack *a);
void	reverse_rotate_b(t_stack *b);

// Algorithm
void	sort_stack(t_tree *root, int argc, char **argv);
void	sort_small_stack(t_tree *root, int argc);
int		find_lowest(t_stack *a, int *lowest);
int		find_biggest(t_stack *a, int *biggest);
void	push_swap(t_tree *root, int chunk_size, int total_chunks);
void	push_chunks(t_stack *stack_a, t_stack *stack_b, int i, int chunk_size);
bool	get_clockwise(t_stack *stack_b, int chunk, int *biggest);
void	sort_numbers(t_stack *stack_a, t_stack *stack_b, int chunk_number);

// Chunks manipulation
void	assign_chunk(t_node *a_head, int chunk_number, int chunck_size);
void	sort_chunk(t_node *a, t_node **array, int chunk_size, t_node **biggest);
void	put_chunk(t_node **a, t_node **array, int chunk_size,
			t_node ***biggest);

// Utils
int		free_array(char **args);
void	exit_error(void);
int		count_args(char **argv);

// Arguments check & error handling
void	check_args(int ac, char **av);
bool	is_num(char *arg);
bool	is_overflow(long tmp, char *arg);
bool	duplicates(int tmp, char **args, int i);
bool	is_sorted(int argc, char **args);

#endif