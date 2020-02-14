/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:49:59 by esupatae          #+#    #+#             */
/*   Updated: 2020/01/22 21:50:00 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	count_col(const char *line)
{
	int		count;
	char	**arr;

	count = 0;
	arr = ft_strsplit(line, ' ');
	while (*arr++)
		count++;
	return (count);
}

static int	*read_row(t_scope *scope, const char *line)
{
	char	**arr;
	char	**ptr1;
	int		*ans;
	int		*ptr2;
	int		count;

	count = 0;
	arr = ft_strsplit(line, ' ');
	ptr1 = arr;
	while (*ptr1++)
		count++;
	ans = (int*)malloc(sizeof(int) * count);
	ptr2 = ans;
	while (*arr)
	{
		*ptr2 = ft_atoi(*arr++);
		set_z_range(scope->z_range, *ptr2++);
	}
	return (ans);
}

static void	add_row_to_list(t_scope *scope, t_file *file, char *line)
{
	t_list	*list;
	int		*arr;
	int		val;

	list = file->list;
	arr = read_row(scope, line);
	if (list)
	{
		list->next = ft_lstnew(arr, sizeof(int) * file->col);
		file->list = list->next;
		file->row++;
	}
	else
	{
		file->list = ft_lstnew(arr, sizeof(int) * file->col);
		file->head = file->list;
		file->row = 1;
	}
	free(arr);
}

void		extrapolate_file(t_scope *scope, t_file *file)
{
	int		i;
	int		j;
	t_list	*curr;
	int		*row;
	t_map	*map;

	i = 0;
	curr = file->head;
	map = scope->map;
	while (i < map->row)
	{
		j = 0;
		row = (int*)(curr->content);
		while (j < map->col)
		{
			map->matrix3d[i][j].x = j * map->scale -
					(map->col * map->scale / 2);
			map->matrix3d[i][j].y = i * map->scale -
					(map->row * map->scale / 2);
			map->matrix3d[i][j].z = (float)(row[j] * map->scale / 2);
			j++;
		}
		curr = curr->next;
		i++;
	}
}

void		read_map(t_scope *scope, const int fd)
{
	int		ret;
	char	*line;
	t_file	*file;

	file = (t_file*)malloc(sizeof(t_file));
	file->list = NULL;
	file->col = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		if (!file->col)
			file->col = count_col(line);
		add_row_to_list(scope, file, line);
		free(line);
	}
	scope->file = file;
	scope->map = init_map(scope, file);
	extrapolate_file(scope, file);
	close(fd);
}
