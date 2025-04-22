/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chphan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:38:39 by chphan            #+#    #+#             */
/*   Updated: 2024/11/23 20:47:09 by chphan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

static char	**free_(char **str, int x)
{
	while (x >= 0)
	{
		free(str[x]);
		x--;
	}
	free(str);
	return (NULL);
}

int	fill_str(const char *s, char c, char **str)
{
	int	word;
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			word = i;
			while (s[word] && s[word] != c)
				word++;
			str[x] = ft_substr(s, i, word - i);
			if (!str[x++])
			{
				free_(str, x);
				return (0);
			}
			i = word;
		}
		else
			i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**str;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	str = ft_calloc(words + 1, sizeof(char *));
	if (!str)
		return (NULL);
	if (fill_str(s, c, str) != 1)
		return (NULL);
	str[words] = NULL;
	return (str);
}

// int    main(void)
// {
// 	char **sp = ft_split("xhelloxyouxme", 'x');
//     int i = 0;

// 	while (sp[i])
// 	{
// 		printf("%s\n", sp[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (sp[i])
// 	{
// 		free(sp[i]);
// 		i++;
// 	}
// 	free(sp);
//     return (0);

// }
