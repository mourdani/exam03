/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 03:05:36 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/18 23:17:14 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * create functions :
 * 	putchar, putstr, putnbr, putint.
 *
 * ft_printf :
 * 	va_list :
 * 		va_list to declare.
 * 		va_start(args, first arg) to initialize.
 * 		va_arg(type) to access.
 * 		va_end(args) to end.
 *
 * 	- loop inside str:
 * 		- if (str[i] = %)
 * 			- increment i.
 * 			- convert x with putnbr.
 * 			- convert s with putstr.
 * 			- convert d with putint.
 * 			- return of the conversion gets added to count.
 * 		- else, print str[i].
 * 		- increment i.
 * 	- return (count).
*/

#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int i = 0;

	if (!str)
		str = "(null)";
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return(i);
}

int	ft_putnbr(unsigned int i, int base)
{
	char *base_set	= "0123456789abcdef";
	int n		= i % base;
	int count	= 0;

	if (i / base > 0)
		count += ft_putnbr(i / base, base);
	count += ft_putchar(base_set[n]);
	return (count);
}

int	ft_putint(int i)
{
	int count = 0;
	if (i < 0)
	{
		ft_putchar('-');
		i *= -1;
		count++;
	}
	count += ft_putnbr(i, 10);
	return (count);
}

int	ft_printf(char *str, ...)
{
	va_list args;
	int i		= 0;
	int count	= 0;

	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if(str[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			if(str[i] == 'd')
				count += ft_putint(va_arg(args, int));
			if(str[i] == 'x')
				count += ft_putnbr(va_arg(args, unsigned int), 16);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

/*
int main()
{
	ft_printf("this is a %s\n", "test");
	ft_printf("%s\n", "toto");
	ft_printf("Magic %s is %d\n", "number", -42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);

}
*/
