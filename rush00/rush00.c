/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yterashi <yterashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:41:14 by yterashi          #+#    #+#             */
/*   Updated: 2026/02/08 15:22:07 by yterashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);
void	draw_horizontal(int x, char left_end, char right_end, char line);

void	rush(int x, int y)
{
	int		height;

	if (x <= 0 || y <= 0)
	{
		return ;
	}
	height = 0;
	while (height <= y - 1)
	{
		if (height == 0)
		{
			draw_horizontal(x, 'o', 'o', '-');
			height ++;
			continue ;
		}
		if (0 < height && height < y - 1)
		{
			draw_horizontal(x, '|', '|', ' ');
			height ++;
			continue ;
		}
		draw_horizontal(x, 'o', 'o', '-');
		height ++;
	}
}

void	draw_horizontal(int x, char left_end, char right_end, char line)
{
	int		width;
	char	new_line;

	new_line = '\n';
	width = 0;
	while (width <= x - 1)
	{
		if (width == 0)
		{
			ft_putchar(left_end);
			width ++;
			continue ;
		}
		if (0 < width && width < x - 1)
		{
			ft_putchar(line);
			width ++;
			continue ;
		}
		ft_putchar(right_end);
		width ++;
	}
	ft_putchar(new_line);
}
