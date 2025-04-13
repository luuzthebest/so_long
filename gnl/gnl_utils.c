/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:06:15 by hounajar          #+#    #+#             */
/*   Updated: 2025/04/12 19:06:45 by lvvz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = gnl_strlen(src);
	i = 0;
	if (size == 0)
	{
		return (len);
	}
	while (i < size - 1 && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

char	*gnl_strdup(const char *s)
{
	size_t	size;
	char	*dest;

	if (!*s)
		return (NULL);
	size = gnl_strlen(s) + 1;
	dest = malloc(size);
	if (dest == NULL)
		return (NULL);
	gnl_strlcpy(dest, s, size);
	return (dest);
}

size_t	gnl_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter])
	{
		counter++;
	}
	return (counter);
}

int	gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*joinedstr;
	size_t	s1_len;
	size_t	s2_len;
	size_t	len;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	len = s1_len + s2_len;
	joinedstr = malloc(len + 1);
	if (joinedstr == NULL)
		return (NULL);
	gnl_strlcpy(joinedstr, s1, s1_len + 1);
	gnl_strlcpy(joinedstr + s1_len, s2, s2_len + 1);
	free(s1);
	return (joinedstr);
}
