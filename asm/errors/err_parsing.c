/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:47:44 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/11 22:23:36 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_pars		*ft_check_opname_type(t_pars *l, int i, int counter)
{
	int		j;
	t_op	op_tab;

	j = 0;
	op_tab = all_info(i - 1);
	while (j < op_tab.nb_params)
	{
		// ft_printf("j = %d	my_type = %d	accepted types %d	op_code %d\n", j, l->type[j], op_tab.type[j], i);
		if (!(l->type[j] & op_tab.type[j]))
			ft_exit("The params are wrong for the op type", counter);
		l->dir_size = (op_tab.mod_dir == 1) ? 2 : 4;
		// ft_printf("%d\n", l->dir_size);
		j++;
	}
	return (l);
}

void	ft_error_head_name(char *line, char *name)
{
	int	i;

	line = ft_comment_delete(line);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_strncmp(&line[i], name, ft_strlen(name)) != 0)
		ft_exit("Error in the header", 0);
	i = i + ft_strlen(name);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	(line[i] != '"') ? ft_exit("Error in the header", 0) : i++;
	while (line[i] && line[i] != '"')
		i++;
	line[i] ? i++ : i;
	while ((line[i] == ' ' || line[i] == '\t') && line[i])
		i++;
	if (line[i])
		ft_exit("Error in the header", 0);
}

void	ft_error_values(char *value, int code, int counter)
{
	if (code == DIR_CODE && *value == ':')
	{
		value++;
		while (value && (ft_isalnum(*value) == 1 || *value == '_'))
			value++;
		if (value && *value)
			ft_exit("Not a valid digit in the param value", counter);
	}
	else if (code == IND_CODE && *value == '-')
	{
		value++;
		while (value && (ft_isdigit(*value) == 1))
			value++;
		if (value && *value)
			ft_exit("Not a digit in the param IND_CODE", counter);
	}
	else
	{
		if (code == DIR_CODE && *value == '-')
			value++;
		while (value && (ft_isdigit(*value) == 1))
			value++;
		while (value && (*value == ' ' || *value == '\t'))
			value++;
		if (value && *value)
			ft_exit("Not a digit in the param value", counter);
	}
}

void	ft_check_label(t_pars *l, int i, int counter)
{
	while (l->label[i])
	{
		if (ft_isalnum(l->label[i]) == 1 || l->label[i] == '_')
			i++;
		else
			ft_exit("Error in the label name", counter);
	}
}
