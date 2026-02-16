char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] = str[i] + 32;

		if (i == 0 || (('a' <= str[i] && str[i] <= 'z')
				&& (('\0' <= str[i - 1] && str[i - 1] <= '/')
					|| (':' <= str[i - 1] && str[i - 1] <= '@')
					|| ('[' <= str[i - 1] && str[i - 1] <= '`')
					|| ('{' <= str[i - 1]))))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

#include <stdio.h>

int main()
{
	char wards[] = "hi, how are you? 42words forty-two; fifty+and+one";
	printf("%s\n",wards);
	printf("%s\n",ft_strcapitalize(wards));
}
