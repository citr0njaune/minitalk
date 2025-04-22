/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chphan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:12:44 by chphan            #+#    #+#             */
/*   Updated: 2024/11/21 16:24:17 by chphan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		slen1;
	int		slen2;
	char	*ptr;
	int		i;
	int		j;

	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	i = 0;
	j = 0;
	ptr = malloc(sizeof(char) * (slen1 + slen2 + 1));
	if (!s1 || !s2 || !ptr)
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}
/*
int	main(void)
{
	char *s1 = "creme ";
	char *s2 = "solaire";
	char	*ptr;

	ptr = ft_strjoin(s1, s2);
	printf("%s", ptr);
	return (0);
}
*/