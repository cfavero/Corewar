/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:48:32 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/08 19:24:00 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_pars		*ft_get_label_values(t_pars *l, t_labels *label, int k)
{
	while ((l->type[k] != DIR_CODE || l->value[k][0] != ':') && k < 3)
	{
		if (!l->value[k])
			return (l);
		k++;
	}
	if (k == 3)
		return (l);
	while (label && ft_strequ(&l->value[k][1], label->lst->label) == 0)
		label = label->next;
	if (!label)
		ft_exit("Label name not found");
	if (label->lst->position - l->position > 0)
		l->value[k] = ft_itoa((label->lst->position - l->position) + l->label_size);
	else
		l->value[k] = ft_itoa((label->max_size + ((label->lst->position -\
			 l->position) - l->label_size)));
	if (k != 2)
		l = ft_get_label_values(l, label, k);
	ft_printf("distance %s\n", l->value[k]);
	return (l);
}

void		ft_add_label(t_labels **save, t_pars *labeled)
{
	t_labels *new;
	t_labels *tmp;

	if (!(new = (t_labels*)malloc(sizeof(t_labels))))
		ft_exit("Error malloc t_labels");
	ft_bzero(new, sizeof(t_labels));
	new->lst = labeled;
	if (new)
	{
		if (*save)
		{
			tmp = *save;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		else if (new)
			*save = new;
	}
}

t_pars		*ft_get_label(char *line, t_pars *l, t_labels **save)
{
	char	*s;
	int		len;
	int		i;

	if ((s = ft_strchr(line, LABEL_CHAR)) != NULL)
	{
		(s != line) ? s-- : s;
		if (*s == DIRECT_CHAR || s == line)
			return (l);
		(s != line) ? s++ : s;
		i = 0;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		s[0] = '\0';
		len = ft_strlen(line) - i;
		s[0] = LABEL_CHAR;
		l->label = ft_strsub(line, i, len);
		ft_add_label(save, l);
		while (line[i] && line[i] != LABEL_CHAR)
			line[i++] = ' ';
		line[i] = ' ';
		ft_check_label(l, 0);
	}
	return (l);
}
