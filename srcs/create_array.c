#include "../includes/filler.h"

char **create_array(void)
{
	char **tmp;
	int i;

	i = 0;
	tmp = (char **)malloc(sizeof(char *) * g_map.y);
	while (i < g_map.y)
	{
		tmp[i] = (char *)malloc(sizeof(char) * g_map.x * g_map.y);
		i++;
	}
	return (tmp);
}

void    free_array(int counter, char **array)
{
	int i;

	i = 0;
	while (i < counter)
	{
		free(array[i++]);
	}
	free(array);
}
