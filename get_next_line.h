/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 22:44:52 by ziyang            #+#    #+#             */
/*   Updated: 2026/02/06 14:25:18 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

char	*get_next_line(int fd);
char    *read_files(int fd, char *stock);
char    *extraire_line(char *str);
char    *save_reste(char *str);
void    *ft_calloc(size_t n, size_t size);
size_t  ft_strlen(const char* str);
char    *ft_join(char *s1, char *s2);
char    *ft_strchr(const char *s, int c);

#endif
