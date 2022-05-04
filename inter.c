/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:28:29 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/15 02:09:33 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** - main: 
** 	- if ac isn't 3 print '\n' and return 0.
**	- if ac is 3:
**		- inside str1:
**			- if no duplicates:
**				- inside str2:
**					- if str1[i] = str2[j]:
**						- print str[i].
**						- break.
**					- else, increment j.
**				- reset j to 0:
**			- else, increment i.
**	- return 0.
*/

#include <unistd.h>

int	check_not_dup(char *str, int i)
{
	int j = 0;

	while (str[j] && j < i)
	{
		if (str[j] == str[i])
			return(0);
		j++;
	}
	return (1);
}


void	inter(char *str1, char *str2)
{
	int i = 0;
	int j = 0;

	while (str1[i])
	{
		if (check_not_dup(str1, i))
		{	
			while (str2[j])
			{
				if (str1[i] == str2[j])
				{
					write(1, &str1[i], 1);
					break;
				}
				j++;
			}
			j = 0;
		}
		i++;
	}
}


int	main(int ac, char **av)
{
	if (ac == 3)
	{
		inter(av[1], av[2]);
		return(0);
	}
	write(1, "\n", 1);
	return (0);
}
