#include "../includes/filler.h"

char **create_array(void)
{
	char **tmp;
	char *line;
	int i;

	i = 0;
	tmp = (char **)malloc(sizeof(char *) * g_map.y);
	line = (char *)malloc(sizeof(char) * g_map.x * g_map.y);
	while (i < g_map.y)
	{
		tmp[i] = &line[i * g_map.x];
		i++;
	}
	return (tmp);
}

char **create_array_token(void)
{
	char **tmp;
	char *line;
	int i;

	i = 0;
	tmp = (char **)malloc(sizeof(char *) * g_token.y);
	line = (char *)malloc(sizeof(char) * g_token.x * g_token.y);
	while (i < g_token.y)
	{
		tmp[i] = &line[i * g_token.x];
		i++;
	}
	return (tmp);
}
