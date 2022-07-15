/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 07:12:35 by dwuthric          #+#    #+#             */
/*   Updated: 2022/07/15 09:56:06 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	_putnum(va_list args, t_info *info, t_bool sign, int radix)
{
	int	length;

	length = info->length;
	if (sign)
	{
		if (length == LENGTH_DEFAULT || length == LENGTH_SHORT || length == LENGTH_SHORTSHORT)
			ft_printf_signed_number(va_arg(args, int), radix, info);
		else if (length == LENGTH_LONG)
			ft_printf_signed_number(va_arg(args, long), radix, info);
		else if (length == LENGTH_LONGLONG)
			ft_printf_signed_number(va_arg(args, long long), radix, info);
	}
	else
	{
		if (length == LENGTH_DEFAULT || length == LENGTH_SHORT || length == LENGTH_SHORTSHORT)
			ft_printf_unsigned_number(va_arg(args, unsigned int), radix, info);
		else if (length == LENGTH_LONG)
			ft_printf_unsigned_number(va_arg(args, unsigned long), radix, info);
		else if (length == LENGTH_LONGLONG)
			ft_printf_unsigned_number(va_arg(args, unsigned long long), radix, info);
	}
}

void	ft_printf_signed_number(long long n, int radix, t_info *info)
{
	if (info->length == LENGTH_SHORT || info->length == LENGTH_SHORTSHORT)
		n = (short) n;
	if (n < 0)
	{
		_putc('-', info);
		ft_printf_unsigned_number(-n, radix, info);
	}
	else
		ft_printf_unsigned_number(n, radix, info);
}

void	ft_printf_unsigned_number(t_ull n, int radix, t_info *info)
{
	char	*hex;
	char	buffer[50];
	int		i;

	int (*f)(int) = ft_tolower;
	if (info->upper)
		f = ft_toupper;
	hex = "0123456789abcdef";
	i = 0;
	buffer[i++] = f(hex[n % radix]);
	n /= radix;
	while (n)
	{
		buffer[i++] = f(hex[n % radix]);
		n /= radix;
	}
	while (i-- > 0)
		_putc(buffer[i], info);
}
