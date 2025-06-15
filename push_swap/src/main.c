/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdub <jdub@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by jdub              #+#    #+#             */
/*   Updated: 2025/06/15 16:24:37 by jdub             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = parse_arguments(argc, argv);
	if (!stack_a)
		error_exit();
	if (has_duplicates(stack_a))
	{
		ft_stackclear(&stack_a);
		error_exit();
	}
	if (is_sorted(stack_a))
	{
		ft_stackclear(&stack_a);
		return (0);
	}
	stack_b = NULL;
	assign_index(stack_a);
	sort_stack(&stack_a, &stack_b);
	ft_stackclear(&stack_a);
	ft_stackclear(&stack_b);
	return (0);
} 