/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:17:10 by acosi             #+#    #+#             */
/*   Updated: 2022/12/06 16:27:36 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_string_size(char const *s, char c)
{
	size_t	i;
	size_t	string_size;

	i = 0;
	string_size = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			string_size++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (string_size);
}

static size_t	ft_strlen_word(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_write_word(char const *s, char c)
{
	size_t		len_word;
	size_t		i;
	char		*word;

	i = 0;
	len_word = ft_strlen_word(s, c);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	while (i < len_word)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	dst = (char **)malloc(sizeof(char *) * (count_string_size(s, c) + 1));
	if (dst == NULL)
		return (NULL);
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			dst[i] = ft_write_word(s, c);
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	dst[i] = NULL;
	return (dst);
}
