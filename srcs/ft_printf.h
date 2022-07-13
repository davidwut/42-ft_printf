/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 23:59:44 by dwuthric          #+#    #+#             */
/*   Updated: 2022/07/12 23:54:01 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# include "../includes/libft.h"

# define STATE_NORMAL		0
# define STATE_LENGTH		1
# define STATE_SPECIFIER	2

int		ft_printf(const char *fmt, ...);

void	ft_printf_state_normal(int *state, const char **fmt);
void	ft_printf_state_specifier(int *state, const char **fmt, va_list args);

#endif
