/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 02:15:38 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/15 02:29:44 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int i;

	while (str[i])
		i++;
	return (i);
}

int	check_dup(char *str, int pos, char c)
{
	int i = 0;

	while (str[i] && i  < pos)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_union(char *str1, char *str2)
{
	int i = 0;
	int j = 0;

	while (str1[i])
	{
		if (check_dup(str1, i, str1[i]))
			write(1, &str1[i], 1);
		i++;
	}
	while (str2[j])
	{
		if (check_dup(str2, j, str2[j]) && check_dup(str1, ft_strlen(str1), str2[j]))
			write(1, &str2[j], 1);
		j++;
	}
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_union(av[1], av[2]);
		return (0);
	}
	write(1, "\n", 1);
	return (0);
}
