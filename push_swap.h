/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:30:28 by dcheng            #+#    #+#             */
/*   Updated: 2025/12/11 18:30:28 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INVALID_NUMBER LLONG_MAX
# define SWAP_A 0
# define PUSH_A 1
# define ROTATE_A 2
# define REVERSE_ROTATE_A 3
# define SWAP_B 4
# define PUSH_B 5
# define ROTATE_B 6
# define REVERSE_ROTATE_B 7
# define SWAP_SWAP 8
# define ROTATE_ROTATE 9
# define REVERSE_ROTATE_ROTATE 10
# define IDX 11
# define VAL 12

# include "libft/libft.h"

typedef struct s_pushswap
{
	int		*a;
	int		*b;
	size_t	size_a;
	size_t	size_b;
	size_t	total_size;
	size_t	*target_a;
	size_t	target_b;
	int		*cost;
	int		*rr;
	int		*rrr;
}	t_pushswap;

typedef int	(*t_op_fn)(t_pushswap *ps);

size_t	count_numbers(char **av);
void	exit_helper(t_pushswap*ps, int code, void (*callback)(void*), void*ctx);
void	parse_input(char **av, int *input);

int		is_sorted(int *arr, size_t n);
int		is_sorted_circular(int *arr, size_t n);
int		find_max_index(int *arr, size_t n);
int		find_min_index(int *arr, size_t n);
size_t	find_value_index(int *arr, size_t size, int target);

void	sort_three(t_pushswap *ps);
void	sort_stack(t_pushswap *ps);
void	turksort(t_pushswap *ps);

void	calc_cost(t_pushswap *ps);
size_t	find_cheapest(const t_pushswap *ps);

void	set_target_a(t_pushswap *ps);
void	set_target_b(t_pushswap *ps);

void	r_to_top(t_pushswap *ps, const size_t i);
void	move_cheapest_to_top(t_pushswap *ps);
void	move_b_target_to_top(t_pushswap *ps);

void	op(t_pushswap *ps, int op_code);
int		ss(t_pushswap *ps);
int		rr(t_pushswap *ps);
int		rrr(t_pushswap *ps);
int		sa(t_pushswap *ps);
int		pa(t_pushswap *ps);
int		ra(t_pushswap *ps);
int		rra(t_pushswap *ps);
int		sb(t_pushswap *ps); // Unused
int		pb(t_pushswap *ps);
int		rb(t_pushswap *ps);
int		rrb(t_pushswap *ps);

#endif