/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turksort_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:25:58 by dcheng            #+#    #+#             */
/*   Updated: 2025/12/14 22:25:58 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calc_costs_r(t_pushswap *ps)
{
	size_t	i;
	size_t	median_a;
	size_t	median_b;

	i = 0;
	median_a = (ps->size_a + 1) / 2;
	median_b = (ps->size_b + 1) / 2;
	while (i < ps->size_a)
	{
		if (i < median_a)
			ps->cost[i] = i;
		else
			ps->cost[i] = ps->size_a - i;
		if (ps->target_a[i] < median_b)
			ps->cost[i] += ps->target_a[i];
		else
			ps->cost[i] += ps->size_b - ps->target_a[i];
		i++;
	}
}

static void calc_costs_rr(t_pushswap *ps)
{
	size_t		i;
	long long	total_cost;

	i = 0;
	while (i < ps->size_a)
	{
		if (i > ps->target_a[i])
			total_cost = i;
		else
			total_cost = ps->target_a[i];
		if (total_cost < ps->cost[i])
		{
			ps->cost[i] = total_cost;
			ps->rr[i] = 1;
		}
		i++;
	}
}

static void	calc_costs_rrr(t_pushswap *ps)
{
	size_t		i;
	long long	total_cost;
	size_t		a_moves;
	size_t		b_moves;

	i = 0;
	while (i < ps->size_a)
	{
		a_moves = ps->size_a - i;
		b_moves = ps->size_b - ps->target_a[i];
		if (a_moves > b_moves)
			total_cost = a_moves;
		else
			total_cost = b_moves;
		if (total_cost < ps->cost[i])
		{
			ps->cost[i] = total_cost;
			ps->rr[i] = 0;
			ps->rrr[i] = 1;
		}
		i++;
	}
}

void	calc_cost(t_pushswap *ps)
{
	size_t	i;

	i = 0;
	while (i < ps->size_a)
	{
		ps->rr[i] = 0;
		ps->rrr[i] = 0;
		i++;
	}
	calc_costs_r(ps);
	calc_costs_rr(ps);
	calc_costs_rrr(ps);
}

size_t	find_cheapest(const t_pushswap *ps)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (i < ps->size_a)
	{
		if (ps->cost[i] < ps->cost[res])
			res = i;
		i++;
	}
	return (res);
}
