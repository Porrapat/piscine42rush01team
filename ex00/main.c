/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:54:52 by mmaythaw          #+#    #+#             */
/*   Updated: 2021/10/31 21:26:22 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

//check if the height I want to put is placeable
//make sure that no num repeating in current row and column
//return 1 if not placeable else 0
int	ft_check_placeable(int **answer, int pos, int numtoput)
{
	int	row;
	int	column;

	row = -1;
	column = -1;
	while (++row < pos / 4)
	{
		if (answer[row][pos % 4] == numtoput)
			return (1);
	}
	while (++column < pos % 4)
	{
		if (answer[pos / 4][column] == numtoput)
			return (1);
	}
	return (0);
}

/*	i(0)	i(1)	i(2)	i(3)
 
 i(8)	pos(0)	pos(1)	pos(2)	pos(3)	i(12)
 
 i(9)	pos(4)	pos(5)	pos(6)	pos(7)	i(13)
 
 i(10)	pos(8)	pos(9)	pos(10)	pos(11)	i(14)
 
 i(11)	pos(12)	pos(13)	pos(14)	pos(15)	i(15)

 	i(4)	i(5)	i(6)	i(7)	
*/
//i(x) = index x of edgeclue
//pos(x) = position in answerboard when pos == x
//row use / 4 and column use % 4 for pos
//ft_check_case will check the whole board considering the edgeclue
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
			answer[pos / 4][pos % 4] = height;
			if (ft_check_case(answer, pos, edgeclue) == 0)
			{
				if (ft_solve(answer, edgeclue, pos + 1) == 1)
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
	while (++row < 4)
	{
		column = -1;
		while (++column < 4)
		{
			ft_putnbr(answer[row][column]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int	main(int ac, char **av)
{
	int	**answer;
	int	*edgeclue;

	if (ft_check(ac, av) == 1)
		return (0);
	edgeclue = ft_get_numbers(av[1]);
	answer = ft_initialize_answerboard(4);
	if (ft_solve(answer, edgeclue, 0) == 1)
		ft_display(answer);
	else
	{
		ft_putstr("Did not find any solutions\n");
	}
	return (0);
}
// ft_check will check if the argument is useable or not
// if useable convert argument's string to int array
// and initialize answer board then solve puzzle
