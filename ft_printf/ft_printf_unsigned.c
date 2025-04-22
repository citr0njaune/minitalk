/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinft_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chphan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:56:36 by chphan            #+#    #+#             */
/*   Updated: 2024/12/09 18:56:39 by chphan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putu(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 9)
	{
		len += ft_putu(nb / 10);
		len += ft_putchar(nb % 10 + '0');
	}
	else
		len += ft_putchar(nb % 10 + '0');
	return (len);
}

int	ft_putcharbase(unsigned long long int nb, int maj)
{
	if (nb < 10)
		return (ft_putchar(nb + '0'));
	if (maj)
		return (ft_putchar(nb + 55));
	return (ft_putchar(nb + 55 + 32));
}

int	ft_putnbrbase(unsigned long long int nb, int maj)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_putnbrbase(nb / 16, maj);
		len += ft_putcharbase(nb % 16, maj);
	}
	else
		len += ft_putcharbase(nb % 16, maj);
	return (len);
}

/*int	ft_putnbrbase(unsigned long nb)
{
	char *b;

 	b = "0123456789abcdef";
 	if (nb < 16)
 	{
 		write(1, &b[ nb % 16], 1);
 		return (1);
 	}
	else
		return (ft_putnbrbase(nb / 16) + ft_putnbrbase(nb % 16));
}*/

int	ft_putptr(void *ptr)
{
	int		len;

	len = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	else
	{
		len += ft_putstr("0x");
		len += ft_putnbrbase((unsigned long long)ptr, 0);
	}
	return (len);
}
