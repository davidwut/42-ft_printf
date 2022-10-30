/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:33:51 by dwuthric          #+#    #+#             */
/*   Updated: 2022/10/30 22:25:05 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef unsigned long long	t_ull;
typedef __uint8_t			t_bool;

enum	e_bool{
	false,
	true
};

typedef struct s_info
{
	int			fd;
	int			done;
	int			upper;
	__uint32_t	flags;
}	t_info;

// ft_printf.c
int			ft_printf(const char *fmt, ...);
int			ft_vfprintf(int fd, const char *fmt, va_list args);
int			ft_vprintf(const char *fmt, va_list args);
void		init_info(t_info *info, int fd);
void		reset_info(t_info *info);

// ft_printf_utils1.c
const char	*parse_flags(const char *fmt, t_info *info);
const char	*parse_width(const char *fmt, t_info *info);
const char	*parse_precision(const char *fmt, t_info *info);
const char	*parse_length(const char *fmt, t_info *info);
const char	*parse_specifier(const char *fmt, t_info *info, va_list args);

// ft_printf_utils2.c
void		_putc(t_info *info, char c);
void		_puts(t_info *info, char *str);
void		_putptr(t_info *info, va_list args);
void		_putbigx(t_info *info, va_list args);
void		_putnum(t_info *info, va_list args, t_bool sign, int radix);

// ft_printf_utils3.c
size_t		ft_strlen(const char *str);
int			ft_tolower(int c);
int			ft_toupper(int c);

// ft_printf_utils4.c
void		_put_signed_number(t_info *info, long long num, int radix);
void		_put_unsigned_number(t_info *info, t_ull num, int radix);

#endif
