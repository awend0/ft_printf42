/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasvv <awendo@mail.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:14:39 by hasvv             #+#    #+#             */
/*   Updated: 2020/11/24 16:49:39 by hasvv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLG_NONE	0b00000000
# define FLG_MINUS	0b00000001
# define FLG_ZERO	0b00000010
# define FLG_HASH	0b00000100
# define FLG_SPACE	0b00001000
# define FLG_PLUS	0b00010000
# define FLG_ERROR	0b10000000

# include <stdarg.h>
# include <ctype.h>

typedef struct		s_tab
{
	va_list			args;
	unsigned char	flags;
	char			type;
	int				width;
	int				precision;
	char			len;
}					t_tab;

char				ft_parse_type(const char *format);
unsigned char		ft_parse_flags(const char **format, t_tab *tab);
int					ft_parse_width(const char **format, t_tab *tab);
int					ft_parse_prec(const char **format, t_tab *tab);
char				ft_parse_len(const char **format, t_tab *tab);

#endif
