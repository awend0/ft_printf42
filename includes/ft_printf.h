/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasvv <awendo@mail.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:14:39 by hasvv             #+#    #+#             */
/*   Updated: 2020/11/26 05:10:13 by hasvv            ###   ########.fr       */
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
# include <wctype.h>
# include <wchar.h>
# include <stdio.h>
# include <stdint.h>

typedef struct		s_tab
{
	va_list			args;
	unsigned char	flags;
	char			type;
	int				width;
	int				precision;
	char			len;
	int				negw;
	int				negp;
	int				tmp;
}					t_tab;

char				ft_parse_type(const char *format);
unsigned char		ft_parse_flags(const char **format, t_tab *tab);
int					ft_parse_width(const char **format, t_tab *tab);
int					ft_parse_prec(const char **format, t_tab *tab);
char				ft_parse_len(const char **format, t_tab *tab);
int					ft_parser(const char **format, t_tab *tab);

int					ft_processor(t_tab *tab);
int					ft_display_d(t_tab *tab);
int					ft_display_c(t_tab *tab);
int					ft_display_s(t_tab *tab);
int					ft_display_p(t_tab *tab);
int					ft_display_u(t_tab *tab);
int					ft_display_x(t_tab *tab);
int					ft_display_wchar(wint_t c);
int					ft_display_gap(int n, char c);

t_tab				*ft_handle_star(t_tab *tab);
void				ft_debug(t_tab *tab);
#endif
