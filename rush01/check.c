/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkasuya <rkasuya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 20:50:12 by nkato             #+#    #+#             */
/*   Updated: 2026/02/14 15:18:50 by rkasuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	check(int array[], int visible_count)
{
	int	i;
	int	count;
	int	max;

	max = 0;
	i = 0;
	count = 0;
	while (i < 4)
	{
		if (array[i] > max)
		{
			max = array[i];
			count++;
		}
		i++;
	}
	if (count == visible_count)
		return (1);
	return (0);
}

int	check_rev(int array[], int visible_count)
{
	int	i;
	int	count;
	int	max;

	max = 0;
	i = 3;
	count = 0;
	while (i >= 0)
	{
		if (array[i] > max)
		{
			max = array[i];
			count++;
		}
		i--;
	}
	if (count == visible_count)
		return (1);
	return (0);
}

int	check_lr(int array[], int left, int right)
{
	if (check(array, left))
		return (0);
	if (check_rev(array, right))
		return (0);
	return (1);
}

// int	main(void)
// {
// 	int arr[4] = {2, 1, 4, 3};

// 	printf("%d\n", check(arr, 1));
// 	printf("%d\n", check(arr, 2));
// 	printf("%d\n", check(arr, 3));
// 	printf("%d\n", check(arr, 4));
// 	printf("%d\n", check_rev(arr, 1));
// 	printf("%d\n", check_rev(arr, 2));
// 	printf("%d\n", check_rev(arr, 3));
// 	printf("%d\n", check_rev(arr, 4));
// }
