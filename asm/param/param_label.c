/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:48:32 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/06 18:02:46 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_pars		*ft_get_label(char *line, t_pars *lst)
{
	char	*s;
	int		len;
	int		i;

	if ((s = ft_strchr(line, LABEL_CHAR)) != NULL)
	{
		i = 0;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		s[0] = '\0';
		len =  ft_strlen(line) - i;
		s[0] = LABEL_CHAR;
		if ((*s - 1) != DIRECT_CHAR)
			lst->label = ft_strsub(line, i, len);
	}
	return (lst);
}

// they can not have space beetween name and :
