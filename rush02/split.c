#include <stdlib.h>
#include "library.h"

int arrays_num(char *str);

char **split(char *argv, int num)//3個ずつに分ける
{
	char **param;
	int count;
	int len;

	len = ft_strlen(argv);
	param = malloc(sizeof(char *) * num);
	count = 0;
	while (count < num)
	{
		param[count] = malloc(sizeof(char) * 3);
		count++;
	}

	count = 0;
	while (count < len)
	{
		param[num - 1 - count / 3][2 - count % 3] = argv[len - 1 - count];
		count++;
	}
	return param;
}	

int arrays_num(char *str)//配列の数
{
	int num;
	num = ft_strlen(str) / 3;
	if (ft_strlen(str) % 3 != 0)
		num++;
	return (num);
}