/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 14:57:23 by iruban            #+#    #+#             */
/*   Updated: 2018/11/02 14:57:25 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr(char const *str)
{
	int index;

	index = 0;
	if (str)
	{
		while (str[index] != '\0')
		{
			ft_putchar(str[index]);
			index++;
		}
	}
}

void        ft_revputstr(const char *str)
{
	int index;

	index = 0;
	while (str[++index]);

	if (str)
	{
		while(index)
			ft_putchar(str[--index]);
	}
}