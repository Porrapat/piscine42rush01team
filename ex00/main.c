/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:54:52 by mmaythaw          #+#    #+#             */
/*   Updated: 2021/10/31 14:54:59 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	ft_check_placeable(int **answer, int pos, int numtoput)
{
	int	i;

	i = -1;
	while (++i < pos / 4)
	{
		if (answer[i][pos % 4] == numtoput)
			return (1);
	}
	i = -1;
	while (++i < pos % 4)
	{
		if (answer[pos / 4][i] == numtoput)
			return (1);
	}
	return (0);
}

int	ft_solve(int **answer, int *edgeclue, int pos)
{
	int	height;

	if (pos == 16)
		return (1);
	height = 0;
	while (++height <= 4)
	{
		if (ft_check_placeable(answer, pos, height) == 0)
		{
			answer[pos / 4][pos % 4] = size;
			if (ft_check_case(answer, pos, edgeclue) == 0)
			{
				if (solve(answer, edgeclue, pos + 1) == 1)
					return (1);
			}
			else
				answer[pos / 4][pos % 4] = 0;
		}
	}
	return (0);
}

void	ft_display(int **answer)
{
	int	row;
	int	column;

	row = -1;
	while (++i < 4)
	{
		column = -1;
		while (++j < 4)
		{
			ft_putnbr(answer[row][column]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int	main(int ac, char **av)
{
	int	answer[4][4];
	int	*edgeclue;

	if (check(ac, av) == 1)
		return (0);
	edgeclue = get_numbers(av[1]);
	if (ft_checkedge(edgeclue))
	{
		ft_putstr("Did not find any solutions\n");
		return (0);
	}
	answer = {
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	};
	else if (ft_solve(answer, edgeclue, 0) == 1)
		ft_display(answer);
	else
		ft_putstr("Did not find any solutions\n");
	return (0);
}
