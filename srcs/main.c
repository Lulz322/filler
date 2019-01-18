#include "../includes/filler.h"


int take_piece(char *line)
{
	int		n;
	int		i;

	n = 6;
	i = 0;
	g_token.y = ft_atoi(&line[6]);
	while (ft_isdigit(line[n]))
		n++;
	n++;
	g_token.x = ft_atoi(&line[n]);
	g_token.token = create_array();
	printf("\n%d %d\n", g_token.x, g_token.y);
	while (i < g_token.y)
	{
		get_next_line(0, &line);
		g_token.token[i] = ft_strdup(line);
		i++;
	}
	i = 0;
	while (i < g_token.y)
		printf("%s\n", g_token.token[i++]);
	return (0);
}


int	take_map(void)
{
	int i;
	char *line;

	i = 0;
	g_map.map = create_array();
	get_next_line(0, &line);
	while (i <= g_map.y)
	{
		get_next_line(0, &line);
		if (ft_isdigit(line[0]))
			g_map.map[i] = ft_strdup(line + 4);
		else
			take_piece(line);
		i++;
	}
}




int main(void)
{
	char *line;

	get_next_line(0, &line);
	g_cvars.friend = (ft_atoi(line + 10) == 1) ? '0' : 'X';
	printf("%c\n", g_cvars.friend);
	while (1)
	{
		get_next_line(0, &line);
		g_map.y = ft_atoi(&line[8]);
		g_map.x = ft_atoi(&line[11]);
		printf("\n%d %d\n", g_map.y, g_map.x);
		take_map();
	}
	//if (!line[10] || (line[10] != '1' && line[10] != '2'))
		//return (printf("error about player position"));





	return 0;
}