/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:57:46 by mradwan           #+#    #+#             */
/*   Updated: 2023/01/04 21:58:31 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_ps *list)
{
	ps_r(&list->stack_a);
	ft_printf("ra\n");
}

void	rb(t_ps *list)
{
	ps_r(&list->stack_b);
	ft_printf("rb\n");
}

void	rra(t_ps *list)
{
	ps_rr_list(&list->stack_a);
	ft_printf("rra\n");
}

void	rrb(t_ps *list)
{
	ps_rr_list(&list->stack_b);
	ft_printf("rrb\n");
}

void	sa(t_ps *list)
{
	ps_swap_list(list->stack_a);
	ft_printf("sa\n");
}
