/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:01:25 by mmaythaw          #+#    #+#             */
/*   Updated: 2021/10/31 15:01:29 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_putstr(char *str);

int		ft_changetonum(char *str);
int		ft_strlen(char *str);
int		*ft_get_numbers(char *str);
int		ft_check(int ac, char **av);
int		ft_check_case(int **answer, int pos, int *edgeclue);
int		ft_checkedge(int *edgeclue);

#endif
