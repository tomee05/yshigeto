/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkasuya <rkasuya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 03:03:50 by rkasuya           #+#    #+#             */
/*   Updated: 2026/02/14 20:25:45 by rkasuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		error(int argc, char *argv[]);

int		create_grid(int param[4][4], int answer[4][4]);

void	put_grid(int answer[4][4]);

int		niatoi(char *argv[], int param[4][4]);

int	main(int argc, char *argv[])
{
	int	answer[4][4];
	int	param[4][4];
	int	flag;

	(void)argc;
	if (error(argc, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	niatoi(argv, param);
	flag = create_grid(param, answer);
	if (!flag)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	put_grid(answer);
}
