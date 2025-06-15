/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdub <jdub@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by jdub              #+#    #+#             */
/*   Updated: 2025/06/15 16:26:40 by jdub             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack_a, 1);
	else if (a > b && b > c)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a, 1);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a, 1);
}

void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	int		min_index;
	int		position;
	t_stack	*current;
	t_stack	*min_node;

	size = ft_stacksize(*stack_a);
	while (size > 3)
	{
		min_index = 0;
		position = 0;
		current = *stack_a;
		min_node = *stack_a;
		while (current)
		{
			if (current->index < min_node->index)
			{
				min_node = current;
				min_index = position;
			}
			current = current->next;
			position++;
		}
		if (min_index <= size / 2)
		{
			while ((*stack_a)->index != min_node->index)
				ra(stack_a, 1);
		}
		else
		{
			while ((*stack_a)->index != min_node->index)
				rra(stack_a, 1);
		}
		pb(stack_a, stack_b, 1);
		size--;
	}
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b, 1);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	max_bits;
	int	max_index;
	int	i;
	int	j;
	int	size;

	size = ft_stacksize(*stack_a);
	max_index = size - 1;
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a, 1);
			else
				pb(stack_a, stack_b, 1);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b, 1);
		i++;
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_stacksize(*stack_a);
	if (size <= 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_small(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
} 