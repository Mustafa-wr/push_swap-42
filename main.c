/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:42:48 by mradwan           #+#    #+#             */
/*   Updated: 2023/01/06 19:20:51 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_copy_to_lists(t_ps *list, char **av)
{
	int	i;
	int	num;

	i = 0;
	num = ft_atoi(av[i++], av);
	list->stack_a = ft_lstnew(num);
	while (av[i])
	{
		num = ft_atoi(av[i], av);
		ft_lstadd_back(&list->stack_a, ft_lstnew(num));
		i++;
	}
	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
	sort_the_nums_to_small(&list->stack_a);
}

static int	supp(int ac, char **av, t_ps *list)
{
	if (!ps_arg_check(ac, av) || !ps_dub_check(ac, av))
		return (0);
	ps_copy_to_lists(list, av);
	if (!ps_sorted_check(list->stack_a))
	{
		free_all(list->stack_a);
		return (0);
	}
	check_and_sort(list);
	return (1);
}

int	ps_main(int ac, char **av)
{
	char	*str;
	t_ps	list;
	int		i;
	int		d;

	i = 1;
	str = NULL;
	while (av[i])
		str = ft_strjoin(str, av[i++]);
	av = ft_split(str, ' ');
	free(str);
	d = 0;
	while (d < i - 1)
	{
		if (av[d++] == NULL)
		{
			write(2, "Error\n", 6);
			free_strings(av);
			return (0);
		}
	}
	if (!supp(ac, av, &list))
		return (0);
	free_all(list.stack_a);
	return (1);
}

void	check_and_sort(t_ps *lst)
{
	lst->stack_b = NULL;
	if (ft_lstsize(lst->stack_a) == 3)
		sort_three(lst);
	else if (ft_lstsize(lst->stack_a) == 5)
		sort_five(lst);
	else if (ft_lstsize(lst->stack_a) < 50)
	{
		while (ft_lstsize(lst->stack_a) > 0)
		{
			if (!ps_sorted_check(lst->stack_a))
				break ;
			sorting_few(lst);
		}
		while (lst->stack_b)
			ps_pa(lst);
	}
	else
		sorting2(lst);
}

int	main(int ac, char **av)
{
	if (!ps_main(ac, av))
		return (0);
}
