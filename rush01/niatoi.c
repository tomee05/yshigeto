/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   niatoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkasuya <rkasuya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 14:46:07 by yshigeto          #+#    #+#             */
/*   Updated: 2026/02/14 16:45:05 by rkasuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	niatoi(char *argv[], int param[4][4])
{
	int	count;
	int	value[16];
	int	i;

	count = 0;
	i = 0;
	while (argv[1][count] != '\0')
	{
		if (count % 2 == 0)
		{
			value[i] = argv[1][count] - '0';
			i++;
		}
		count++;
	}
	count = 0;
	while (count < 16)
	{
		param[count / 4][count % 4] = value[count];
		count++;
	}
	return ;
}
