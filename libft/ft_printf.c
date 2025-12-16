/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigger <nigger@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:19:10 by nigger            #+#    #+#             */
/*   Updated: 2025/11/16 15:19:10 by nigger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1), 1);
	else if (c == 's')
		return (ft_putstr_pf(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_pf((long)va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunbr_pf((unsigned long)va_arg(args, unsigned int)));
	else if (c == 'p')
		return (ft_putptr_pf(va_arg(args, void *)));
	else if (c == 'x')
		return (ft_puthex_pf(va_arg(args, unsigned int), HEX_LOW));
	else if (c == 'X')
		return (ft_puthex_pf(va_arg(args, unsigned int), HEX_UP));
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_format(format[i], args);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
