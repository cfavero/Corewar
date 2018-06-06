/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:48:38 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/06 13:50:17 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_pars		*ft_get_type(char *line, t_pars *lst)
{
	// if (r) REG_CODE 01 if (%) 10 else 11
	// type [0] type [1] type [2]
	// if is sm different we say error;
	ft_check_opname_type(lst, lst->op_code);
	return (lst);
}
