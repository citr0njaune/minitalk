/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chphan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:43:25 by chphan            #+#    #+#             */
/*   Updated: 2024/11/21 15:28:55 by chphan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total;
	size_t			i;
	void			*ptr;
	unsigned char	*ptr2;

	i = 0;
	total = nmemb * size;
	ptr = malloc(total);
	if (ptr == (void *)0)
		return (0);
	ptr2 = (unsigned char *)ptr;
	while (i < total)
	{
		ptr2[i] = 0;
		i++;
	}
	return (ptr);
}

/*int	main(void)
{
	size_t n = 5;
	size_t i = 0;
	int *array = ft_calloc(n, 5);
	
	while (i < 5)
	{	
		printf("%d\n", array[i]);
		i++;
	}
	return (0);//ft_bzero(ptr2, total);
}*/
