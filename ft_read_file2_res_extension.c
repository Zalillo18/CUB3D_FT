/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file2_res_extension.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartin- <gmartin-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:06:49 by gmartin-          #+#    #+#             */
/*   Updated: 2020/07/09 12:10:58 by gmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_set_res(char **res, int j, t_file *f)
{
	if (j == 1)
		f->w = ft_atoi(res[j]);
	if (j == 2)
		f->h = ft_atoi(res[j]);
}

int				ft_check_extension(char *str)
{
	char	*extensions;
	int		rtn;

	rtn = -1;
	extensions = ".xpm";
	if (ft_strcmp(extensions, str) != 0)
		rtn = 1;
	return (rtn);
}

int				ft_handle_resolution(t_file *f)
{
	char	**res;
	int		i;
	int		j;

	if (*f->line == 'R' && *f->line)
	{
		i = 0;
		j = 1;
		res = ft_split(f->line, ' ');
		if (res[3] != 0)
			return (f->rtn = -1);
		while (j <= 2)
		{
			while (res[j][i])
			{
				if (!ft_isdigit(res[j][i]))
					return (f->rtn = -1);
				i++;
			}
			i = 0;
			ft_set_res(res, j, f);
			j++;
		}
	}
	return (f->rtn);
}
