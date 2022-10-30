/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:47:37 by dwuthric          #+#    #+#             */
/*   Updated: 2022/10/30 23:22:05 by dwuthric         ###   ########.fr       */
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

	%[flags][width][.precision][length]specifier

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

int	ft_vprintf(const char *fmt, va_list args)
{
	return (ft_vfprintf(STDOUT_FILENO, fmt, args));
}

int	ft_vfprintf(int fd, const char *fmt, va_list args)
{
	t_info	info;

	init_info(&info, fd);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			fmt = parse_flags(fmt, &info);
			fmt = parse_width(fmt, &info);
			fmt = parse_precision(fmt, &info);
			fmt = parse_length(fmt, &info);
			fmt = parse_specifier(fmt, &info, args);
		}
		else
			info.done += write(fd, fmt++, 1);
		reset_info(&info);
	}
	return (info.done);
}

void	init_info(t_info *info, int fd)
{
	info->fd = fd;
	info->done = 0;
	reset_info(info);
}

void	reset_info(t_info *info)
{
	info->flags = 0;
	info->upper = 0;
}
