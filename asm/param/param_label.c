/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:48:32 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/06 19:50:32 by mmanley          ###   ########.fr       */
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
		i = 0;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		s[0] = '\0';
		len =  ft_strlen(line) - i;
		s[0] = LABEL_CHAR;
		if ((*s - 1) != DIRECT_CHAR)
			l->label = ft_strsub(line, i, len);
		else
			return (l);
		while (line[i] && line[i] != LABEL_CHAR)
			line[i++] = ' ';
		line[i] = ' ';
		i = 0;
		while (l->label[i])
		{
			if (ft_isalnum(l->label[i]) == 1)
				i++;
			else
				ft_exit("Error in the label name");
		}
	}
	return (l);
}

// what if we have and actual label but has the wrong name ex. ciao%: ??
// so far we return but we should say error 0.0
