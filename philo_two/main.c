/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 12:24:12 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/18 12:28:21 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_two(char const **av)
{
	size_t	i;

	i = 1;
	while (av[i])
	{
		ft_putendl(av[i]);
		i++;
	}
}

int		main(int ac, char const **av)
{
	ft_putendl("MAIN PHILO_TWO");
	if (ac == 5)
		philo_two(av);
	else
		ft_putendl("Wrong nbr of arguments");
	return (0);
}
