#include <unistd.h>

void ft_putnbr(int nb)
{
	int	c;
	char	k;

	k = nb + '0';
	c = add(nb);
	write(1, &k, c);
	
}

int	add(int i)
{
	int	count;

	count = 0;
	if (i < 0)
	{
		write(1, "-", 1);
		if (i == -2147483648)
		{
			return (11);
		}
		i = -i;
		while (i > 9)
		{
			i = i / 10;
			count++;
		}
	}
	else{
		while (i > 9)
		{
			i = i / 10;
			count++;
		}
	}
	return (count);
}


int main()
{
	ft_putnbr(9876543);
	return(0);
}
