#include <fcntl.h>
#include <unistd.h>

void load_dict(char *numfile, char dict[121][2][12], int *dict_size)
{
	int fd = open(numfile, O_RDONLY);
	char c;
	char line[121];
	int i;
	*dict_size = 0;

	while (1)
	{
		i = 0;
		while (read(fd, &c, 1) > 0 && c != '\n')
		{
			line[i] = c;
			i++;
		}
		if (i == 0)
			break;
		line[i] = '\0';

		int j = 0;
		i = 0;
		while (line[i] != ':')
		{
			dict[*dict_size][0][j] = line[i];
			i++;
			j++;
		}
		dict[*dict_size][0][j] = '\0';
		i += 2;
		j = 0;

		while (line[i] != '\0')
		{
			dict[*dict_size][1][j] = line[i];
			i++;
			j++;
		}
		dict[*dict_size][1][j] ='\0';

		dict_size++;
	}
	close(fd);
}
