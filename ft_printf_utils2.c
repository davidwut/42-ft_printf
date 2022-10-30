/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:40:11 by dwuthric          #+#    #+#             */
/*   Updated: 2022/10/30 22:25:00 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	_putc(t_info *info, char c)
{
	info->done += 1;
	write(info->fd, &c, 1);
}

void	_puts(t_info *info, char *str)
{
	int	len;

	len = ft_strlen(str);
	info->done += len;
	write(info->fd, str, len);
}

void	_putptr(t_info *info, va_list args)
{
	_puts(info, "0x");
	_putnum(info, args, false, 16);
}

void	_putbigx(t_info *info, va_list args)
{
	info->upper = 1;
	_putnum(info, args, false, 16);
}

void	_putnum(t_info *info, va_list args, t_bool sign, int radix)
{
	if (sign)
	{
		_put_signed_number(info, va_arg(args, int), radix);
	}
	else
	{
		_put_unsigned_number(info, va_arg(args, unsigned int), radix);
	}
}