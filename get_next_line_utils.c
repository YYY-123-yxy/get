/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 22:56:47 by ziyang            #+#    #+#             */
/*   Updated: 2026/02/06 21:25:38 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *extraire_line(char *str)
{
    int i;
    int j;
    char    *line;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (str[i] == '\n')
        i++;
    line = ft_calloc((i + 1), sizeof(char));
    if (!line)
        return (NULL);
    j = 0;
    while (j < i)
    {
        line[j] = str[j];
        j++;
    }
    return (line);
}
char    *save_reste(char *str)
{
    int i;
    int j;
    char *  new_stock;
    
    if (!str)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (!str[i])
        return (free (str), NULL);
    if (str[i] == '\n')
        i++;
    new_stock = ft_calloc((ft_strlen(&str[i]) + 1), sizeof(char));
    if (!new_stock)
        return (free (str), NULL);
    j = 0;
    while (str[i])
        new_stock[j++] = str[i++];
    free (str);
    return (new_stock);
}
char    *ft_join(char *s1, char *s2)
{
    int    i;
    int    j;
    char    *str;

    if (!s1 || !s2)
        return (NULL);
    str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if(!str)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
    {
        str[i + j] = s2[j];
        j++;
    } 
    str[i + j ]= '\0';
    free(s1);
    return (str);
}

void    *ft_calloc(size_t n, size_t size)
{
    unsigned char    *ptr;
    size_t  total;
    size_t  i;

    if (n != 0 && n > __SIZE_MAX__ / size)
        return (NULL);
    total = n * size;
    ptr = malloc(total);
    if (!ptr)
        return (NULL);
    i = 0;
    while (i < total)
    {
        ptr[i] = 0;
        i++;
    }
    return ((void *)ptr);
}
size_t      ft_strlen(const char *str)
{
    size_t  i;
    
    i = 0;
    while (str[i])
        i++;
    return (i);
}
