/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:44:38 by wismith           #+#    #+#             */
/*   Updated: 2022/01/08 20:06:08 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *s)
{
	free (s);
	s = NULL;
	return (NULL);
}

char	*gnl_algo(char *save, int fd)
{
	int		check;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	check = 1;
	while (check > 0)
	{
		check = read(fd, temp, BUFFER_SIZE);
		if (check == -1)
			return (ft_free(temp));
		temp[check] = '\0';
		save = ft_strjoin(save, temp);
		if (ft_nlel(temp))
			break ;
	}
	ft_free(temp);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	save = gnl_algo(save, fd);
	res = ft_rtnline(save);
	save = ft_rtnsave(save);
	return (res);
}