/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkasuya <rkasuya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 03:05:05 by rkasuya           #+#    #+#             */
/*   Updated: 2026/02/14 20:25:32 by rkasuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	create_x(int answer[24][4]);

int		check_grid(int answer[24][4], int param[4][4]);

int		check_lr(int array[], int left, int right);

void	arraycpy(int dest[4], int src[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		dest[i] = src[i];
		i++;
	}
}

int	create_grid(int param[4][4], int answer[4][4])
{
	int	i;
	int	colarray[24][4];

	create_x(colarray);
	i = 0;
	while (i < 24 * 24 * 24 * 24)
	{
		arraycpy(answer[0], colarray[(i / (24 * 24 * 24)) % 24]);
		if (check_lr(answer[0], param[2][0], param[3][0]))
			i = ((i / (24 * 24 * 24)) + 1) * 24 * 24 * 24;
		arraycpy(answer[1], colarray[(i / (24 * 24) % 24)]);
		if (check_lr(answer[1], param[2][1], param[3][1]))
			i = ((i / (24 * 24)) + 1) * 24 * 24;
		arraycpy(answer[2], colarray[(i / 24) % 24]);
		if (check_lr(answer[2], param[2][2], param[3][2]))
			i = ((i / 24) + 1) * 24;
		arraycpy(answer[3], colarray[i % 24]);
		if (check_grid(answer, param))
			return (1);
		i++;
	}
	return (0);
}
