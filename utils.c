/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:56:11 by mradwan           #+#    #+#             */
/*   Updated: 2023/01/05 22:19:45 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, char **av)
{
	int			i;
	long int	res;
	int			sign;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = sign * -1;
	while (str[i] == '0')
			i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i++] - '0');
		if ((res > 2147483647 && sign == 1) || (res > 2147483648 && sign == -1))
		{
			write(2, "Error\n", 6);
			free_strings(av);
			exit(-1);
		}
	}
	return (res * sign);
}

int	ps_dub_check(int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (ac < 2)
		return (0);
	while (av[j])
	{
		i = j + 1;
		while (av[i])
		{
			if (ft_atoi(av[i], av) == ft_atoi(av[j], av))
			{
				write(2, "Error\n", 6);
				free_strings(av);
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	ps_sorted_check(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
			tmp = tmp->next;
		else
			return (1);
	}
	return (0);
}

void	sort_the_nums_to_small(t_list **list)
{
	int		i;
	t_list	*tmp;
	t_list	*tmp2;

	i = 0;
	tmp = (*list);
	while (tmp)
	{
		i = 0;
		tmp2 = (*list);
		while (tmp2)
		{
			if (tmp->content > tmp2->content)
				i++;
			tmp2 = tmp2->next;
		}
		tmp->id = i;
		tmp = tmp->next;
	}
}

void	free_strings(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
