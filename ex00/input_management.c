/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:36:20 by mmaythaw          #+#    #+#             */
/*   Updated: 2021/10/31 21:28:16 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>

int	ft_check_unwanted(char *argstr)
{
	while (*argstr)
	{
		if (!(*argstr == ' ' || (*argstr >= '0' && *argstr <= '4')))
		{
			ft_putstr("Error: Unwanted character in input string\n");
			ft_putstr("Only space and integer character are allowed\n");
			ft_putstr("The integer must be from 0 to 4 only\n");
			return (1);
		}
		argstr++;
	}
	return (0);
}

//check count, format, length
//and unwated character in argument
//if there is any anomaly return 1
int	ft_check(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("Error: Argument format\n");
		ft_putstr("Argument format: ./rush-01 \"num num num num ....\"\n");
		return (1);
	}
	if (ft_check_unwanted(&av[1][0]))
		return (1);
	if (ft_strlen(av[1]) != 31)
	{
		ft_putstr("Error: Edge clue count\n");
		ft_putstr("Input must be a string of space sepearated integers\n");
		ft_putstr("The count of integer must be a total of 16\n");
		ft_putstr("Example: \"num num num num ....\"\n");
		return (1);
	}
	return (0);
}

// convert argument's string to integer array
int	*ft_get_numbers(char *argstr)
{
	int	charnum;
	int	index;
	int	*input;

	input = malloc(sizeof(int) * 17);
	charnum = 0;
	index = 0;
	while (argstr[charnum] != '\0')
	{
		if (argstr[charnum] >= '0' && argstr[charnum] <= '4')
		{
			input[index] = ft_changetonum(argstr + charnum);
			index++;
		}
		charnum++;
	}
	return (input);
}

int	**ft_initialize_answerboard(int size)
{
	int	**arr;
	int	index;

	index = 0;
	arr = malloc(sizeof(int) * size + 1);
	while (index < size)
	{
		arr[index] = malloc(sizeof(int) * size + 1);
		index++;
	}
	return (arr);
}
