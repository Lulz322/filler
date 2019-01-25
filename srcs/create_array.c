/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:52:39 by iruban            #+#    #+#             */
/*   Updated: 2019/01/25 15:53:36 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

char	**create_array(void)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = (char **)malloc(sizeof(char *) * g_map.y);
	while (i < g_map.y)
	{
		tmp[i] = (char *)malloc(sizeof(char) * g_map.x * g_map.y);
		i++;
	}
	return (tmp);
}

void	free_array(int counter, char **array)
{
	int i;

	i = 0;
	while (i < counter)
	{
		free(array[i++]);
	}
	free(array);
}
