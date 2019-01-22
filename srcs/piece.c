//
// Created by Ihor RUBAN on 2019-01-21.
//
#include "../includes/filler.h"

bool	check_place(int i, int j)
{
	int y;
	int x;
	int answer;

	y = 0;
	answer = 0;
	while (y < g_token.y)
	{
		x = 0;
		while (x < g_token.x)
		{
			if ((g_map.map[i + y][j + x] == g_cvars.friend ||
				 g_map.map[i + y][j + x] == g_cvars.friend + 32)
				&& g_token.token[y][x] == '*')
				answer++;
			if ((g_map.map[i + y][j + x] == g_cvars.enemy ||
				 g_map.map[i + y][j + x] == g_cvars.enemy + 32)
				&& g_token.token[y][x] == '*')
				return (false);
			x++;
		}
		y++;
	}
	return ((answer == 1) ? true : false);
}

bool	try_left_upside(void)
{
	int y;
	int x;

	y = 0;
	while (y < g_map.y)
	{
		x = -1;
		while (++x < g_map.x)
		{
			if (try_set_piece(y, x) == true)
			{
				g_answer.x_answer = x;
				g_answer.y_answer = y;
				return (true);
			}
		}
		y++;
	}
	return (false);
}

bool	try_right_upside(void)
{
	int y;
	int x;

	y = 0;
	while (y < g_map.y)
	{
		x = g_map.x;
		while (x)
		{
			if (try_set_piece(y, x) == true)
			{
				g_answer.x_answer = x;
				g_answer.y_answer = y;
				return (true);
			}
			x--;
		}
		y++;
	}
	return (false);
}

bool	try_left_downside(void)
{
	int y;
	int x;

	y = g_map.y;
	while (y)
	{
		x = -1;
		while (++x < g_map.x)
		{
			if (try_set_piece(y, x) == true)
			{
				g_answer.x_answer = x;
				g_answer.y_answer = y;
				return (true);
			}
		}
		y--;
	}
	return (false);
}

bool	try_right_downside(void)
{
	int y;
	int x;

	y = g_map.y;
	while (y)
	{
		x = g_map.x;
		while (x)
		{
			if (try_set_piece(y, x) == true)
			{
				g_answer.x_answer = x;
				g_answer.y_answer = y;
				return (true);
			}
			x--;
		}
		y--;
	}
	return (false);
}