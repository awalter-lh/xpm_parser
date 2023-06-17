/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awalter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:56:55 by awalter           #+#    #+#             */
/*   Updated: 2023/04/15 16:56:56 by awalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xpm_parser.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	rv;

	i = 0;
	rv = ft_strlen(src);
	if (size != 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (rv);
}

int	count(char *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			nb++;
		i++;
	}
	return (nb);
}

char	**loop(char *s, char c, char **lst, int *n)
{
	int	j;
	int	i;

	j = 0;
	while (*n < count (s, c))
	{
		i = 0;
		while (s[j] && s[j] == c)
			j++;
		while (s[j + i] && s[j + i] != c)
			i++;
		lst[*n] = (char *) malloc((i + 1) * sizeof(char));
		if (lst[*n] == NULL)
			return (NULL);
		ft_strlcpy(lst[*n], &s[j], i + 1);
		j += i;
		*n += 1;
	}
	return (lst);
}

char	**ft_split(char *s, char c)
{
	int		n;
	char	**lst;

	n = 0;
	lst = (char **) malloc((count (s, c) + 1) * sizeof(char *));
	if (lst == NULL)
		return (NULL);
	lst = loop(s, c, lst, &n);
	lst[n] = NULL;
	return (lst);
}
