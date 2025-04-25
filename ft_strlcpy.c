/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:07:58 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/04/25 19:03:42 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t res;

	res = 0;
	while (src[res])
		res++;
	
	i = 0;
	if (size == 0)
		return (res);
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (res);
}v
