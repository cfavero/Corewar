/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:48:38 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/09 18:53:03 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_get_value(t_pars **lst, int k, int i, int code, char *line, int counter)
{
	int j;

	if (code != 3)
		i++;
	j = i;
	(*lst)->type[k] = code;
	while (line[j] && line[j] != ',' && line[j] != ' ')
		j++;
	(*lst)->value[k] = ft_strndup(&line[i], j - i);
	if (line[j] == ',')
		j++;
	i = j;
	ft_error_values((*lst)->value[k], code, counter);
	return (i);
}

t_pars		*ft_get_type(char *line, t_pars *lst, int counter)
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
		ft_exit("Need params", counter);
	while (line[i] && k < 3)
	{
		j = 0;
		if (line[i] == 'r')
			i = ft_get_value(&lst, k, i, REG_CODE, line, counter);
		else if (line[i] == '%')
			i = ft_get_value(&lst, k, i, DIR_CODE, line, counter);
		else if (ft_isdigit(line[i]) == 1)
			i = ft_get_value(&lst, k, i, IND_CODE, line, counter);
		else if (line[i] && (line[i] != ' ' && line[i] != '\t'))
			ft_exit("Error in the params", counter);
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		k++;
	}
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i])
		ft_exit("Error after the params", counter);
	ft_check_opname_type(lst, lst->op_code, counter);
	return (lst);
}

// check if ft_strdup return NULL
