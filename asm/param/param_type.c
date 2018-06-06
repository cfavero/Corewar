/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:48:38 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/06 21:18:57 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_pars		*ft_get_type(char *line, t_pars *lst)
{
	int i;
	int k;
	int j;

	k = 0;
	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!line[i] && !lst->op_name)
		return (lst);
	else if (!line[i] && lst->op_name)
		ft_exit("Need params");
	while (line[i] && k < 3)
	{
		j = 0;
		if (line[i] == 'r')
		{
			i++;
			j = i;
			lst->type[k] = REG_CODE;
			while (line[j] && line[j] != ',' && line[j] != ' ')
				j++;
			lst->value[k] = ft_strndup(&line[i], j - i);
			i = j;
			ft_printf("type[%d] = %#0.2x, value = %s\n", k, lst->type[k], lst->value[k]);
		}
		else if (line[i] == '%')
		{
			i++;
			j = i;
			lst->type[k] = DIR_CODE;
			while (line[j] && line[j] != ',' && line[j] != ' ')
				j++;
			lst->value[k] = ft_strndup(&line[i], j - i);
			i = j;
			ft_printf("type[%d] = %#0.2x, value = %s\n", k, lst->type[k], lst->value[k]);
		}
		else if (ft_isdigit(line[i]) == 1)
		{
			j = i;
			lst->type[k] = IND_CODE;
			while (line[j] && line[j] != ',' && line[j] != ' ')
				j++;
			lst->value[k] = ft_strndup(&line[i], j - i);
			i = j;
			ft_printf("type[%d] = %#0.2x, value = %s\n", k, lst->type[k], lst->value[k]);
		}
		else if (line[i] && (line[i] != ' ' || line[i] != '\t'))
			ft_exit("Error in the params");
		i++;
		k++;
	}
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i])
		ft_exit("Error in the params");
	ft_check_opname_type(lst, lst->op_code);
	return (lst);
}

// check if ft_strdup return NULL
