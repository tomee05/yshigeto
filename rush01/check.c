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
//配列の要素とmaxを一つずつ比べて確認する
int	check(int array[], int visible_count)　//作った配列にて見える箱の数が期待値と一致するか、左からの確認
{
	int	i;　//繰り返し処理用の数
	int	count;　//見える箱の数
	int	max;　//最大の高さ

	max = 0;
	i = 0;
	count = 0;
	
	while (i < 4)　//配列に入っている4個分繰り返す
	{
		if (array[i] > max)　//最大値よりもarray[i]が大きい場合
		{
			max = array[i];　//maxにarray[i]を代入
			count++;　//左から見えている箱の数
		}
		i++;
	}
	if (count == visible_count)　//countと与えられた値が等しいかどうか
		return (1);　//等しければ、'1'を返す
	return (0);　//等しくなければ、'0'を返す
}

int	check_rev(int array[], int visible_count)　//右からの確認
{
	int	i; //繰り返し処理用の数”
	int	count;　//見える箱の数”
	int	max;　//最大の高さ”

	max = 0;
	i = 3; //右からなので、4個目から引いていく
	count = 0;
	while (i >= 0)　//配列に入っている4個分繰り返す
	{
		if (array[i] > max)　//最大値よりもarray[i]が大きい場合”
		{
			max = array[i];　//maxにarray[i]を代入”
			count++;　//右から見えている箱の数
		}
		i--;
	}
	if (count == visible_count)　//countと与えられた値が等しいかどうか”
		return (1);　//等しければ、'1'を返す”
	return (0);　//等しくなければ、'0'を返す”
}

int	check_lr(int array[], int left, int right)　//左右それぞれの値を比較
{
	if (check(array, left))　//左からの確認→合っていれば'0'を返す
		return (0);
	if (check_rev(array, right)) //右からの確認→合っていれば'0'を返す
		return (0);
	return (1); //どちらかが合っていなければ'1'を返す
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
