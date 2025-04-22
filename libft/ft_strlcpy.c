/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chphan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:38:39 by chphan            #+#    #+#             */
/*   Updated: 2024/11/13 19:17:39 by chphan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t		slen;
	size_t		i;

	slen = ft_strlen(src);
	i = 0;
	if (siz == 0)
		return (slen);
	if (!dst || !src)
		return (0);
	while (src[i] != '\0' && i + 1 < siz)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}

/*int	main(void)
{
	char dst[10];
	char *src = "carotte";
	int siz = 5;

	printf("%zu", ft_strlcpy(dst, src, siz));
	return (0);
}*/
