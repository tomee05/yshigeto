#include <string.h>
#include "library.h"

char *find_word(char *num, char dict[121][2][12], int dict_size)
{
	int i = 0;
	while (i < dict_size)
	{
		if (ft_strcmp(dict[i][0], num) == 0)
			return dict[i][1];
		i++;
	}
	return NULL;
}

char *convert(char *three, char dict[121][2][12], int dict_size)
{
	char upper[2];
	char lower[3];
	char *upper_word;
	char *lower_word;

	upper[0] = three[0];
	upper[1] = '\0';
	lower[0] = three[1];
	lower[1] = three[2];
	lower[2] = '\0';

	upper_word = find_word(upper, dict, dict_size);
	lower_word = find_word(lower, dict, dict_size);
}