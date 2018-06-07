/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:48:32 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/07 15:36:51 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_pars		*ft_get_label(char *line, t_pars *l)
{
	char	*s;
	int		len;
	int		i;

	if ((s = ft_strchr(line, LABEL_CHAR)) != NULL)
	{
		if (s != line)
			s--;
		if (*s == DIRECT_CHAR)
			return (l);
		s++;
		i = 0;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		s[0] = '\0';
		len =  ft_strlen(line) - i;
		s[0] = LABEL_CHAR;
		l->label = ft_strsub(line, i, len);
		while (line[i] && line[i] != LABEL_CHAR)
			line[i++] = ' ';
		line[i] = ' ';
		i = 0;
		while (l->label[i])
		{
			if (ft_isalnum(l->label[i]) == 1 || l->label[i] == '_')
				i++;
			else
				ft_exit("Error in the label name");
		}
	}
	return (l);
}
