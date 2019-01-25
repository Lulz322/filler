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
		ft_strcpy(g_token.token[i], line);
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
		ft_strcpy(g_map.map[i], line + 4);
		free(line);
		i++;
	}
	set_piece();
	//g_coords.friend_x = 2;
	//g_coords.friend_y = 8;
	if (g_coords.enemy_x == 0 && g_coords.enemy_y == 0 && g_coords.friend_x == 0 && g_coords.friend_y == 0)
		set_position();
	else
		set_position_two();
}


void print(void)
{
	ft_putnbr(g_answer.y_answer);
	ft_putchar(' ');
	ft_putnbr(g_answer.x_answer);
	ft_putchar('\n');
	g_coords.friend_y = g_answer.y_answer;
	g_coords.friend_x = g_answer.x_answer;
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