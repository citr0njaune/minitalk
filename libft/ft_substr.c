/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chphan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:43:30 by chphan            #+#    #+#             */
/*   Updated: 2024/11/21 15:52:40 by chphan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*sub;
	size_t	i;
	size_t	slen;

	slen = ft_strlen(s);
	if (len > slen - start)
		len = slen - start;
	if (start > slen)
	{
		sub = malloc(1);
		if (!sub || !s)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	i = 0;
	j = 0;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub || !s)
		return (0);
	while (j < len && s[start + i])
		sub[j++] = s[start + i++];
	sub[j] = '\0';
	return (sub);
}

/*int	main(void)
{
	char *src = "limonade rose";
	char *sub;

	sub = ft_substr(src, 9, 4);
	printf("%s", sub);
	return (0);

}*/
