/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:56:38 by dwuthric          #+#    #+#             */
/*   Updated: 2022/10/30 22:13:40 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	_put_signed_number(t_info *info, long long num, int radix)
{
	if (num < 0)
	{
		_putc(info, '-');
		_put_unsigned_number(info, -num, radix);
	}
	else
		_put_unsigned_number(info, num, radix);
}

void	_put_unsigned_number(t_info *info, t_ull num, int radix)
{
	char	*hex;
	char	buffer[50];
	int		i;
	int		(*adjust)(int);

	adjust = ft_tolower;
	if (info->upper)
		adjust = ft_toupper;
	hex = "0123456789abcdef";
	i = 0;
	buffer[i++] = adjust(hex[num % radix]);
	num /= radix;
	while (num)
	{
		buffer[i++] = adjust(hex[num % radix]);
		num /= radix;
	}
	while (i-- > 0)
		_putc(info, buffer[i]);
}
