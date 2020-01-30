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

typedef struct	s_scope
{
	int		x;
	int		y;
	int		mouse_pressed:1;
	int		mouse_released:1;
	int		mouse_hold:1;
	int		key_pressed:1;
	int		key_released:1;
	int		key_hold:1;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		***arr;
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

int			get_direction(int n1, int n2);
int			***read_data(const int fd);

#endif
