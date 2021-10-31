/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:30:19 by mmaythaw          #+#    #+#             */
/*   Updated: 2021/10/31 21:19:53 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

int	ft_changetonum(char *str)
{
	int	num;

	num = 0;
	if (*str >= '0' && *str <= '9')
		num = num * 10 + (*str - '0');
	return (num);
}

void	ft_putnbr(int nb)
{
	if (nb / 10 != 0)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}
