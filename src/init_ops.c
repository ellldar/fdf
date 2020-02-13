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

t_image	*init_image(t_scope *scope, int width, int height)
{
	t_image	*image;

	image = (t_image*)malloc(sizeof(t_image));
	image->ptr = mlx_new_image(scope->mlx_ptr, width, height);
	image->addr = mlx_get_data_addr(image->ptr, &image->bits_ppxl,
			&image->line_size, &image->endian);
	return (image);
}

t_scope *init_scope(void *mlx_ptr, void *win_ptr, int width, int height)
{
    t_scope *scope;

    scope = (t_scope*)malloc(sizeof(t_scope));
    scope->mlx_ptr = mlx_ptr;
    scope->win_ptr = win_ptr;
    scope->width = width;
    scope->height = height;
    scope->line = (t_line*)malloc(sizeof(t_line));
    return (scope);
}

t_map	*init_map(t_scope *scope, t_file *file)
{
	t_map	*map;
	t_node	**arr2d;
	t_node	**arr3d;
	t_node	**tmp3d;
	int 	i;

	map = (t_map*)malloc(sizeof(t_map));
	map->scale = SCALE;
	map->row = file->row;
	map->col = file->col;
	map->matrix2d = (t_node**)malloc(sizeof(t_node*) * map->row);
	map->matrix3d = (t_node**)malloc(sizeof(t_node*) * map->row);
	map->matrix3d_temp = (t_node**)malloc(sizeof(t_node*) * map->row);
	arr2d = map->matrix2d;
	arr3d = map->matrix3d;
	tmp3d = map->matrix3d_temp;
	i = 0;
	while (i < map->row)
	{
		*arr2d++ = (t_node*)malloc(sizeof(t_node) * map->col);
		*arr3d++ = (t_node*)malloc(sizeof(t_node) * map->col);
		*tmp3d++ = (t_node*)malloc(sizeof(t_node) * map->col);
		i++;
	}
	return (map);
}

