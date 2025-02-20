/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchafiki <mchafiki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:26:17 by mchafiki          #+#    #+#             */
/*   Updated: 2025/02/21 00:26:18 by mchafiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_strlen(char	*str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(str[i] == '0')
		i++;
	while(str[i])
	{
		j++;
		i++;
	}
	return (j);
}

void	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
int     ft_atoi(const char *str)
{
	int             i;
	long    result;

        result = 0;
        i = 0;
        while ((str[i] > 8 && str[i] <= 13) || str[i] == 32)
                i++;
        while (str[i] >= '0' && str[i] <= '9')
        {
                result = result * 10 + (str[i] - '0');
                i++;
        }
        return (result);
}

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		else
		{
			write(1, "-", 1);
			n = -n;
		}
	}
	if (n <= 9)
	{
		c = n + '0';
		ft_putchar(c);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
