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

void 	render_image(t_scope *scope)
{
	t_image	*img;

	img = scope->image;
	mlx_put_image_to_window(scope->mlx_ptr, scope->win_ptr, img->ptr, 0, 0);
}

void	clear_image(t_scope *scope)
{
	ft_bzero(scope->image->addr, scope->height * scope->image->line_size);
}
