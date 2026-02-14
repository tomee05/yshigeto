/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkasuya <rkasuya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:32:35 by rkasuya           #+#    #+#             */
/*   Updated: 2026/02/14 19:48:44 by rkasuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(int array[], int visible_count);

int	check_rev(int array[], int visible_count);

int	check_same_num_col(int answer[4][4])
{
	int	i;
	int	j;
	int	k;

	k = 0;
	while (k < 4)
	{
		i = 0;
		while (i < 4)
		{
			j = i + 1;
			while (j < 4)
			{
				if (answer[i][k] == answer[j][k])
				{
					return (0);
				}
				j++;
			}
			i++;
		}
		k++;
	}
	return (1);
}

int	check_row(int answer[4][4], int param[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!(check(answer[i], param[2][i])))
			return (0);
		if (!(check_rev(answer[i], param[3][i])))
			return (0);
		i++;
	}
	return (1);
}

int	check_col(int answer[4][4], int param[4][4])
{
	int	i;
	int	j;
	int	array[4];

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			array[i] = answer[i][j];
			i++;
		}
		if (!(check(array, param[0][j])))
			return (0);
		if (!(check_rev(array, param[1][j])))
			return (0);
		j++;
	}
	return (1);
}

int	check_grid(int answer[4][4], int param[4][4])
{
	if (!check_same_num_col(answer))
		return (0);
	if (!check_row(answer, param))
		return (0);
	if (!check_col(answer, param))
		return (0);
	return (1);
}
