/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:08:34 by miafonso          #+#    #+#             */
/*   Updated: 2024/04/08 14:08:34 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	count_words(char const *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	if (s[i] != c)
		words++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i] != '\0')
				words++;
			if (s[i] == '\0')
				return (words);
		}
		i++;
	}
	return (words);
}

int	word_size(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	*build_str(char const *s, unsigned int start, unsigned int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(((end - start) + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = s[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**str_split;
	size_t	i;
	size_t	start;
	int		word;

	start = 0;
	word = 0;
	i = 0;
	str_split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !str_split)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			start = i;
			i += word_size(&s[i], c);
			str_split[word] = build_str(s, start, i);
			word++;
		}
	}
	str_split[word] = NULL;
	return (str_split);
}

/*int main()
{
		char const s_ft_split[] = "lorem ipsum dolor sit amet,
			consectetur adipiscing elit. Sed non risus. Suspendisse";
		char const s_ft_split1[] = "hhhhhheeehh";
		char const s_ft_split2[] = "eeeehabceeehhhh";
		char const s_ft_split3[] = "hhhhh";
		char const s_ft_split4[] = "eeehhehheee";
		char **str_split = ft_split(s_ft_split, ' ');

		printf("%s\n", str_split[0]);
		printf("%s\n", str_split[11]);
		printf("count_words: 0 --> %d\n", count_words(s_ft_split, ' '));
		printf("count_words: 2 --> %d\n", count_words(s_ft_split1, 'e'));
		printf("count_words: 2 --> %d\n", count_words(s_ft_split2, 'e'));
		printf("count_words: 1 --> %d\n", count_words(s_ft_split3, 'e'));
		printf("count_words: 2 --> %d\n", count_words(s_ft_split4, 'e'));

		free(str_split);
}*/