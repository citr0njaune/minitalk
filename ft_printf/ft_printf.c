/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chphan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:45:52 by chphan            #+#    #+#             */
/*   Updated: 2024/12/09 18:45:59 by chphan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	type(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	if (c == 'p')
		len += ft_putptr(va_arg(args, void *));
	if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int));
	if (c == 'u')
		len += ft_putu(va_arg(args, unsigned int));
	if (c == 'x')
		len += ft_putnbrbase(va_arg(args, unsigned int), 0);
	if (c == 'X')
		len += ft_putnbrbase(va_arg(args, unsigned int), 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	args;

	len = 0;
	i = 0;
	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
				len += type(args, format[i + 1]);
			if (format[i + 1] == '%')
				len += ft_putchar(format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
