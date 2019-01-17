#include "../includes/filler.h"
#include <stdio.h>
#include <unistd.h>

#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100


typedef struct coords
{
	int x;
	int y;
} coords;

coords cord;


void fill_o_board(unsigned char map[10][10])
{
	int i;
	int j;
	i = 0;
	while (i < 10)
	{
		j = -1;
		while (++j < 10)
			map[i][j] = ' ';
		i++;
	}
}

void create_board(unsigned char map[10][10])
{
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = -1;
		while (++j < 10)
			if (i == 0 || j == 0 || i == 9 || j == 9)
				map[i][j] = 178;
		i++;
	}
}

void print_map(unsigned char map[10][10])
{
	int i;
	int j;

	i = 0;

	while (i < 10)
	{
		j = -1;
		while (++j < 10)
			printf("%c ", map[i][j]);
		printf("\n");
		i++;
	}
}

void del_heash(unsigned char map[10][10])
{
	int i;
	int j;

	i = 1;
	while (i < 9)
	{
		j = 0;
		while (j++ < 8)
				map[i][j] = ' ';
		i++;
	}
}


void place_character(unsigned char map[10][10], int x, int y)
{
	del_heash(map);
	map[y][x] = '#';
	cord.x = x;
	cord.y = y;

}


int main() {
	unsigned char map[10][10];
	int a;

	fill_o_board(map);
	create_board(map);
	printf("\nSTEP TWO\n");
	print_map(map);
	cord.y = 5;
	cord.x = 3;
	place_character(map, cord.x, cord.y);
	while (a != 27)
	{
		printf("WAITING...\n");
		a = getchar();
		if (a == UP)
			if (map[cord.y - 1][cord.x] == ' ')
				cord.y--;
		if (a == DOWN)
			if (map[cord.y + 1][cord.x] == ' ')
				cord.y++;
		if (a == LEFT)
			if (map[cord.y][cord.x - 1] == ' ')
				cord.x--;
		if (a == RIGHT)
			if (map[cord.y][cord.x + 1]  == ' ')
				cord.x++;
		place_character(map, cord.x, cord.y);
		print_map(map);
	}



	return 0;
}