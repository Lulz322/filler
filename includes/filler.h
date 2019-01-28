/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:30:34 by iruban            #+#    #+#             */
/*   Updated: 2019/01/28 14:30:36 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "../libft/includes/libft.h"

enum	e_bool { false, true };

# define _BOOL	typedef enum e_bool bool

_BOOL;

typedef struct	s_cvars
{
	char		friend;
	char		enemy;
}				t_cvars;

t_cvars g_cvars;

typedef struct	s_map
{
	int			x;
	int			y;
	char		**map;
}				t_map;

t_map g_map;

typedef struct	s_token
{
	int			x;
	int			y;
	char		**token;
}				t_token;

t_token g_token;

typedef struct	s_coords
{
	int			enemy_x;
	int			enemy_y;
	int			friend_x;
	int			friend_y;
}				t_coords;

t_coords g_coords;

typedef struct	s_answer
{
	int			x_answer;
	int			y_answer;
}				t_answer;

t_answer g_answer;

char			**create_array(void);
void			set_position(void);
void			set_piece();
bool			try_right_downside(void);
bool			try_left_downside(void);
bool			try_right_upside(void);
bool			try_left_upside(void);
bool			place_piece(void);
void			set_me(void);
void			free_array(int counter, char **qwe);
bool			try_set_piece(int i, int j);
void			set_position_two(void);
bool			check_place(int i, int j);
#endif
