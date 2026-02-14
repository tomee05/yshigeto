/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkato <nkato@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:32:29 by rkasuya           #+#    #+#             */
/*   Updated: 2026/02/14 17:29:36 by nkato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>

int	error(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argv == NULL || argc != 2 || argv[1] == NULL)
		return (1);
	while (argv[1][i] != '\0')
	{
		if (i % 2 == 0 && !(argv[1][i] >= '1' && argv[1][i] <= '4'))
			return (1);
		if (i % 2 == 1 && !(argv[1][i] == ' '))
			return (1);
		i++;
	}
	if (i != 31)
		return (1);
	return (0);
}

// int	main(int argc, char *argv[])
// {
// 	// char	*argv[] = {"1", "1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4"};

// 	printf("%d", error(argc, argv));
// }
