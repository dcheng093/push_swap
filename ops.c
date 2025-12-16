/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:17:17 by dcheng            #+#    #+#             */
/*   Updated: 2025/12/13 22:17:17 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op(t_pushswap *ps, int op_code)
{
	static char				*op_strs[] = {
		"sa\n", "pa\n", "ra\n", "rra\n",
		"sb\n", "pb\n", "rb\n", "rrb\n",
		"ss\n", "rr\n", "rrr\n"
	};
	static const t_op_fn	op_fns[] = {
		sa, pa, ra, rra,
		sb, pb, rb, rrb,
		ss, rr, rrr
	};

	if (op_code < SWAP_A || op_code > REVERSE_ROTATE_ROTATE)
		return ;
	if (op_fns[op_code](ps))
		ft_putstr_fd(op_strs[op_code], 1);
}

int	ss(t_pushswap *ps)
{
	if (ps->size_a < 2 && ps->size_b < 2)
		return (0);
	sa(ps);
	sb(ps);
	return (1);
}

int	rr(t_pushswap *ps)
{
	if (ps->size_a < 2 && ps->size_b < 2)
		return (0);
	ra(ps);
	rb(ps);
	return (1);
}

int	rrr(t_pushswap *ps)
{
	if (ps->size_a < 2 && ps->size_b < 2)
		return (0);
	rra(ps);
	rrb(ps);
	return (1);
}
