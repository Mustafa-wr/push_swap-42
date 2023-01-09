/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:41:11 by mradwan           #+#    #+#             */
/*   Updated: 2023/01/05 20:54:48 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_ps *s)
{
	if (s->stack_a->id == 0 && s->stack_a->next->id == 2)
	{
		sa(s);
		ra(s);
	}
	else if (s->stack_a->id == 2 && s->stack_a->next->id == 1)
	{
		sa(s);
		rra(s);
	}
	else if (s->stack_a->id == 2 && s->stack_a->next->id == 0)
		ra(s);
	else if (s->stack_a->id == 1 && s->stack_a->next->id == 0)
		sa(s);
	else if (s->stack_a->id == 1 && s->stack_a->next->id == 2)
		rra(s);
}

void	sorting_few(t_ps *s)
{
	if (s->stack_a->id == 0)
	{
		ps_pb(s);
		sort_the_nums_to_small(&s->stack_a);
	}
	else
		rra(s);
}

void	sorting2_helper(t_ps *s, int i)
{
	while (i)
	{
		if (s->stack_a->id % 2 == 1)
		{	
			s->stack_a->id /= 2;
			ra(s);
		}
		else if (s->stack_a->id % 2 == 0)
		{	
			s->stack_a->id /= 2;
			ps_pb(s);
		}
		i--;
	}
}

void	sorting2(t_ps *s)
{
	int	i;

	while (ps_sorted_check(s->stack_a))
	{
		i = ft_lstsize(s->stack_a);
		sorting2_helper(s, i);
		if (s->stack_b)
		{
			while (s->stack_b)
				ps_pa(s);
		}
	}
}
