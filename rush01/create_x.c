/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkasuya <rkasuya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 03:04:30 by rkasuya           #+#    #+#             */
/*   Updated: 2026/02/14 17:12:52 by rkasuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //malloc()を使用しているため

int	check_same_num(int array[])　//配列内に重複した値がないかチェック
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (array[i] == array[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	**create_x(void)
{
	int	i;
	int	j;
	int	**answer;

	i = 0;
	j = 0;
	answer = (int **)malloc((4 * 3 * 2 * 1) * sizeof(int *));
	answer[0] = malloc(4 * 4);
	while (i < 4 * 4 * 4 * 4)
	{
		answer[j][0] = (i / (4 * 4 * 4)) % 4 + 1;
		answer[j][1] = (i / (4 * 4)) % 4 + 1;
		answer[j][2] = (i / 4) % 4 + 1;
		answer[j][3] = i % 4 + 1;
		if (check_same_num(answer[j]))
		{
			j++;
			if (j != 24)
				answer[j] = malloc(4 * 4);
			if (j == 24)
				break ;
		}
		i++;
	}
	return (answer);
}
