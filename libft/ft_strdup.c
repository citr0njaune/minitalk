/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chphan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:03:33 by chphan            #+#    #+#             */
/*   Updated: 2024/11/05 15:34:40 by chphan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*dup;

	i = 0;
	dup = ((char *) malloc(sizeof(char) * (ft_strlen(src) + 1)));
	if (dup == NULL)
		return (NULL);
	else
	{
		while (src[i] != '\0')
		{
			dup[i] = src[i];
			i++;
		}
	}
	dup[i] = '\0';
	return (dup);
}

/*int	main(void)
{
	char	*src = "bon matin";
	printf("%s\n", ft_strdup(src));
	return (0);
}*/
