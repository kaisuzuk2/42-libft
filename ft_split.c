/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:54:02 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/04/27 15:29:10 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

static size_t	ft_word_count(char const *s, char c)
{
	size_t	res;
	int		flg;
	size_t	i;

	res = 0;
	flg = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			flg = 1;
		else if (flg)
		{
			res++;
			flg = 0;
		}
		i++;
	}
	printf("size = %zu\n", res);
	return (res);
}

static char	*ft_fill_word(char const **p, char c)
{
	char	*res;
	size_t	str_len;

	str_len = 0;
	while (**p == c)
		(*p)++;
	while ((*p)[str_len])
	{
		if ((*p)[str_len] == c)
			break ;
		str_len++;
	}
	res = (char *)malloc(sizeof(char) * (str_len + 1));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, *p, str_len + 1);
	if ((*p)[str_len] != '\0')
		*p = *p + str_len + 1;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**head;
	char	**tmp;
	size_t	head_size;

	head_size = ft_word_count(s, c);
	head = (char **)malloc(sizeof(char *) * (head_size + 1));
	if (head == NULL)
		return (NULL);
	tmp = head;
	while (tmp < &head[head_size])
	{
		*tmp = ft_fill_word(&s, c);
		if (tmp++ == NULL)
		{
			while (--tmp)
				free(*tmp);
			free(tmp);
			return (NULL);
		}
	}
	
	return (head);
}
