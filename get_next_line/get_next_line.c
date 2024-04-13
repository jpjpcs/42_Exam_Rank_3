
#include "get_next_line.h"

//#include<fcntl.h>
//#include <stdio.h>

char *ft_strchr(char *line, int c)
{
    while(*line)
    {
        if (*line == (char)c)
            return((char*)line);
        line++;
    }
    return(NULL);
}

size_t ft_strlen (const char *string)
{
    size_t i = 0;
    while (string[i])
        i++;
    return(i);
}

void ft_strcpy(char *line, const char *buf)   
{
    while(*buf)
        *line++ = *buf++;
    *line = '\0';
}

char *ft_strdup(const char *buf)
{
    size_t len = ft_strlen(buf) + 1;
    char *line = malloc(len);
    if (!line)
        return(NULL);
    ft_strcpy(line, buf);
    return(line);
}

char *ft_strjoin(char *line, const char *buf)
{
    if (!line || !buf)
        return(NULL);
    size_t len_line = ft_strlen(line);
    size_t len_buf = ft_strlen(buf);
    char *join = malloc(len_line + len_buf + 1);
    if (!join)
        return(NULL);
    ft_strcpy(join, line);
    ft_strcpy(join + len_line, buf);
    free(line); 
    return(join);
}
char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1];
    char *line;
    char *newline;
    int countread; 
    int to_copy;

    line = ft_strdup(buf);

    while(!(newline = ft_strchr(line, '\n')) && (countread = read(fd, buf, BUFFER_SIZE)))
    {
        buf[countread] = '\0';
        line = ft_strjoin (line, buf);
    }

    if (ft_strlen(line) == 0)
        return(free(line), NULL);
    if (newline != NULL)
    {
        to_copy = newline - line + 1;
        ft_strcpy(buf, newline + 1);
    }
    else
    {
        to_copy = ft_strlen(line);
        buf[0] = '\0';
    }
    line[to_copy] = '\0';
    return(line);
}

/* int main()
{
    char *line;
    int fd = open ("vazio.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    return(0);
} */