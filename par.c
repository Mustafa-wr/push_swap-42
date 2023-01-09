/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:38:18 by mradwan           #+#    #+#             */
/*   Updated: 2023/01/06 19:20:34 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_arg_check(int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	if (ac < 2)
		return (0);
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if ((av[j][0] == '+' || av[j][0] == '-' ) && i == 0)
				i++;
			if (av[j][i] >= '0' && av[j][i] <= '9')
				i++;
			else
			{
				write(2, "Error\n", 6);
				free_strings(av);
				return (0);
			}
		}
		j++;
	}
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	i = -1;
	j = 0;
	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 2);
	if (join == NULL)
		return (NULL);
	if (s1)
		while (s1[++i] != '\0')
			join[i] = s1[i];
	while (s2[j] != '\0')
		join[i++] = s2[j++];
	join[(ft_strlen(s1) + ft_strlen(s2))] = ' ';
	join[(ft_strlen(s1) + ft_strlen(s2)) + 1] = '\0';
	free(s1);
	return (join);
}

void	free_all(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

void	sorting_few2(t_ps *s)
{
	if (s->stack_a->id == 0)
	{
		ps_pb(s);
		ft_printf("pb\n");
		sort_the_nums_to_small(&s->stack_a);
	}
	else
		ra(s);
}

void	sort_five(t_ps *lst)
{
	while (ft_lstsize(lst->stack_a) > 3)
	{
		if (lst->stack_a->id == 0 || lst->stack_a->id == 1)
			ps_pb(lst);
		else
			rra(lst);
	}
	sort_the_nums_to_small(&lst->stack_a);
	sort_three(lst);
	ps_pa(lst);
	ps_pa(lst);
	sort_the_nums_to_small(&lst->stack_a);
	if (ps_sorted_check(lst->stack_a))
		sa(lst);
	// free_all(lst->stack_a);
}
