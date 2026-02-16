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

int		error(int argc, char *argv[]);　//引数はコマンドライン引数の個数と文字列の配列、戻り値はint。エラー処理を行う

int		create_grid(int param[4][4], int answer[4][4]);　//引数は条件を格納した4*4の整数配列(input)と解答を格納する4*4の整数配列(output)、戻り値はint。条件をもとに解答を生成

void	put_grid(int answer[4][4]);　//引数は4*4の整数配列、戻り値はなし。解答グリッドを画面に表示

int		niatoi(char *argv[], int param[4][4]);　//引数はコマンドライン引数の配列(文字列)と変換結果を格納する4*4の整数配列(output)、戻り値はint。コマンドライン引数を数値配列に変換

int	main(int argc, char *argv[])　//コマンドライン引数から条件を受け取る
{
	int	answer[4][4];　//解答を格納する4*4配列
	int	param[4][4];　//条件(各方向から見える高さ)を格納
	int	flag;  //解けたかどうかのフラグ

	(void)argc;　//main関数の中で直接的にargcは使っていないので、警告抑制のために、argc変数を使っていないことを明示的に示す
	
	if (error(argc, argv))　//引数の個数や形式が正しいかチェック
	{
		write(1, "Error\n", 6);　//エラーがあれば"Error"と表示して返す
		return (0);
	}
	
	niatoi(argv, param);　//コマンドライン引数(文字列)を整数に変換してparam配列に格納
	
	flag = create_grid(param, answer);　//paramの条件をもとにanswerを作成
	if (!flag)　//解けなかった場合は"Error"を出力して返す
	{
		write(1, "Error\n", 6);
		return (0);
	}
	
	put_grid(answer);　//解答の4*4グリッドを出力
}
