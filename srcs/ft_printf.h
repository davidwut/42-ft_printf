/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 23:59:44 by dwuthric          #+#    #+#             */
/*   Updated: 2022/07/15 09:55:18 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# include "../includes/libft.h"

# define STATE_DEFAULT		0
# define STATE_LENGTH		1
# define STATE_SPEC			2

# define LENGTH_DEFAULT		0
# define LENGTH_LONG		1
# define LENGTH_LONGLONG	2
# define LENGTH_SHORT		3
# define LENGTH_SHORTSHORT	4

typedef unsigned long long t_ull;
typedef __uint8_t	t_bool;
# define true 1
# define false 0

typedef struct s_info
{
	int	fd;
	int	state;
	int	length;
	int	size;
	int	upper;
}	t_info;

int		ft_printf(const char *fmt, ...);

int		ft_vfprintf(int fd, const char *fmt, va_list args);
int		ft_vprintf(const char *fmt, va_list args);

void	_init_info(t_info *info, int fd);
void	_reset_info(t_info *info);

void	_state_length(const char **fmt, t_info *info);
void	_state_spec(const char **fmt, va_list args, t_info *info);

void	_putnum(va_list args, t_info *info, t_bool sign, int radix);
void	ft_printf_signed_number(long long n, int radix, t_info *info);
void	ft_printf_unsigned_number(t_ull n, int radix, t_info *info);

void	_putc(char c, t_info *info);
void	_puts(char *str, t_info *info);

#endif
