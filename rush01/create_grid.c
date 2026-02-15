/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkasuya <rkasuya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 03:05:05 by rkasuya           #+#    #+#             */
/*   Updated: 2026/02/14 15:18:46 by rkasuya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// プロトタイプ宣言
int	**create_x(void);　//create_xという引数のない戻り値が2次元配列の関数(1〜4の順列24通りを生成する)
int	check_grid(int **grid, int param[4][4]);　//chack_gridという引数がgridの2次元配列とparam[4][4](4×4の配列)で、戻値がintの関数(グリッド全体が正しいかチェックする関数)
int	check_lr(int array[], int left, int right);　//chack_lrという引数がarrayの配列とleft,rightで、戻値がintの関数(1行の左右条件をチェックする関数)


int	**create_grid(int param[4][4])　//24通りの行パターンを4行分すべて組み合わせて試し、条件を満たす解を見つける
{
	int	i;
	int	**answer;　　//最終的な4*4グリッドの答え
	int	**colarray;　//1〜4の数字を並べた24通り(4!=24)のパターン

	colarray = create_x();　//create_x()で作った24通りの列パターンをcolarrayに代入
  
	i = 0;
	answer = (int **)malloc(4 * sizeof(int *));　//ansｗerに
  
	while (i < 24 * 24 * 24 * 24)　//1列のパターンが4^4(4!)なので、1列で24通り。それらが4行あるので全部で24^4、そのすべてを検証する
	{
		answer[0] = colarray[(i / (24 * 24 * 24)) % 24]; //1列目(千の位)のパターン生成
		if (check_lr(answer[0], param[2][0], param[3][0]))　//chack_lr(1行目のデータ、左からの正解、右からの正解)
			i = ((i / (24 * 24 * 24)) + 1) * 24 * 24 * 24;
  
		answer[1] = colarray[(i / (24 * 24) % 24)];     //2列目のパターン生成
		if (check_lr(answer[1], param[2][1], param[3][1]))　//chack_lr(2行目のデータ、左からの正解、右からの正解)
			i = ((i / (24 * 24)) + 1) * 24 * 24;
  
		answer[2] = colarray[(i / 24) % 24];           //3列目のパターン生成
		if (check_lr(answer[2], param[2][2], param[3][2]))　//chack_lr(3行目のデータ、左からの正解、右からの正解)
			i = ((i / 24) + 1) * 24;
  
		answer[3] = colarray[i % 24];       　　　     //4列目のパターン生成
		if (check_grid(answer, param))
			return (answer);
		i++;
	}
	return (NULL);
}
