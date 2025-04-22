/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chphan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:25:01 by chphan            #+#    #+#             */
/*   Updated: 2024/11/15 16:38:38 by chphan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*sourc;

	dst = (unsigned char *)dest;
	sourc = (unsigned char *)src;
	i = 0;
	if (n != 0 && dst == 0 && src == 0)
		return (0);
	while (n > i)
	{
		dst[i] = sourc[i];
		i++;
	}
	return (dst);
}

/*int	main(void)
{
	const char *dest;
	const char *src = "ciel et eau";
	
	ft_memcpy(&dest, &src, strlen(src));
	printf("%s", dest);
	return (0);
}*/
