/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:45:52 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/06 17:45:12 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*ft_comment_delete(char *line)
{
	char	*s;
	int		i;

	i = 0;
	if (!line)
		return (line);
	if ((s = ft_strchr(line, COMMENT_CHAR)) != NULL)
		while (s[i])
			s[i++] = ' ';
	return (line);
}

int		ft_head_name(char *line, header_t **head)
{
	char	*s;
	int		len;

	if ((s = ft_strstr(line, NAME_CMD_STRING)) != NULL)
	{
		if ((*head)->prog_name[0])
			ft_exit("Already a .Name");
		if ((s = ft_strchr(line, 34)) != NULL)
		{
			s++;
			if ((ft_strchr(s, 34)) != NULL)
			{
				len = 0;
				while (s[len] && s[len] != 34)
					len++;
				if (len > PROG_NAME_LENGTH)
					ft_exit("Error .Name too long");
				ft_strncpy((*head)->prog_name, s, len);
				ft_error_head_name(line, NAME_CMD_STRING);
				return (1);
			}
		}
		ft_exit("Error in the .Name");
	}
	return (0);
}

int		ft_head_com(char *line, header_t **head)
{
	char	*s;
	int		len;

	if ((s = ft_strstr(line, COMMENT_CMD_STRING)) != NULL)
	{
		if ((*head)->comment[0])
			ft_exit("Already a .Comment");
		if ((s = ft_strchr(line, 34)) != NULL)
		{
			s++;
			if ((ft_strchr(s, 34)) != NULL)
			{
				len = 0;
				while (s[len] && s[len] != 34)
					len++;
				if (len > COMMENT_LENGTH)
					ft_exit("Error .Comment too long");
				ft_strncpy((*head)->comment, s, len);
				ft_error_head_name(line, COMMENT_CMD_STRING);
				return (1);
			}
		}
		ft_exit("Error in the .Comment");
	}
	return (0);
}
