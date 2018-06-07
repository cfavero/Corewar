/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 09:53:45 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/07 11:31:17 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*ft_get_filename(char *name)
{
	char	*new;
	int		i;
	int		k;

	i = 0;
	k = 0;
	new = NULL;
	while (name && name[i])
		i++;
	i--;
	while (name[i] && (name[i] == ' ' || name[i] == '\t') && i > 0)
		i--;
	if (name[i] != 's' || name[i - 1] != '.')
		ft_exit("Wrong file extension");
	while (name[i] && i > 0 && name[i] != '/')
	{
		i--;
		k++;
	}
	(name[i] == '/') ? k-- : k;
	(name[i] == '/') ? i++ : i;
	new = ft_strsub(name, i, k);
	new = ft_strjoin_free(new, "cor", 1);
	return (new);
}

int			create_file(char *asm_file, int fd, header_t *head, t_pars *ops)
{
	char	*cor_file;

	if (!(cor_file = ft_get_filename(asm_file)))
		ft_exit("Did not get cor file name");
	ft_printf("%s\n", cor_file);
	if ((fd = open(cor_file, O_RDWR | O_CREAT, 0647)) == -1)
		ft_exit("Had a problem with open in creat file");
	ft_printf("Cor fd = %d\n", fd);
	write_header(fd, head);
	write_commands(fd, ops);
	return (fd);
}
