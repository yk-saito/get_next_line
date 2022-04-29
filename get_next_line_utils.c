/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 20:14:03 by ysaito            #+#    #+#             */
/*   Updated: 2020/07/16 10:48:59 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char		*ft_strdup(const char *s1)
{
	size_t	len;
	char	*copy;
	int		i;

	len = ft_strlen(s1);
	copy = (char *)malloc(len + 1);
	if (copy == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char		*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = c;
	while (*s != '\0')
	{
		if (*s == ch)
		{
			return ((char *)s);
		}
		s++;
	}
	return ((char *)s);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	s1_len;
	size_t	s2_len;
	int		i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(newstr = (char *)malloc(s1_len + s2_len + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	while (*s2 != '\0')
	{
		newstr[i] = *s2++;
		i++;
	}
	newstr[s1_len + s2_len] = '\0';
	free(s1);
	return (newstr);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	slen;
	size_t	newlen;
	size_t	i;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen || len <= 0)
		return (ft_strdup(""));
	newlen = (slen - start) > len ? len : slen - start;
	if (!(new = (char *)malloc(newlen + 1)))
		return (NULL);
	i = 0;
	while (s[start] != '\0' && newlen-- > 0)
	{
		new[i++] = s[start++];
	}
	new[i] = '\0';
	return (new);
}
