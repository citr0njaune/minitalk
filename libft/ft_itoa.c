/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chphan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:04:43 by chphan            #+#    #+#             */
/*   Updated: 2024/11/27 16:38:07 by chphan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	intlen(int n)
{
	int	i;
	int	len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	i = 0;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

char	intmax(int n, char *str)
{
	int	i;
	int	len;

	len = intlen(n);
	str[0] = '-';
	str[10] = '8';
	n = 214748364;
	i = 9;
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	str[len] = '\0';
	return (*str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		i;

	len = intlen(n);
	i = len - 1;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == -2147483648)
		intmax(n, str);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n = n / 10;
	}
	str[len] = '\0';
	return (str);
}

/*int	main(void)
{
	int	n;

	//n = 247109304;
	n = -2147483648;
	printf("%s", ft_itoa(n));
	return (0);
}*/
