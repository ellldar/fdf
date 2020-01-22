/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 00:53:12 by esupatae          #+#    #+#             */
/*   Updated: 2020/01/18 00:54:35 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, void *param)
{
	ft_putnbr(key);
	ft_putchar('\n');
	return (0);
}

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;

	if (argc == 2)
	{
		ft_putstr("Filename: ");
		ft_putstr(argv[1]);
		ft_putstr("\n");
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, 1000, 720, "FDF");
		mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
		mlx_key_hook(win_ptr, deal_key, (void *)0);
		mlx_loop(mlx_ptr);
	}
	else
		ft_putstr("usage: ./fdf [source_file]\n");
	return (0);
}
