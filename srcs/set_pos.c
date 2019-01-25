#include "../includes/filler.h"


void	set_position_two(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_map.y)
	{
		j = 0;
		while (j < g_map.x)
		{
			if (g_map.map[i][j] == g_cvars.enemy + 32)
			{
				g_coords.enemy_x = j;
				g_coords.enemy_y = i;
			}
			j++;
		}
		i++;
	}
}


void	set_position(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_map.y)
	{
		j = 0;
		while (j < g_map.x)
		{
			if (g_map.map[i][j] == g_cvars.enemy)
			{
				g_coords.enemy_x = j;
				g_coords.enemy_y = i;
			}
			if (g_map.map[i][j] == g_cvars.friend)
			{
				g_coords.friend_x = j;
				g_coords.friend_y = i;
			}
			j++;
		}
		i++;
	}
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
	if (line[10] == '1')
		g_cvars.friend = 'O';
	else
		g_cvars.friend = 'X';
	free(line);
	set_enemy();
}


bool 	place_piece(void)
{
	/*ft_putchar('\n');
	ft_putstr("ENEMY Y : ");
	ft_putnbr(g_coords.enemy_y);
	ft_putchar('\n');
	ft_putstr("ENEMY X : ");
	ft_putnbr(g_coords.enemy_x);
	ft_putchar('\n');
	ft_putstr("FRIEND Y : ");
	ft_putnbr(g_coords.friend_y);
	ft_putchar('\n');
	ft_putstr("FRIEND X : ");
	ft_putnbr(g_coords.friend_x);
	ft_putchar('\n');*/
	if (g_coords.enemy_y > g_coords.friend_y && g_coords.enemy_x >= g_coords.friend_x)
	{
		if (try_right_downside() == true)
			return (true);
	}
	else if (g_coords.enemy_y < g_coords.friend_y && g_coords.enemy_x <= g_coords.friend_x)
	{
			if (try_left_upside() == true)
				return (true);
	}
	else if (g_coords.enemy_y <= g_coords.friend_y && g_coords.enemy_x >= g_coords.friend_x)
	{
		if (try_right_upside() == true)
			return (true);
	}
	else if (g_coords.enemy_y >= g_coords.friend_y && g_coords.enemy_x <= g_coords.friend_x)
	{
		if (try_left_downside() == true)
			return (true);
	}
	return (false);
}