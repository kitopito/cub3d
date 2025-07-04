#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_fgetc(int fd);

#endif