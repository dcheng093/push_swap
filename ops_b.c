/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:05:56 by dcheng            #+#    #+#             */
/*   Updated: 2025/12/13 22:05:56 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

int	sb(t_pushswap *ps)
{
	int	tmp;

	if (ps->size_b < 2)
		return (0);
	tmp = ps->b[1];
	ps->b[1] = ps->b[0];
	ps->b[0] = tmp;
	return (1);
}

int	pb(t_pushswap *ps)
{
	size_t	i;

	if (ps->size_a == 0)
		return (0);
	i = ps->size_b;
	while (i > 0)
	{
		ps->b[i] = ps->b[i - 1];
		i--;
	}
	ps->b[0] = ps->a[0];
	i = 0;
	while (i < ps->size_a - 1)
	{
		ps->a[i] = ps->a[i + 1];
		i++;
	}
	ps->size_b++;
	ps->size_a--;
	return (1);
}

int	rb(t_pushswap *ps)
{
	int		tmp;
	size_t	i;

	if (ps->size_b < 2)
		return (0);
	i = 0;
	tmp = ps->b[0];
	while (i < ps->size_b - 1)
	{
		ps->b[i] = ps->b[i + 1];
		i++;
	}
	ps->b[ps->size_b - 1] = tmp;
	return (1);
}

int	rrb(t_pushswap *ps)
{
	int		tmp;
	size_t	i;

	if (ps->size_b < 2)
		return (0);
	i = ps->size_b - 1;
	tmp = ps->b[ps->size_b - 1];
	while (i > 0)
	{
		ps->b[i] = ps->b[i - 1];
		i--;
	}
	ps->b[0] = tmp;
	return (1);
}
