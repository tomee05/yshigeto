#include <unistd.h>

void ft_print_comb2(void)
{
  int i,j,k,l;
  i=-1;
  while (++i<=9)
  {
    j=i;
    while (++j<=8)
      {
        write(1, &i, 1);
        write(1, &j, 1);
        write(1, " ", 1);
      }
  }

  k=-1;
  while (++k<=9)
  {
    l=k;
    while(++l<=9)
      {
        write(1, &k, 1);
        write(1, &l, 1);
        if (!(k == 98 && l == 99))
        	{
        		write(1, ", ", 2);
        	}
      }
  }
