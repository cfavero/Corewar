/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:28:48 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/05 19:55:48 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "asm.h"

char	*ft_check_line(char *line)
{
	// delete the comment COMMENT_CMD_STRING NAME_CMD_STRING
	// if .name or .comment we store the header
	// initialized lst, and add next at the end
	return (line);
}

t_pars	ft_init_lst(t_pars *lst)
{
	// init lst
}

int		ft_create_tab(char *line)
{
	static char	**tab_name = NULL;
	int	i;

	i = 0;
	if (!tab_code && !tab_name)
		tab_name = ft_strsplit("live ld st add sub and or xor zjmo ldi sti fork lld lldi lfork aff", ' ');
	// Search the ritgh init
	return (i + 1);
}
