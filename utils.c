/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:12:17 by arashido          #+#    #+#             */
/*   Updated: 2023/03/12 17:41:52 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
  unsigned int i;
  long  sign;
  long  res;

  i = 0;
  res = 0;
  sign = 1;

  while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
    i++;
  while (str[i] == '-'  || str[i] == '+')
  {
    if (str[i] == '-')
      sign *= -1;
    i++;
  }
  while (str[i] >= '0' && str[i] <= '9')
  {
    res = res * 10 + str[i] - 48;
    i++;
  }
  return ((int)(res * sign));
}

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}