/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edgecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:37:59 by mmaythaw          #+#    #+#             */
/*   Updated: 2021/10/31 16:46:46 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//if there is any abnomaly then return 1

int	ft_checkcorner(int *edgeclue, int i)
{
	if (edgeclue[i] == 1 || edgeclue[i] == 4)
	{
		if ((i == 0 || i == 7) && edgeclue[i] != edgeclue[i + 8])
			return (1);
		else if (i == 3 && edgeclue[i] != edgeclue[i + 9])
			return (1);
		else if (i == 4 && edgeclue[i] != edgeclue[i + 7])
			return (1);
	}
	return (0);
}

int	ft_checkrepeat(int *edgeclue)
{
	int	i;
	int	count1;
	int	count4;

	i = -1;
	count1 = 0;
	count4 = 0;
	while (i++ < 16)
	{
		if (i % 4 == 0)
		{
			count1 = 0;
			count4 = 0;
		}
		if (edgeclue[i] == 1)
			count1++;
		if (edgeclue[i] == 4)
			count4++;
		if (i % 4 == 3)
		{
			if (count1 > 1 || count4 > 1)
				return (1);
		}
	}
	return (0);
}

int	ft_checkoppositeplus(int *edgeclue, int i)
{
	if ((i >= 0 && i <= 3) || (i >= 8 && i <= 11))
	{
		if (edgeclue[i] == 1)
		{
			if (edgeclue[i + 4] != 4)
				return (1);
		}
		else if (edgeclue[i] == 4)
		{
			if (edgeclue[i + 4] != 1)
				return (1);
		}
	}
	return (0);
}

int	ft_checkoppositeminus(int *edgeclue, int i)
{
	if ((i >= 4 && i <= 7) || (i >= 12 && i <= 15))
	{
		if (edgeclue[i] == 1)
		{
			if (edgeclue[i - 4] != 4)
				return (1);
		}
		else if (edgeclue[i] == 4)
		{
			if (edgeclue[i - 4] != 1)
				return (1);
		}
	}
	return (0);
}

int	ft_checkedge(int *edgeclue)
{
	int	i;

	i = -1;
	while (i++ < 16)
	{
		if (ft_checkcorner(edgeclue, i))
			return (1);
		if (ft_checkoppositeplus(edgeclue, i))
			return (1);
		if (ft_checkoppositeminus(edgeclue, i))
			return (1);
	}
	if (ft_checkrepeat(edgeclue))
		return (1);
	return (0);
}
