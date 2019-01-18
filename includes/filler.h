//
// Created by bender on 1/7/19.
//

#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H

#include <stdio.h>
#include <stdlib.h>
# include <string.h>
#include <fcntl.h>
#include "get_next_line.h"
# include "../libft/includes/libft.h"

typedef struct s_cvars
{
	char friend;
	char enemy;
}				t_cvars;

t_cvars g_cvars;

typedef struct s_map
{
	int x;
	int y;
	char **map;
}		t_map;

t_map g_map;

typedef struct s_token
{
	int x;
	int y;
	char **token;
}	t_token;

t_token g_token;

char	**create_array(void);

#endif
