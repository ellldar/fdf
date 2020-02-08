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

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

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

typedef struct	s_scope
{
    void	*mlx_ptr;
    void	*win_ptr;
    t_image	*image;
    t_line	*line;
	int		width;
	int		height;
	int		color;
	int		mouse_pressed:1;
	int		mouse_button:2;
	int		key_pressed:1;
	int		key_button:4;
}				t_scope;

typedef struct	s_scene
{
	int		x_angle;
	int		y_angle;
	int		z_angle;
	int		ratio;
}				t_scene;

typedef struct	s_key
{
	int		button;
	int		x;
	int		y;
}				t_key;

typedef struct	s_mouse
{
	int		button;
	int		x;
	int		y;
}				t_mouse;

/*
 * -------- READ DATA FUNCTIONS --------------
 */


/*
 * -------- INITIALIZER FUNCTIONS --------------
 */

t_image		*init_image(t_scope *scope, int width, int height);
t_scope		*init_scope(void *mlx_ptr, void *win_ptr, int width, int height);

/*
 * -------- INPUT FUNCTIONS --------------
 */

int			deal_key(int key, t_scope *scope);
int			key_press(int button, t_scope *scope);
int			key_release(int button, t_scope *scope);
int			deal_mouse(int button, int x, int y, t_scope *scope);
int			mouse_press(int button, int x, int y, t_scope *scope);
int			mouse_release(int button, int x, int y, t_scope *scope);
int			mouse_move(int x, int y, t_scope *scope);

/*
 * -------- DISPLAY FUNCTIONS --------------
 */

void		put_pixel(t_scope *scope, int x, int y, int color);
void		draw_line(t_scope *scope, int x0, int y0, int x1, int y1, int color);
void		render_image(t_scope *scope);
void		clear_image(t_scope *scope);

/*
 * -------- HELPER FUNCTIONS --------------
 */

int			get_direction(int n1, int n2);
int			is_inbound(int x, int y, t_scope *scope);

#endif
