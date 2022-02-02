/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:16:24 by magostin          #+#    #+#             */
/*   Updated: 2022/02/02 02:55:15 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#define CMP1 "BCD"
#define CMP2 "ABC"
#define CMP3 "CBD"
#define STRL "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define CPY1 "copy is 👌"
#define WRT1 "write is 👌 "

int		ft_strlen(char *str);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);

int		main(void)
{
	char			copy[4][20];
	int				fd_write = open("write.test", O_WRONLY);
	int				fd_read[2];
	int				read_ret[2];
	char			read_buffer[2][20];
	char			*dup_test[2][7];
	
	// *****   FT_STRLEN   ***** //
	printf("		STRLEN\n");
	printf("ft_strlen(\"%s\") = [%d]\n", CMP1, ft_strlen(CMP1));
	printf("   strlen(\"%s\") = [%d]\n", CMP1, (int)strlen(CMP1));
	//printf("ft_strlen(NULL) = [%d]\n", ft_strlen(NULL)); //SEGFAULT !
	//printf("strlen(NULL) = [%d]\n\n", (int)strlen(NULL)); //SEGFAULT !
	printf("ft_strlen(\"%s\") = [%d]\n", STRL, ft_strlen(STRL));
	printf("   strlen(\"%s\") = [%d]\n\n", STRL, (int)strlen(STRL));

	// *****   FT_STRCPY   ***** //
	printf("		STRCPY\n");
	printf("ft_strcpy(copy[0], \"%s\") = |%s|, printf(copy[0]) = |%s|\n", CMP1, ft_strcpy(copy[0], CMP1), copy[0]);
	printf("   strcpy(copy[1], \"%s\") = |%s|, printf(copy[1]) = |%s|\n", CMP1, strcpy(copy[1], CMP1), copy[1]);
	//printf("ft_strcpy(copy[2], NULL) = |%s|, printf(copy[2]) = |%s|\n", ft_strcpy(copy[2], NULL), copy[2]); //SEGFAULT !
	//printf("   strcpy(copy[3], NULL) = |%s|, printf(copy[3]) = |%s|\n", strcpy(copy[3], NULL), copy[3]);    //SEGFAULT !
	printf("ft_strcpy(copy[2], \"%s\") = |%s|, printf(copy[2]) = |%s|\n", CPY1, ft_strcpy(copy[2], CPY1), copy[2]);
	printf("   strcpy(copy[3], \"%s\") = |%s|, printf(copy[3]) = |%s|\n\n", CPY1, strcpy(copy[3], CPY1), copy[3]);

	// *****   FT_STRCMP   ***** //
	printf("		STRCMP\n");
	printf("ft_strcmp(\"%s\", \"%s\") = %d\n", CMP1, CMP1, ft_strcmp(CMP1, CMP1));
	printf("   strcmp(\"%s\", \"%s\") = %d\n", CMP1, CMP1, strcmp(CMP1, CMP1));
	printf("ft_strcmp(\"%s\", \"%s\") = %d\n", CMP1, CMP2, ft_strcmp(CMP1, CMP2));
	printf("   strcmp(\"%s\", \"%s\") = %d\n", CMP1, CMP2, strcmp(CMP1, CMP2));
	printf("ft_strcmp(\"%s\", \"%s\") = %d\n", CMP1, CMP3, ft_strcmp(CMP1, CMP3));
	printf("   strcmp(\"%s\", \"%s\") = %d\n\n", CMP1, CMP3, strcmp(CMP1, CMP3));

	// *****   FT_WRITE   ***** //
	printf("		WRITE\n");
	printf("ft_write(1, \"%s\", ft_strlen(\"%s\")) = %ld\n", WRT1, WRT1, ft_write(1, WRT1, ft_strlen(WRT1)));
	printf("   write(1, \"%s\",    strlen(\"%s\")) = %ld\n", WRT1, WRT1, write(1, WRT1, strlen(WRT1)));
	printf("ft_write(-42, \"%s\", ft_strlen(\"%s\")) = %ld\n", WRT1, WRT1, ft_write(-42, WRT1, ft_strlen(WRT1)));
	printf("   write(-42, \"%s\",    strlen(\"%s\")) = %ld\n", WRT1, WRT1, write(-42, WRT1, strlen(WRT1)));
	printf("ft_write(open(\"write.test\", \'w\'), \"%s\", ft_strlen(\"%s\")) = %ld\n", WRT1, WRT1, ft_write(fd_write, WRT1, ft_strlen(WRT1)));
	printf("   write(open(\"write.test\", \'w\'), \"%s\",    strlen(\"%s\")) = %ld\n\n", WRT1, WRT1, write(fd_write, WRT1, strlen(WRT1)));
	close(fd_write);

	// *****   FT_READ   ***** //
	printf("		READ\n");
	fd_read[0] = open("write.test", O_RDONLY);
	fd_read[1] = open("write.test", O_RDONLY);
	read_ret[0] = ft_read(fd_read[0], read_buffer[0], 13);
	read_ret[1] = read(fd_read[1], read_buffer[1], 13);
	read_buffer[0][read_ret[0]] = 0;
	read_buffer[1][read_ret[1]] = 0;
	printf("ft_read(open(\"write.test\", O_RDONLY), read_buffer[0], 13) = %d. printf(read_buffer[0]) = |%s|\n", read_ret[0], read_buffer[0]);
	printf("   read(open(\"write.test\", O_RDONLY), read_buffer[1], 13) = %d. printf(read_buffer[1]) = |%s|\n", read_ret[1], read_buffer[1]);
	close(fd_read[0]);
	close(fd_read[1]);

	// *****   FT_STRDUP   ***** //
	printf("		STRDUP\n");
	dup_test[0][0] = ft_strdup(CMP1);
	dup_test[0][1] = ft_strdup(CMP2);
	dup_test[0][2] = ft_strdup(CMP3);
	dup_test[0][3] = ft_strdup(STRL);
	dup_test[0][4] = ft_strdup(CPY1);
	dup_test[0][5] = ft_strdup(WRT1);
//	dup_test[0][6] = ft_strdup(NULL); //SEGFAULT !
	dup_test[1][0] = strdup(CMP1);
	dup_test[1][1] = strdup(CMP2);
	dup_test[1][2] = strdup(CMP3);
	dup_test[1][3] = strdup(STRL);
	dup_test[1][4] = strdup(CPY1);
	dup_test[1][5] = strdup(WRT1);
//	dup_test[1][6] = strdup(NULL); //SEGFAULT !
	for (int i = 0; i <= 5; i++)
	{
		printf("ft_strdup: \"%s\"\n", dup_test[0][i]);
		printf("   strdup: \"%s\"\n", dup_test[1][i]);
		free(dup_test[0][i]);
		free(dup_test[1][i]);
	}
	return (1);
}