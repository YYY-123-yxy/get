/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziyang <ziyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 22:55:25 by ziyang            #+#    #+#             */
/*   Updated: 2026/02/19 17:11:28 by ziyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_files(int fd, char *stock)
{
	char	*buffer;
	int		bytes_read;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), NULL);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			stock = ft_join(stock, buffer);
			if (!stock)
				return (free(buffer), NULL);
			if (ft_strchr(stock, '\n'))
				break ;
		}
	}
	free(buffer);
	return (stock);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(stock), stock = NULL, NULL);
	if (!stock)
	{
		stock = ft_calloc(1, sizeof(char));
		if (!stock)
			return (NULL);
	}
	if (!ft_strchr(stock, '\n'))
		stock = read_files(fd, stock);
	if (!stock || !*stock)
		return (free(stock), stock = NULL, NULL);
	line = extraire_line(stock);
	stock = save_reste(stock);
	return (line);
}
