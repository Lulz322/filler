#include "../includes/filler.h"

bool	try_set_piece(int i, int j)
{
	if (i + g_token.y > g_map.y || j + g_token.x > g_map.x)
		return (false);
	else
		return (check_place(i , j));
}

void set_piece(void)
{
	int		n;
	int		i;
	char    *line;
	n = 6;
	i = 0;
	get_next_line(0, &line);
	g_token.y = ft_atoi(&line[6]);
	while (ft_isdigit(line[n]))
		n++;
	n++;
	g_token.x = ft_atoi(&line[n]);
	if (!g_token.token)
		g_token.token = create_array();
	free(line);
	while (i < g_token.y)
	{
		get_next_line(0, &line);
		g_token.token[i] = ft_strdup(line);
		free(line);
		i++;
	}
}

void	set_map(void)
{
	int i;
	char *line;

	i = 0;
	get_next_line(0, &line);
	g_map.y = ft_atoi(&line[8]);
	g_map.x = ft_atoi(&line[11]);
	if (!g_map.map)
		g_map.map = create_array();
	free(line);
	get_next_line(0, &line);
	free(line);
	while (i < g_map.y)
	{
		get_next_line(0, &line);
		g_map.map[i] = ft_strdup(line + 4);
		free(line);
		i++;
	}
	set_piece();
	set_position();
}


void print(void)
{
	ft_putnbr(g_answer.y_answer);
	ft_putchar(' ');
	ft_putnbr(g_answer.x_answer);
	ft_putchar('\n');
}

int main(void)
{
	bool game;

	game = true;
	set_me();
	while (game)
	{
		set_map();
		if (place_piece() == false)
			game = false;
		print();
	}
	free_array(g_map.y, g_map.map);
	free_array(g_map.y, g_token.token);
	return (0);
}