/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:18:32 by esupatae          #+#    #+#             */
/*   Updated: 2020/01/23 19:18:42 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	deal_key(int key, t_pos *param)
{
	int x;
	int x1;
	int y;
	int y1;
	int i;

	i = 0;
	x = param->x;
	y = param->y;
	ft_putnbr(key);
	if (key == 123)
		param->x -= 10;
	else if (key == 124)
		param->x += 10;
	else if (key == 125)
		param->y += 10;
	else if (key == 126)
		param->y -= 10;
	ft_putchar('\n');
	x1 = x;
	y1 = y;
	while (i++ < 10)
	{
		x1 += get_direction(x, param->x);
		y1 += get_direction(y, param->y);
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, x1, y1, 0xFFFFFF);
	}
	return (0);
}

int	deal_mouse(int button, int x, int y, t_pos *param)
{
	float	dx;
	float	dy;
	int		step;
	float	x0;
	float	y0;
	int		i;

	ft_putstr("button: ");
	ft_putnbr(button);
	ft_putchar('\n');
	if (button == 1)
	{
		if (param->x > 0 && param->y > 0)
		{
			dx = x - param->x;
			dy = y - param->y;
			if (ft_abs(dx) >= ft_abs(dy))
				step = ft_abs(dx);
			else
				step = ft_abs(dy);
			dx = dx / step;
			dy = dy / step;
			x0 = param->x;
			y0 = param->y;
			i = 0;
			while (i <= step)
			{
				mlx_pixel_put(param->mlx_ptr, param->win_ptr, round(x0), round(y0), 0xFFFFFF);
				x0 += dx;
				y0 += dy;
				i++;
			}
			param->x = x0;
			param->y = y0;
		}
		else
		{
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y, 0xFFFFFF);
			param->x = x;
			param->y = y;
		}
	}
	else if (button == 2)
	{
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		param->x = -1;
		param->y = -1;
	}
	return (0);
}

int mouse_press(int button, int x, int y, t_pos *pos)
{
	ft_putstr("pressed a mouse button\n");
	pos->pressed = 1;
	deal_mouse(button, x, y, pos);
	return (0);
}

int mouse_rel(int button, int x, int y, t_pos *pos)
{
	ft_putstr("release a mouse button\n");
	pos->pressed = 0;
	return (0);
}

int mouse_move(int x, int y, t_pos *param)
{
	if (param->pressed == 1)
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y, 0xFFFFFF);
	return (0);
}