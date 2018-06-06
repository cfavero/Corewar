/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:28:48 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/06 18:05:50 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "asm.h"

t_pars		*ft_check_line(char *line, t_pars *lst, header_t **head)
{
	t_pars	*new;

	if (!(*head)->prog_name[0] || !(*head)->comment[0])
	{
		if (((ft_head_name(line, head)) == 1) || ((ft_head_com(line, head)) == 1))
			return (lst);
		else
		{
			line = ft_comment_delete(line);
			while (*line && (*line == ' ' || *line == '\t'))
				line++;
			if (!*line)
				return (lst);
			ft_exit("We need an header");
		}
	}
	line = ft_comment_delete(line);
	if (!(new = ft_init_lst(new, line)))
		ft_exit("Malloc faild(init_lst)");
	ft_add_lst(&lst, new);
	return (lst);
}

t_pars		*ft_init_lst(t_pars *lst, char *line)
{
	if (!(lst = (t_pars*)malloc(sizeof(t_pars))))
		return (NULL);
	if (!line)
		lst->line = NULL;
	else
		lst->line = ft_strdup(line);
	lst->label = NULL;
	lst->comment = NULL;
	lst->op_name = NULL;
	lst->param = NULL;
	lst->line_code = NULL;
	lst->next = NULL;
	lst->type[0] = 0;
	lst->type[1] = 0;
	lst->type[2] = 0;
	lst->op_code = 0;
	lst->size_code = 0;
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

int			ft_create_tab(char *str)
{
	static char	**tab_name = NULL;
	int	i;

	i = 0;
	if (!tab_name)
		tab_name = ft_strsplit("live ld st add sub and or xor zjmo ldi sti fork lld lldi lfork aff", ' ');
	while (tab_name[i])
	{
		if (ft_strcmp(str, tab_name[i]) == 0)
			return (i + 1);
		i++;
	}
	ft_exit("Wrong operation name");
	return(-1);
}
