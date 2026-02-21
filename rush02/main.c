#include <string.h>

int arrays_num(char *str);
void **split(char *argv, int num);

int main (int argc, char *argv[])
{
	int num = arrays_num(argv[1]);
	int dict_size;
	char **param = split(argv[1], num);
	char dict[121][2][12];
	load_dict("numbers.dict", dict, &dict_size);
	(void)argc;

	int i = 0;
	while (i < num)
	{
		char *word = find_word(param[i], dict, dict_size);
		i++;
	}
	int i = 0;
	while (i < num)
	{
		free(param[i]);
		i++;
	}
	free(param);
}