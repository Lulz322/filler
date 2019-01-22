#include "../includes/filler.h"


void set_piece(char *line)
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
	if (!g_token.token)
		g_token.token = create_array();
	while (i < g_token.y)
	{
		get_next_line(0, &line);
		g_token.token[i] = ft_strdup(line);
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
	get_next_line(0, &line);
	while (i <= g_map.y)
	{
		get_next_line(0, &line);
		if (ft_isdigit(line[0]))
			g_map.map[i] = ft_strdup(line + 4);
		i++;
	}
	set_piece(line);
	set_position();
}

void	set_enemy(void)
{
	if (g_cvars.friend == 'O')
		g_cvars.enemy = 'X';
	if (g_cvars.friend == 'X')
		g_cvars.enemy = 'O';
}


void	set_me(void)
{
	char *line;

	get_next_line(0, &line);
	if (ft_atoi(line + 10) == 1)
		g_cvars.friend = 'O';
	else
		g_cvars.friend = 'X';
	set_enemy();
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
		place_piece();
		print();
	}
	free(g_map.map);
	free(g_token.token);
	return (0);

}