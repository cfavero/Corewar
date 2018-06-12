/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:28:48 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/12 19:43:16 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_pars			*ft_check_line(char *line, t_pars *lst, header_t **hd, int cnt)
{
	t_pars		*new;

	if (!(*hd)->prog_name[0] || !(*hd)->comment[0])
	{
		if (((ft_head_name(line, hd)) == 1) || ((ft_head_com(line, hd)) == 1))
			return (lst);
		else
		{
			line = ft_comment_delete(line);
			if (!(line = check_line(line)))
				return (lst);
			ft_exit("We need a header", cnt);
		}
	}
	line = ft_comment_delete(line);
	if (!(line = check_line(line)))
		return (lst);
	if (!(new = ft_init_lst(new, line)))
		ft_exit("Malloc faild(init_lst)", cnt);
	new->line_nb = cnt;
	ft_add_lst(&lst, new);
	return (lst);
}

t_pars			*ft_init_lst(t_pars *lst, char *line)
{
	if (!(lst = (t_pars*)malloc(sizeof(t_pars))))
		return (NULL);
	ft_bzero(lst, sizeof(t_pars));
	if (line)
		lst->line = ft_strdup(line);
	return (lst);
}

void			ft_add_lst(t_pars **lst, t_pars *new)
{
	t_pars		*tmp;

	if (new)
	{
		if (*lst)
		{
			tmp = *lst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		else if (new)
			*lst = new;
	}
}

void			free_bad_node(t_pars **node, t_pars *lst, t_pars **tmp2)
{
	t_pars		*tmp;

	tmp = *node;
	free(tmp->label);
	tmp->label = NULL;
	free(tmp);
	tmp = lst;
	*tmp2 = lst;
}

/*
**Find this shit  with the labels alone
*/

void			ft_solo_label(t_pars **lst, t_labels **label)
{
	t_pars		*tmp;
	t_pars		*tmp2;
	t_labels	*lab;

	tmp = *lst;
	tmp2 = *lst;
	lab = *label;
	if (!lst || !tmp)
		return ;
	while (tmp->next)
	{
		if (tmp->next->label && !tmp->next->op_name)
			tmp2 = tmp;
		if (tmp && tmp->next && tmp->label && !tmp->op_name)
		{
			while (lab->lst != tmp)
				lab = lab->next;
			tmp->next->label = ft_strdup(tmp->label);
			lab->lst = tmp->next;
			if (tmp2 != *lst)
				tmp2->next = tmp->next;
			else
				*lst = tmp2->next;
			free_bad_node(&tmp, *lst, &tmp2);
			lab = *label;
		}
		tmp = tmp->next;
	}
}
