/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinft_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chphan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:56:25 by chphan            #+#    #+#             */
/*   Updated: 2024/12/09 18:56:28 by chphan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_nb(int nb)
{
	long int	nbr;

	nbr = (long)nb;
	if (nb < 0)
		return (1 + len_nb(-nbr));
	if (nb > 9)
		return (1 + len_nb(nbr / 10));
	return (1);
}

int	ft_putnbr(int nb)
{
	long int	i;
	int			len;

	i = (long)nb;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (i < 0)
	{
		ft_putchar('-');
		i = -i;
	}
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putchar(i % 10 + '0');
	}
	else
		ft_putchar(i % 10 + '0');
	len = len_nb(nb);
	return (len);
}
