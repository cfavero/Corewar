/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:28:48 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/09 18:36:49 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_pars		*ft_check_line(char *line, t_pars *lst, header_t **hd, int counter)
{
	t_pars	*new;

	if (!(*hd)->prog_name[0] || !(*hd)->comment[0])
	{
		if (((ft_head_name(line, hd)) == 1) || ((ft_head_com(line, hd)) == 1))
			return (lst);
		else
		{
			line = ft_comment_delete(line);
			while (*line && (*line == ' ' || *line == '\t'))
				line++;
			if (!*line)
				return (lst);
			ft_exit("We need an header", counter);
		}
	}
	line = ft_comment_delete(line);
	if (!(new = ft_init_lst(new, line)))
		ft_exit("Malloc faild(init_lst)", counter);
	ft_add_lst(&lst, new);
	return (lst);
}

t_pars		*ft_init_lst(t_pars *lst, char *line)
{
	if (!(lst = (t_pars*)malloc(sizeof(t_pars))))
		return (NULL);
	ft_bzero(lst, sizeof(t_pars));
	if (line)
		lst->line = ft_strdup(line);
	return (lst);
}

void		ft_add_lst(t_pars **lst, t_pars *new)
{
	t_pars *tmp;

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
