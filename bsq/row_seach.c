int	search(int **spot[y][x],int x_max, int y_max,
		int obstacle, int standard);
int	col_move(int **spot[y][x], int y_max);

int	row_search(int **spot[y][x], int x_max, int obstacle)
{
	if (x <= x_max)
	{
		x++;
		if ((now[y][x] == obstacle) ||
		((y <= obstacle && y + (standard - 1) >= obstacle) &&
		(x <= obstacle && x + (standard -1) >= obstacle)))
			x++;
		return (now[y][x]);
	}
	return ("ERROR");
}

int	col_move(int **now[y][x], int y_max)
{
	if (y <= y_max)
	{
		y = 0;
		x++;
		return (now[y][x]);
	}
	return (0);
}
