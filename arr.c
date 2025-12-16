/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 02:25:46 by dcheng            #+#    #+#             */
/*   Updated: 2025/12/14 02:25:46 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(int *arr, size_t n)
{
	size_t	max_idx;
	size_t	i;

	max_idx = 0;
	i = 1;
	while (i < n)
	{
		if (arr[i] > arr[max_idx])
			max_idx = i;
		i++;
	}
	return (max_idx);
}

int	find_min_index(int *arr, size_t n)
{
	size_t	min_idx;
	size_t	i;

	min_idx = 0;
	i = 1;
	while (i < n)
	{
		if (arr[i] < arr[min_idx])
			min_idx = i;
		i++;
	}
	return (min_idx);
}

size_t	find_value_index(int *arr, size_t size, int target)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == target)
			return (i);
		i++;
	}
	return (0);
}

int	is_sorted(int *arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted_circular(int *arr, size_t n)
{
	size_t	i;
	int		breaks;

	if (n < 2)
		return (1);
	i = 0;
	breaks = 0;
	while (i < n)
	{
		if (arr[i] > arr[(i + 1) % n])
			breaks++;
		i++;
	}
	return (breaks <= 1);
}
