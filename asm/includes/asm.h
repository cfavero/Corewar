/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:36:54 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/05 20:02:57 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
#define ASM_H
# include "ft_printf.h"

typedef struct		s_pars
{
	char			*line;
	char			*label;
	char			*comment;
	char			*op_name;
	int				op_code;
	int				size_code;
	char			*param;
	int				*type[3];
	char			*line_code;
	struct s_pars	*next;
}					t_pars;
typedef struct		s_bitch
{
	char			*label
	char			*final_line;
	struct s_pars	*next;
}					t_bitch;
#endif
