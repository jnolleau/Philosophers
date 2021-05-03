/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:12:56 by julnolle          #+#    #+#             */
/*   Updated: 2021/05/03 18:27:31 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
/*
int			ft_malloc_datas(t_data *data)
{
	int	i;

	data->last_meal_time = NULL;
	data->meal_nb = NULL;
	if (data->nb > 1)
	{
		data->last_meal_time = malloc(sizeof(time_t) * data->nb);
		data->meal_nb = malloc(sizeof(int) * data->nb);
		if (data->last_meal_time && data->meal_nb)
		{
			i = 0;
			while (i < data->nb)
			{
				data->last_meal_time[i] = UNSET;
				data->meal_nb[i] = 0;
				i++;
			}
			return (SUCCESS);
		}
	}
	return (FAILURE);
}*/

int			ft_init(t_data *data, char const **av, int ac)
{
	data->start_time = get_time_in_ms();
	data->nb = ft_atoi(av[1]);
	if (data->nb < 2)
	{
		ft_putendl_fd("The simulation needs at least 2 philosophers to run", 2);
		return (FAILURE);
	}
	data->forks = NULL;
	data->id = 0;
	data->die_t = ft_atoi(av[2]);
	data->eat_t = ft_atoi(av[3]);
	data->sleep_t = ft_atoi(av[4]);
	data->last_meal_time = UNSET;
	data->meal_nb = 0;
	data->stop = CONTINUE;
	if (ac == 6)
		data->max_meals = ft_atoi(av[5]);
	else
		data->max_meals = UNSET;
	return (SUCCESS);
}

static char	*get_action(int state)
{
	if (state == FORK)
		return ("has taken a fork");
	else if (state == EAT)
		return ("is eating");
	else if (state == SLEEP)
		return ("is sleeping");
	else if (state == THINK)
		return ("is thinking");
	else if (state == DIE)
		return ("died");
	else
		return ("died");
}

int			ft_print_state(t_data *data, int state)
{
	sem_wait(data->display);
	printf("%ld %d %s\n",
		get_time_in_ms() - data->start_time, data->id, get_action(state));
	sem_post(data->display);
	if (state == DIE)
	{
		data->stop = STOP;
		// return (SUCCESS);
	}
	if (state == EAT && data->max_meals != UNSET)
	{
		if (data->meal_nb >= data->max_meals)
			data->stop = FULL;
	}
	return (SUCCESS);
}
