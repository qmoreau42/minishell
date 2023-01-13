#include "minish.h"

int gestion_error(t_tok *token)
{
    while (token)
    {
        if (path_error(token->cmd[0], token->error))
            return (1);
        if (path_is_dir(token->path))
           return (path_error(token->cmd[0], 3));
        token = token->next;
    }
    return (0);
}

int path_is_dir(char *str)
{
    int fd;

    fd = open(str, O_DIRECTORY);
    if (fd > 0)
    {
        close(fd);
        return (1);
    }
    return (0);
}

int    path_error(char *str, int error)
{
    if (error == 1)
    {
        write(1, "bash: ", ft_strlen("bash: "));
        write(1, str, ft_strlen(str));
        write(1, ": No such file or directory\n", ft_strlen(": No such file or directory\n"));
        return (1);
    }
    if (error == 2)
    {
        write(1, str, ft_strlen(str));
        write(1, ": command not found\n", ft_strlen(": command not found\n"));
        return (1);
    }
    if (error == 3)
    {
        write(1, "bash: ", ft_strlen("bash: "));
        write(1, str, ft_strlen(str));
        write(1, ": Is a directory\n", ft_strlen(": Is a directory\n"));
        return (1);
    }
    return (0);
}