/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 23:59:17 by dwuthric          #+#    #+#             */
/*   Updated: 2022/07/18 08:27:29 by dwuthric         ###   ########.fr       */
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

	length l ll h hh

	%[flags][width][.precision][length]spec

	% 6.4d
	[  0001]
	[123456]  width
	[12]
	   [1234] precision


*/

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		done;

	va_start(args, fmt);
	done = ft_vprintf(fmt, args);
	va_end(args);
	return (done);
}

int		ft_vprintf(const char *fmt, va_list args)
{
	return (ft_vfprintf(STDOUT_FILENO, fmt, args));
}

int	ft_vfprintf(int fd, const char *fmt, va_list args)
{
	t_info	info;

	_init_info(&info, fd);
	while (*fmt)
	{
		_reset_info(&info);
		_state_default(&fmt, &info);
		_state_flags(&fmt, &info);
		_state_width(&fmt, &info);
		_state_precision(&fmt, &info);
		_state_length(&fmt, &info);
		_state_spec(&fmt, args, &info);
		fmt++;
	}
	return (info.size);
}

void	_state_default(const char **fmt, t_info *info)
{
	if (**fmt != '%')
			_putc(**fmt, info);
		else
			info->state = STATE_FLAGS;
}

void	_state_flags(const char **fmt, t_info *info)
{
	if (info->state == STATE_FLAGS)
	{
		fmt[0]++;
		while (1)
		{
			if (**fmt == '-')
				info->flags |= FLAGS_LEFT;
			else if (**fmt == '0')
				info->flags |= FLAGS_ZERO;
			else if (**fmt == '+')
				info->flags |= FLAGS_PLUS;
			else if (**fmt == '#')
				info->flags |= FLAGS_HASH;
			else if (**fmt == ' ')
				info->flags |= FLAGS_SPACE;
			else if (**fmt == '*')
				info->flags |= FLAGS_STAR;
			else
				break ;
			fmt[0]++;
		}
		info->state = STATE_WIDTH;
		fmt[0]--;
	}
}

void	_state_width(const char **fmt, t_info *info)
{
	int	n;

	n = 0;
	if (info->state == STATE_WIDTH)
	{
		fmt[0]++;
		n = _atoi(fmt);
		info->state = STATE_PRECISION;
		fmt[0]--;
	}
	info->pad_size = n;
}

void	_state_precision(const char **fmt, t_info *info)
{
	int	n;

	n = 0;
	if (info->state == STATE_PRECISION)
	{
		fmt[0]++;
		if (**fmt == '.')
		{
			fmt[0]++;
			n = _atoi(fmt);
		}
		info->state = STATE_LENGTH;
		fmt[0]--;
	}
	info->precision = n;
}

void	_state_length(const char **fmt, t_info *info)
{
	if (info->state == STATE_LENGTH)
	{
		fmt[0]++;
		if (**fmt == 'h')
		{
			info->length = LENGTH_SHORT;
			fmt[0]++;
			if (**fmt == 'h')
				info->length = LENGTH_SHORTSHORT;
		}
		else if (**fmt == 'l')
		{
			info->length = LENGTH_LONG;
			fmt[0]++;
			if (**fmt == 'l')
				info->length = LENGTH_LONGLONG;
		}
		if (info->length == LENGTH_LONGLONG || info->length == LENGTH_SHORTSHORT)
			fmt[0]++;
		info->state = STATE_SPEC;
		fmt[0]--;
	}
}

void	_state_spec(const char **fmt, va_list args, t_info *info)
{
	if (info->state == STATE_SPEC)
	{
		fmt[0]++;
		if (**fmt == 'c')
			_putc(va_arg(args, int), info);
		else if (**fmt == 's')
			_pad_str(va_arg(args, char*), info);
		else if(**fmt == '%')
			_putc('%', info);
		else if(**fmt == 'd' || **fmt == 'i')
			_putnum(args, info, true, 10);
		else if(**fmt == 'u')
			_putnum(args, info, false, 10);
		else if(**fmt == 'o')
			_putnum(args, info, false, 8);
		else if(**fmt == 'x')
			_putnum(args, info, false, 16);
		else if(**fmt == 'X')
		{
			info->flags |= FLAGS_UPPER;
			_putnum(args, info, false, 16);
		}
		else if (**fmt == 'p')
		{
			_puts("0x", info);
			_putnum(args, info, false, 16);
		}
		else
			fmt--;
		fmt++;
	}
}

void	_pad_str(char *str, t_info *info)
{
	padder(ft_strlen(str), info);
	_puts(str, info);
	if (info->flags & FLAGS_LEFT)
		padder(ft_strlen(str), info);
}

void	_init_info(t_info *info, int fd)
{
	info->fd = fd;
	info->state = STATE_DEFAULT;
	info->length = LENGTH_DEFAULT;
	info->size = 0;
	info->flags = 0U;
	info->pad_size = 0;
	info->precision = 0;
}

void	_reset_info(t_info *info)
{
	info->state = STATE_DEFAULT;
	info->length = LENGTH_DEFAULT;
	info->flags = 0U;
	info->pad_size = 0;
	info->precision = 0;
}

void	_putc(char c, t_info *info)
{
	info->size++;
	ft_putchar_fd(c, info->fd);
}

void	_puts(char *str, t_info *info)
{
	info->size += ft_strlen(str);
	ft_putstr_fd(str, info->fd);
}

void	padder(int strlen, t_info *info)
{
	char	c;
	int		diff;

	c = ' ';
	if (info->flags & FLAGS_ZERO)
		c = '0';
	diff = info->pad_size - strlen;
	if (diff <= 0)
		return ;
	while (diff--)
		_putc(c, info);
}

int _atoi(const char **str)
{
	int	total;

	total = 0;
	while (**str && '0' <= **str && **str <= '9')
	{
		total = total * 10 + **str - '0';
		str[0]++;
	}
	return (total);
}
