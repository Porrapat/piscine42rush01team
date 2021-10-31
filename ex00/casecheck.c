/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:22:32 by mmaythaw          #+#    #+#             */
/*   Updated: 2021/10/31 19:05:59 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_col_up(int **answer, int pos, int *edgeclue)
{
	int	row;
	int	curr_max_height;
	int	visible_towers;

	row = 0;
	curr_max_height = 0;
	visible_towers = 0;
	if (pos / 4 == 3)
	{
		while (row < 4)
		{
			if (answer[row][pos % 4] > curr_max_height)
			{
				curr_max_height = answer[row][pos % 4];
				visible_towers++;
			}
			row++;
		}
		if (edgeclue[pos % 4] != visible_towers)
			return (1);
	}
	return (0);
}

int	ft_check_row_right(int **answer, int pos, int *edgeclue)
{
	int	column;
	int	curr_max_height;
	int	visible_towers;

	column = 3;
	curr_max_height = 0;
	visible_towers = 0;
	if (pos % 4 == 3)
	{
		while (column >= 0)
		{
			if (answer[pos / 4][column] > curr_max_height)
			{
				curr_max_height = answer[pos / 4][column];
				visible_towers++;
			}
			column--;
		}
		if (edgeclue[12 + pos / 4] != visible_towers)
			return (1);
	}
	return (0);
}

int	ft_check_col_down(int **answer, int pos, int *edgeclue)
{
	int	row;
	int	curr_max_height;
	int	visible_towers;

	row = 3;
	curr_max_height = 0;
	visible_towers = 0;
	if (pos / 4 == 3)
	{
		while (row >= 0)
		{
			if (answer[row][pos % 4] > curr_max_height)
			{
				curr_max_height = answer[row][pos % 4];
				visible_towers++;
			}
			row--;
		}
		if (edgeclue[4 + pos % 4] != visible_towers)
			return (1);
	}
	return (0);
}

int	ft_check_row_left(int **answer, int pos, int *edgeclue)
{
	int	column;
	int	curr_max_height;
	int	visible_towers;

	column = 0;
	curr_max_height = 0;
	visible_towers = 0;
	if (pos % 4 == 3)
	{
		while (column < 4)
		{
			if (answer[pos / 4][column] > curr_max_height)
			{
				curr_max_height = answer[pos / 4][column];
				visible_towers++;
			}
			column++;
		}
		if (edgeclue[8 + pos / 4] != visible_towers)
			return (1);
	}
	return (0);
}

int	ft_check_case(int **answer, int pos, int *edgeclue)
{
	if (ft_check_row_left(answer, pos, edgeclue) == 1)
		return (1);
	if (ft_check_row_right(answer, pos, edgeclue) == 1)
		return (1);
	if (ft_check_col_down(answer, pos, edgeclue) == 1)
		return (1);
	if (ft_check_col_up(answer, pos, edgeclue) == 1)
		return (1);
	return (0);
}
