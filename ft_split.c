/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:54:02 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/04/26 15:24:05 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

static size_t ft_word_count(char const *s, char c)
{
	size_t res;
	int flg;
	
	p = (char *)s;
	res = 0;
	flg = 0;
	while (*p && (p = ft_strchr(p, c)) != NULL)
	{
		if (flg)
			res++;
		p++;
		if (*p == c)
			flg = 1;
		else
			flg = 0;
		if (!*p)
			res--;
	}
	return (res);
}

static void ft_free(char **res, size_t size)
{
	size_t i;
	
	i = 0;
	while (i <= size)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

char **ft_split(char const*s, char c)
{	
	char **res;
	size_t res_size;
	size_t str_size;
	size_t i;
	char *p;
	
	res_size = ft_word_count(s, c);
	res = (char **)malloc(sizeof(char *) * res_size);
	if (res == NULL)
		return (NULL);
	p = (char *)s;
	i = 0;
	while (i < res_size - 1)
	{
		str_size = ((char *)ft_memchr((char *)p, (int)c, -1) - p) + 1;
		res[i] = (char *)malloc(sizeof(char) * str_size);
		if (res[i] == NULL)
			ft_free(res, i);
		ft_strlcpy(res[i], p, str_size);
		p = (char *)ft_memchr((char *)p, (int)c,  -1);
		p++;
		i++;
	}
	str_size = ft_strlen(p) + 1;
	res[i] = (char *)malloc(sizeof(char) * str_size);
	ft_strlcpy(res[i], p, str_size);
	return (res);
}

int main(void)
{
	char s[] = "hello world this is a pen";
	char **res = ft_split(s, ' ');
	for (int i = 0; i < 6; i++)
		printf("%s\n", res[i]);
}