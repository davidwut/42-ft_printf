/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 23:59:17 by dwuthric          #+#    #+#             */
/*   Updated: 2022/07/13 06:14:03 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	conversion cspdiuxX%
	c - character
	s - string of characters
	p - pointer adress
	d - signed decimal integer
	i - signed decimal integer
	u - unsigned decimal integer
	x - unsigned hex integer, lowercase
	X - unsigned hex integer, uppercase
	% - print %

	flags -0.*
	- - Left-justify within the given field width; Right justification is the default
	0 - Left-pads the number with zeroes (0) instead of spaces

*/

void	ft_printf_init(int *state)
{
	*state = STATE_NORMAL;
}

int	ft_printf(const char *fmt, ...)
{
	int	state;
	va_list args;

	ft_printf_init(&state);
	va_start(args, fmt);
	while (*fmt)
	{
		ft_printf_state_normal(&state, &fmt);
		ft_printf_state_specifier(&state, &fmt, args);
		ft_printf_init(&state);
		fmt++;
	}
	va_end(args);
	return (1);
}

void	ft_printf_state_normal(int *state, const char **fmt)
{
	if (*state == STATE_NORMAL)
		{
			if (**fmt == '%')
				*state = STATE_SPECIFIER;
			else
				ft_putchar(**fmt);
		}
}

/*
	conversion cspdiuxX%
	c - character
	s - string of characters
	p - pointer adress
	d - signed decimal integer
	i - signed decimal integer
	u - unsigned decimal integer
	x - unsigned hex integer, lowercase
	X - unsigned hex integer, uppercase
	% - print %
*/

void	ft_printf_state_specifier(int *state, const char **fmt, va_list args)
{
	if (*state == STATE_SPECIFIER)
		{
			fmt[0]++;
			if (**fmt == 'c')
				ft_putchar(va_arg(args, int));
			else if (**fmt == 's')
				ft_putstr(va_arg(args, char*));
			else if (**fmt == 'p')
				ft_putstr("POINTER");
			else if (**fmt == 'd' || **fmt == 'i')
				ft_putnbr(va_arg(args, int));
			else if (**fmt == '%')
				ft_putchar('%');
		}
}
