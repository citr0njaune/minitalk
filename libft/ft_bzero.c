/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chphan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:26:36 by chphan            #+#    #+#             */
/*   Updated: 2024/11/19 15:38:10 by chphan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

/*int	main(void)
{
	char s[10];
	int i = 0;
	
	ft_bzero(s, 10);
	while (i < 10)
	{
		printf("%d", s[i]);
		i++;
	}
	return (0);
}*/
