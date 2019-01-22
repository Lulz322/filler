#include "../includes/filler.h"

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
			if (g_map.map[i][j] == g_cvars.enemy || g_map.map[i][j] == g_cvars.enemy + 32)
			{
				g_coords.enemy_x = j;
				g_coords.enemy_y = i;
			}
			if (g_map.map[i][j] == g_cvars.friend || g_map.map[i][j] == g_cvars.friend + 32)
			{
				g_coords.friend_x = j;
				g_coords.friend_y = i;
			}
			j++;
		}
		i++;
	}
}

bool 	place_piece(void)
{
	if (g_coords.enemy_y >= g_coords.friend_y && g_coords.enemy_x <= g_coords.friend_x) {
		if (try_left_upside() == true)
			return (true);
	}
	else if (g_coords.enemy_y <= g_coords.friend_y && g_coords.enemy_x <= g_coords.friend_x)
	{
			if (try_left_downside() == true)
				return (true);
		}
	else if (g_coords.enemy_y <= g_coords.friend_y && g_coords.enemy_x >= g_coords.friend_x) {
		if (try_right_upside() == true)
			return (true);
	}
	else if (g_coords.enemy_y >= g_coords.friend_y && g_coords.enemy_x >= g_coords.friend_x)
	{
		if (try_right_downside() == true)
			return (true);
	}
	return (true);
}