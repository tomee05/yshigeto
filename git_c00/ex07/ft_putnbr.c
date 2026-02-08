/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshigeto <yshigeto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:56:28 by yshigeto          #+#    #+#             */
/*   Updated: 2026/02/08 22:22:06 by yshigeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	add(int i)
{
	int	count;

	count = 1;
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

void	ft_putnbr(int nb)
{
	int	c;
	char	k;

	k = nb + '0';
	c = add(nb)+1;
	write(1, &k, c);
	
}

int main()
{
	ft_putnbr(9876543);
	return(0);
}
