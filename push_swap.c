/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:45:46 by dcheng            #+#    #+#             */
/*   Updated: 2025/12/11 18:45:46 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_helper(t_pushswap*ps, int code, void (*callback)(void*), void*ctx)
{
	if (callback)
		callback(ctx);
	if (ps)
	{
		if (ps->a)
			free(ps->a);
		if (ps->b)
			free(ps->b);
		if (ps->cost)
			free(ps->cost);
		if (ps->target_a)
			free(ps->target_a);
		if (ps->rr)
			free(ps->rr);
		if (ps->rrr)
			free(ps->rrr);
		free(ps);
	}
	if (code == EXIT_FAILURE)
		ft_putstr_fd("Error\n", 2);
	exit(code);
}

static void	init_pushswap(t_pushswap **ps, int *arr, size_t count)
{
	size_t	i;

	*ps = ft_calloc(1, sizeof(t_pushswap));
	if (!*ps)
		exit_helper(NULL, EXIT_FAILURE, free, arr);
	(*ps)->a = ft_calloc(count, sizeof(int));
	(*ps)->b = ft_calloc(count, sizeof(int));
	(*ps)->size_a = count;
	(*ps)->size_b = 0;
	(*ps)->total_size = count;
	(*ps)->cost = ft_calloc(count, sizeof(int));
	(*ps)->target_a = ft_calloc(count, sizeof(size_t));
	(*ps)->target_b = SIZE_MAX;
	(*ps)->rr = ft_calloc(count, sizeof(int));
	(*ps)->rrr = ft_calloc(count, sizeof(int));
	if (!(*ps)->a || !(*ps)->b || !(*ps)->cost
		|| !(*ps)->target_a || !(*ps)->rr || !(*ps)->rrr)
		exit_helper(*ps, EXIT_FAILURE, NULL, NULL);
	i = 0;
	while (i < count)
	{
		(*ps)->a[i] = arr[i];
		i++;
	}
}

static void	solve(t_pushswap *ps)
{
	if (!is_sorted(ps->a, ps->size_a))
	{
		if (ps->size_a == 2)
			op(ps, SWAP_A);
		else if (ps->size_a == 3)
			sort_three(ps);
		else
			turksort(ps);
	}
}

int	main(int ac, char **av)
{
	int			*input;
	size_t		count;
	t_pushswap	*ps;

	ps = NULL;
	if (ac > 1 && av)
	{
		count = count_numbers(av);
		if (count == 0)
			exit_helper(ps, EXIT_FAILURE, NULL, NULL);
		input = ft_calloc(count, sizeof(int));
		if (!input)
			exit_helper(ps, EXIT_FAILURE, NULL, NULL);
		parse_input(av, input);
		init_pushswap(&ps, input, count);
		free(input);
		solve(ps);
	}
	exit_helper(ps, EXIT_SUCCESS, NULL, NULL);
}
