/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chphan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:05:19 by chphan            #+#    #+#             */
/*   Updated: 2024/11/14 19:51:37 by chphan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (n);
	while (n > 0)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		n--;
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char array [] = { 0, 0, 20 , 0};
	char array1 [] = { 0, 0, 16 , 0};
	size_t	n = 3;
	
	printf("mem %d\n", memcmp(array, array1, n));
	printf("ft_ %d\n", ft_memcmp(array, array1, n));
	return (0);
}*/
