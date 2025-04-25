/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:08:24 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/04/25 10:12:50 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

int main(void)
{
	if (ft_isalnum('0'))
		printf("num or alpha");
	else
		printf("non");
}