/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yterashi <yterashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:41:14 by yterashi          #+#    #+#             */
/*   Updated: 2026/02/08 15:22:07 by yterashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);　//ft_putcharを呼び出す
void	draw_horizontal(int x, char left_end, char right_end, char line);　//draw_horizontalを呼び出す

void	rush(int x, int y)　//図形を描画する
{
	int		height;　//縦の長さ

	if (x <= 0 || y <= 0)　//x or y が0のとき数を返す
	{
		return ;
	}
	height = 0;　//heightを0にする
	while (height <= y - 1)　//heightをy-1まで増やす間、描画する
	{
		if (height == 0)　//一番上の列の処理
		{
			draw_horizontal(x, 'o', 'o', '-');　//一番上の列を描画
			height ++;　//heightを1増やす
			continue ;　//while (height <= y - 1)[26]に戻る
		}
		if (0 < height && height < y - 1)　//heightが0より大きくy-1より小さいときの処理
		{
			draw_horizontal(x, '|', '|', ' ');　//間の列
			height ++;　//heightを1増やす
			continue ;　//while (height <= y - 1)[26]に戻る
		}
		draw_horizontal(x, 'o', 'o', '-');　//一番下の列
		height ++;　//heightを1増やす
	}
}

void	draw_horizontal(int x, char left_end, char right_end, char line)　
//1列分の描画(横の長さ(x),　左端の文字,　右端の文字,　中の文字)
{
	int		width;　//横の長さ
	char	new_line;　//改行

	new_line = '\n';　//new_lineに改行を入れる
	width = 0;　//widthを0にする
	while (width <= x - 1)　//widthがx-1のとき繰り返す
	{
		if (width == 0)　//widthが0のとき、左端の文字を表示
		{
			ft_putchar(left_end);
			width ++;　//widthを1増やす
			continue ;　//while (width <= x - 1)[53]に戻る
		}
		if (0 < width && width < x - 1)　//widthが0より大きく、x-1より小さいとき、中の文字を表示
		{
			ft_putchar(line);
			width ++;　//widthを1増やす
			continue ;　//while (width <= x - 1)[53]に戻る
		}
		ft_putchar(right_end);　//右端の文字を表示
		width ++;　//widthを1増やす
	}
	ft_putchar(new_line);　//改行する
}
