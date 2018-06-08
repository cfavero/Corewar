/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:47:44 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/07 18:01:14 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_check_opname_type(t_pars *l, int i)
{
	if ((i == 1 || i == 9 || 1 == 12 || i == 15) && (l->type[0] != 2 \
		|| l->type[1] != 0 || l->type[2] != 0))
		ft_exit("The params are wrong for the op type");
	else if ((i == 4 || i == 5) && (l->type[0] != 1 || l->type[1] != 1 \
		|| l->type[2] != 1))
		ft_exit("The params are wrong for the op type");
	else if ((i == 6 || i == 7 || i == 8) && (l->type[2] != 1))
		ft_exit("The params are wrong for the op type");
	else if ((i == 2 || i == 13) && (l->type[0] == 1 || l->type[1] != 1 \
		|| l->type[2] != 0))
		ft_exit("The params are wrong for the op type");
	else if (i == 16 && (l->type[0] != 1 || l->type[1] != 0 || l->type[2] != 0))
		ft_exit("The params are wrong for the op type");
	else if (i == 10 && (l->type[2] != 1 || l->type[1] == 1))
		ft_exit("The params are wrong for the op type");
	else if (i == 11 && (l->type[0] != 1 || l->type[2] == 1))
		ft_exit("The params are wrong for the op type");
	else if (i == 14 && (l->type[1] == 1 || l->type[2] != 1))
		ft_exit("The params are wrong for the op type");
	else if (i == 3 && (l->type[0] != 1 || l->type[1] == 2 || l->type[2] != 0))
		ft_exit("The params are wrong for the op type");
	return (0);
}

void	ft_error_head_name(char *line, char *name)
{
	int	i;

	line = ft_comment_delete(line);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_strncmp(&line[i], name, ft_strlen(name)) != 0)
		ft_exit("Error in the header");
	i = i + ft_strlen(name);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	(line[i] != '"') ? ft_exit("Error in the header") : i++;
	while (line[i] && line[i] != '"')
		i++;
	line[i] ? i++ : i;
	while ((line[i] == ' ' || line[i] == '\t') && line[i])
		i++;
	if (line[i])
		ft_exit("Error in the header");
}

void	ft_error_values(char *value, int code)
{
	if (code == 2 && *value == ':')
	{
		value++;
		while (value && (ft_isalnum(*value) == 1 || *value == '_'))
			value++;
		if (value && *value)
			ft_exit("Not a valid digit in the param value");
	}
	else
	{
		while (value && (ft_isdigit(*value) == 1))
			value++;
		if (value && *value)
			ft_exit("Not a digit in the param value");
	}
}

void	ft_check_label(t_pars *l, int i)
{
	while (l->label[i])
	{
		if (ft_isalnum(l->label[i]) == 1 || l->label[i] == '_')
			i++;
		else
			ft_exit("Error in the label name");
	}
}
