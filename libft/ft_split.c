/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:49:04 by vscabell          #+#    #+#             */
/*   Updated: 2021/04/04 01:27:39 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_elem(const char *s, char c)
{
	int	i;
	int	elem;

	i = 0;
	elem = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0')
		{
			elem++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (elem);
}

static int	*ft_position_elem(const char *s, char c, int elem)
{
	int	*p;
	int	i;
	int	j;

	i = 0;
	j = 0;
	p = malloc((elem * 2) * sizeof(int));
	if (!p)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0')
		{
			p[j] = i;
			i++;
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
			p[j] = i;
			j++;
		}
		else
			i++;
	}
	return (p);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		elem;
	int		*posit;
	char	**arr;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	elem = ft_count_elem(s, c);
	posit = ft_position_elem(s, c, elem);
	arr = (char **)malloc((elem + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (j < elem)
	{
		arr[j] = ft_substr(s, ((unsigned int)posit[i]),
				((size_t)(posit[i + 1] - posit[i])));
		i = i + 2;
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
