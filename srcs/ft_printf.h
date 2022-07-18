/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 23:59:44 by dwuthric          #+#    #+#             */
/*   Updated: 2022/07/17 17:38:23 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# include "../includes/libft.h"

# define STATE_DEFAULT		0
# define STATE_FLAGS		1
# define STATE_WIDTH		2
# define STATE_PRECISION	3
# define STATE_LENGTH		4
# define STATE_SPEC			5

# define LENGTH_DEFAULT		0
# define LENGTH_LONG		1
# define LENGTH_LONGLONG	2
# define LENGTH_SHORT		3
# define LENGTH_SHORTSHORT	4

# define FLAGS_LEFT		(1U << 0U)
# define FLAGS_ZERO		(1U << 1U)
# define FLAGS_PLUS		(1U << 2U)
# define FLAGS_HASH		(1U << 3U)
# define FLAGS_SPACE	(1U << 4U)
# define FLAGS_STAR		(1U << 5U)
# define FLAGS_UPPER	(1U << 6U)


typedef unsigned long long t_ull;
typedef __uint8_t	t_bool;
# define true 1
# define false 0

typedef struct s_info
{
	int			fd;
	int			state;
	int			length;
	int			size;
	int			pad_size;
	int			precision;
	__uint32_t	flags;
}	t_info;

int		ft_printf(const char *fmt, ...);

int		ft_vfprintf(int fd, const char *fmt, va_list args);
int		ft_vprintf(const char *fmt, va_list args);

void	_init_info(t_info *info, int fd);
void	_reset_info(t_info *info);

void	_state_default(const char **fmt, t_info *info);
void	_state_flags(const char **fmt, t_info *info);
void	_state_width(const char **fmt, t_info *info);
void	_state_precision(const char **fmt, t_info *info);
void	_state_length(const char **fmt, t_info *info);
void	_state_spec(const char **fmt, va_list args, t_info *info);

void	_putnum(va_list args, t_info *info, t_bool sign, int radix);
void	ft_printf_signed_number(long long n, int radix, t_info *info);
void	ft_printf_unsigned_number(t_ull n, int radix, t_info *info);

void	_putc(char c, t_info *info);
void	_puts(char *str, t_info *info);

void	padder(int strlen, t_info *info);
void	_pad_str(char *str, t_info *info);

int _atoi(const char **str);

#endif
