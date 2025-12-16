/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 00:41:15 by dcheng            #+#    #+#             */
/*   Updated: 2025/12/13 00:41:15 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_numbers(char **av)
{
	size_t	i;
	size_t	j;
	size_t	count;
	size_t	is_number;

	i = 1;
	count = 0;
	while (av[i])
	{
		j = 0;
		is_number = 0;
		while (av[i][j])
		{
			if ((av[i][j] >= 9 && av[i][j] <= 13) || av[i][j] == 32)
				is_number = 0;
			else if (!is_number)
			{
				is_number = 1;
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

static long long	ft_atoi_pushswap(const char *s)
{
	long long	res;
	long long	tmp;
	int			sign;
	size_t		i;

	res = 0;
	sign = 1;
	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
		sign = 1 - 2 * (s[i++] == '-');
	if (!(s[i] >= '0' && s[i] <= '9'))
		return (INVALID_NUMBER);
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		tmp = res * sign;
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (INVALID_NUMBER);
		i++;
	}
	if (s[i] != '\0')
		return (INVALID_NUMBER);
	return (res * sign);
}

static int	validate_input(int *input, const char *num, size_t idx)
{
	long long	tmp;
	size_t		i;

	tmp = ft_atoi_pushswap(num);
	if (tmp == INVALID_NUMBER)
		return (0);
	i = 0;
	while (i < idx)
	{
		if (input[i] == (int)tmp)
			return (0);
		i++;
	}
	input[idx] = (int)tmp;
	return (1);
}

static void	free_split(char **split)
{
	size_t	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	parse_input(char **av, int *input)
{
	size_t	i;
	size_t	j;
	size_t	idx;
	char	**nums;

	i = 1;
	idx = 0;
	while (av[i])
	{
		if (av[i][0] == ' ' || av[i][ft_strlen(av[i]) - 1] == ' ')
			exit_helper(NULL, EXIT_FAILURE,
				(void (*)(void *))free_split, nums);
		nums = ft_split(av[i], ' ');
		if (!nums || !nums[0])
			exit_helper(NULL, EXIT_FAILURE,
				(void (*)(void *))free_split, nums);
		j = 0;
		while (nums[j])
			if (!validate_input(input, nums[j++], idx++))
				exit_helper(NULL, EXIT_FAILURE,
					(void (*)(void *))free_split, nums);
		free_split(nums);
		i++;
	}
}
