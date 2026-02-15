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

int	check(int array[], int visible_count);　//check.cより、checkを呼び出して、

int	check_rev(int array[], int visible_count);

int	check_same_num_col(int answer[4][4]) //各列(横)に同じ数字が重複していないか確認
{
	int	i;　//行番号(縦)-1
	int	j;　//行番号(縦)-2
	int	k;　//列番号(横)

	k = 0;
	while (k < 4)　//各列をチェック
	{
		i = 0;
		while (i < 4)　//iとjの差は、j=i+1となる
		{
			j = i + 1;
			while (j < 4)　//最初の引数を変えて縦で重複を確認する
			{
				if (answer[i][k] == answer[j][k])　//i行目、k列目の値と重複があれば、'0'を返す
				{
					return (0);
				}
				j++;
			}
			i++;
		}
		k++;
	}
	return (1);　//すべての列で重複なし→'1'を返す
}

int	check_row(int answer[4][4], int param[4][4]) //すべての行について、左右からの条件を確認
{
	int	i;　//whileで繰り返す用の変数

	i = 0;
	while (i < 4)　//配列が4つの数を持っているので、4回繰り返す
	{
		if (!(check(answer[i], param[2][i])))　//左から配列を確認する→一致しない場合、'0'を返す
			return (0);
		if (!(check_rev(answer[i], param[3][i])))　//右から配列を確認する→一致しない場合、'0'を返す
			return (0);
		i++;
	}
	return (1);　//すべての列が条件を満たすとき、'1'を返す
}

int	check_col(int answer[4][4], int param[4][4]) //すべての行について、上下からの条件を確認
{
	int	i;
	int	j;
	int	array[4]; //1列を一時的に格納する配列

	j = 0;
	while (j < 4)　//各列をチェック
	{
		i = 0;
		while (i < 4)
		{
			array[i] = answer[i][j]; //縦方向のデータを横に並べる
			i++;
		}
		if (!(check(array, param[0][j])))　//上から数をチェック
			return (0);
		if (!(check_rev(array, param[1][j])))　//下から数をチェック
			return (0);
		j++;
	}
	return (1);
}

int	check_grid(int answer[4][4], int param[4][4])　//すべての検証をまとめて実行するメイン検証関数
{
	if (!check_same_num_col(answer))　//各列に重複がないか
		return (0);
	if (!check_row(answer, param))　//すべての行の左右の条件
		return (0);
	if (!check_col(answer, param))　//すべての行の上下の条件
		return (0);
	return (1);　//すべてをパスすれば'1'を返す
}
