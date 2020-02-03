/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:20:04 by esupatae          #+#    #+#             */
/*   Updated: 2020/01/23 19:20:06 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		get_direction(int n1, int n2)
{
	if (n1 > n2)
		return (-1);
	else if (n1 < n2)
		return (1);
	return (0);
}

t_scope	*init_scope(void *mlx_ptr, void *win_ptr, int width, int height)
{
	t_scope	*scope;
	int 	**data;
	int		*row;
	int		i;

	scope = (t_scope*)malloc(sizeof(t_scope));
	scope->x = height;
	scope->y = width;
	scope->mlx_ptr = mlx_ptr;
	scope->win_ptr = win_ptr;
	scope->mouse_pressed = 0;
	scope->mouse_released = 0;
	scope->mouse_hold = 0;
	scope->key_pressed = 0;
	scope->key_released = 0;
	scope->key_hold = 0;
	scope->img_ptr = NULL;
	scope->arr = (int***)malloc(sizeof(int**));
	*(scope->arr) = (int**)malloc(sizeof(int*) * height);
	data = *(scope->arr);
	i = 0;
	while (i < height)
    {
		row = *data;
        row = (int*)malloc(sizeof(int) * width);
        data++;
        i++;
    }
	return (scope);
}
