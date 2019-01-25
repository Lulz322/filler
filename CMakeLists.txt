cmake_minimum_required(VERSION 3.13)
project(filler C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)
include_directories(libft/includes)

add_executable(filler
        includes/filler.h
        includes/get_next_line.h
        libft/includes/libft.h
        libft/ft_atoi.c
        libft/ft_isalpha.c
        libft/ft_isdigit.c
        libft/ft_itoa.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memset.c
        libft/ft_putchar.c
        libft/ft_putnbr.c
        libft/ft_putstr.c
        libft/ft_putstr_fd.c
        libft/ft_strcat.c
        libft/ft_strchr.c
        libft/ft_strcmp.c
        libft/ft_strcpy.c
        libft/ft_strdel.c
        libft/ft_strjoin.c
        libft/ft_strlen.c
        libft/ft_strncat.c
        libft/ft_strncpy.c
        libft/ft_strnew.c
        libft/ft_strstr.c
        libft/ft_strsub.c
        libft/ft_swap.c
        libft/lst_gnl.c
        srcs/create_array.c
        srcs/get_next_line.c
        srcs/main.c
        srcs/piece.c
        srcs/set_pos.c)
