/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dekravts <moonriver7609@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 03:16:04 by dekravts          #+#    #+#             */
/*   Updated: 2024/06/25 18:06:58 by dekravts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 14
# endif

char	*get_next_line(int fd);
int		new_present(char *line, char c);
size_t	ft_strlen(char *str);
char	*cpy_do_new(char *line, char *buffer);

#endif