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

void	create_x(int answer[24][4]);　//create_xという引数のない戻り値が2次元配列の関数(1〜4の順列24通りを生成する)
int		check_grid(int answer[24][4], int param[4][4]);//chack_gridという引数がgridの2次元配列とparam[4][4](4×4の配列)で、戻値がintの関数(グリッド全体が正しいかチェックする関数)
int		check_lr(int array[], int left, int right);//chack_lrという引数がarrayの配列とleft,rightで、戻値がintの関数(1行の左右条件をチェックする関数)

void	arraycpy(int dest[4], int src[4])  //4要素のint配列をコピーする関数
{
	int	i;

	i = 0;
	while (i < 4)　　
	{
		dest[i] = src[i];
		i++;
	}
}

int	create_grid(int param[4][4], int answer[4][4])　//24通りの行パターンを4行分すべて組み合わせて試し、条件を満たす解を見つける
{
	int	i;
	int	colarray[24][4];　//1〜4の数字を並べた24通り(4!=24)のパターン

	create_x(colarray);
	i = 0;
	while (i < 24 * 24 * 24 * 24)　//1列のパターンが4^4(4!)なので、1列で24通り。それらが4行あるので全部で24^4、そのすべてを検証する
	{
		arraycpy(answer[0], colarray[(i / (24 * 24 * 24)) % 24]); //1列目(千の位)のパターン生成
		if (check_lr(answer[0], param[2][0], param[3][0]))　//chack_lr(1行目のデータ、左からの正解、右からの正解)：左右それぞれから値を確認
			i = ((i / (24 * 24 * 24)) + 1) * 24 * 24 * 24;　//
		arraycpy(answer[1], colarray[(i / (24 * 24) % 24)]);     //2列目(百の位)のパターン生成
		if (check_lr(answer[1], param[2][1], param[3][1]))　//chack_lr(2行目のデータ、左からの正解、右からの正解)：左右それぞれから値を確認
			i = ((i / (24 * 24)) + 1) * 24 * 24;
		arraycpy(answer[2], colarray[(i / 24) % 24]);           //3列目(十の位)のパターン生成
		if (check_lr(answer[2], param[2][2], param[3][2]))　//chack_lr(3行目のデータ、左からの正解、右からの正解)：左右それぞれから値を確認
			i = ((i / 24) + 1) * 24;
		arraycpy(answer[3], colarray[i % 24]);       　　　     //4列目(一の位)のパターン生成
		if (check_grid(answer, param))
			return (1);
		i++;　//基本はここでiを1ずつ増やしており、
	}
	return (0);
}
