/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:16:48 by acosi             #+#    #+#             */
/*   Updated: 2023/05/20 08:13:52 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Initialize the stack_a by creating a new_node for each
argument passed to the executable. */

int	create_nodes(t_tree *root, int size, char **args)
{
	t_node	*new_node;
	int		i;
	int		j;

	j = 0;
	root->a.first = root->head;
	root->a.first->prev = NULL;
	new_node = root->a.first;
	i = -1;
	while (++i < (size - 1))
	{
		j = ft_atoi(args[i]);
		new_node->value = j;
		new_node->chunk = 0;
		new_node->next = new_node + 1;
		new_node->next->prev = new_node;
		new_node++;
	}
	j = ft_atoi(args[i]);
	root->a.last = new_node;
	new_node->value = j;
	new_node->chunk = 0;
	new_node->next = NULL;
	return (1);
}

/* Initialize the first node of the root structure (head) and
initialize stack_a depending on how the arguments are
passed to the executable. free_array() returns 0 and is used to both
free args from any leaks and as a return value to indicate if the 
init_stack() function executed correctly or not. */

int	init_stack(t_tree *root, int ac, char **av)
{
	int		j;
	char	**args;

	j = 0;
	if (ac > 2)
	{
		root->head = malloc(sizeof(*root->head) * (ac - 1));
		if (!root->head)
			return (0);
		if (!create_nodes(root, ac - 1, &av[1]))
			return (0);
	}
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		while (args[j])
			j++;
		root->head = malloc(sizeof(*root->head) * j);
		if (!root->head)
			return (free_array(args));
		if (!create_nodes(root, j, args))
			return (free_array(args));
	}
	return (!(free_array(args)));
}

int	main(int ac, char **av)
{
	t_tree	root;

	if (ac < 2)
		return (0);
	check_args(ac, av);
	if (is_sorted(ac, av) == true)
		return (0);
	if (!init_stack(&root, ac, av))
		return (0);
	root.b.first = NULL;
	root.b.last = NULL;
	sort_stack(&root, ac, av);
	return (0);
}
