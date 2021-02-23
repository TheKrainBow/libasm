/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:49:40 by magostin          #+#    #+#             */
/*   Updated: 2021/02/23 16:14:27 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define STRLEN(x)			printf("[%s] = %d ft_%d\n", x, (int)strlen(x), ft_strlen(x));
# define STRCMP(a, b)		printf("[%s]:[%s] = %d ft_%d\n", a, b, strcmp(a, b), ft_strcmp(a, b));
# define WRITE(s, x)		printf(" returned %ld with [%s] %ld\n", ft_write(STDOUT_FILENO, s, x), s, x);
# define CPY(s)				printf("[%s] ft_(%s)\n", s, ft_strcpy(buffer, s));

int		ft_strlen(char *str);

#endif