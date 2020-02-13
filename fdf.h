/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 00:52:36 by esupatae          #+#    #+#             */
/*   Updated: 2020/01/18 00:53:05 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>

# include <time.h>
# include <stdlib.h>
# include <stdio.h>

# define WIDTH 1200
# define HEIGHT 800
# define CENT_X 600
# define CENT_Y 400
# define SCALE 20

typedef struct	s_file
{
	int		col;
	int		row;
	t_list	*list;
	t_list	*head;
}				t_file;

typedef struct	s_image
{
	void	*ptr;
	char	*addr;
	int		bits_ppxl;
	int		line_size;
	int		endian;
}				t_image;

typedef struct	s_line
{
	float	x;
	float	dx;
	float	y;
	float	dy;
	int		step;
	float	ratio;
	int		alpha;
	int		reverse_alpha;
}				t_line;

typedef struct	s_node
{
	int		x;
	int		y;
	int		z;
}				t_node;

typedef struct	s_map
{
	int		row;
	int		col;
	int		scale;
	t_node	**matrix3d;
	t_node	**matrix3d_temp;
	t_node	**matrix2d;
}				t_map;

typedef struct	s_mouse
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		dx;
	int		dy;
	float	rot_x;
	float	rot_y;
	int		pressed:1;
	int		button:2;
}				t_mouse;

typedef struct	s_key
{
	int		pressed:1;
	int		button:4;
}				t_key;

typedef struct	s_scope
{
    void	*mlx_ptr;
    void	*win_ptr;
    t_image	*image;
    t_line	*line;
    t_map	*map;
    t_mouse	*mouse;
    t_key	*key;
	int		width;
	int		height;
	int		color;
}				t_scope;

/*
 * -------- READ DATA FUNCTIONS --------------
 */

void		read_map(t_scope *scope, const int fd);

/*
 * -------- INITIALIZER FUNCTIONS --------------
 */

t_image		*init_image(t_scope *scope, int width, int height);
t_scope		*init_scope(void *mlx_ptr, void *win_ptr, int width, int height);
t_map		*init_map(t_scope *scope, t_file *file);

/*
 * -------- INPUT FUNCTIONS ----------------
 */

int			deal_key(int key, t_scope *scope);
int			key_press(int button, t_scope *scope);
int			key_release(int button, t_scope *scope);
int			deal_mouse(int button, int x, int y, t_scope *scope);
int			mouse_press(int button, int x, int y, t_scope *scope);
int			mouse_release(int button, int x, int y, t_scope *scope);
int			mouse_move(int x, int y, t_scope *scope);

/*
 * -------- MATH FUNCTIONS -----------------
 */

void		calc_rotation(t_mouse *mouse);
void		interpolate(t_scope *scope);

/*
 * -------- DISPLAY FUNCTIONS --------------
 */

void		draw_3d_obj(t_scope *scope);
void		draw_line(t_scope *scope, int x0, int y0, int x1, int y1, int color);
void		render_image(t_scope *scope);
void		clear_image(t_scope *scope);

/*
 * -------- HELPER FUNCTIONS --------------
 */

int			get_direction(int n1, int n2);
int			is_confined(t_scope *scope, int x, int y);
int			is_endpoint(t_line *var, int x, int y, int x1, int y1);

#endif
