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

int	deal_mouse(int button, int x, int y, t_scope *scope)
{
	float	dx;
	float	dy;
	int		step;
	float	x0;
	float	y0;
	int		i;

//	ft_putstr("button: ");
//	ft_putnbr(button);
//	ft_putchar('\n');
//	if (button == 1)
//	{
//		if (scope->x > 0 && scope->y > 0)
//		{
//			dx = x - scope->x;
//			dy = y - scope->y;
//			if (ft_abs(dx) >= ft_abs(dy))
//				step = ft_abs(dx);
//			else
//				step = ft_abs(dy);
//			dx = dx / step;
//			dy = dy / step;
//			x0 = scope->x;
//			y0 = scope->y;
//			i = 0;
//			while (i <= step)
//			{
//				mlx_pixel_put(scope->mlx_ptr, scope->win_ptr, round(x0), round(y0), 0xFFFFFF);
//				x0 += dx;
//				y0 += dy;
//				i++;
//			}
//            scope->x = x0;
//            scope->y = y0;
//		}
//		else
//		{
//			mlx_pixel_put(scope->mlx_ptr, scope->win_ptr, x, y, 0xFFFFFF);
//            scope->x = x;
//            scope->y = y;
//		}
//	}
//	else if (button == 2)
//	{
//		mlx_clear_window(scope->mlx_ptr, scope->win_ptr);
//        scope->x = -1;
//        scope->y = -1;
//	}
	return (0);
}

int mouse_press(int button, int x, int y, t_scope *scope)
{
	ft_putstr("pressed a mouse button\n");
	return (0);
}

int mouse_release(int button, int x, int y, t_scope *scope)
{
	ft_putstr("release a mouse button\n");
	return (0);
}

int mouse_move(int x, int y, t_scope *scope)
{
//	ft_putstr("mouse motion detected: (");
//	ft_putnbr(x);
//	ft_putstr(", ");
//	ft_putnbr(y);
//	ft_putstr(")\n");
	draw_line(scope, 600, 400, x, y, 0xFFFFFF);
	return (0);
}