#include "minish.h"

int init_token(t_tok *token)
{
    int flag;

    flag = 0;
    while (token)
    {
        token->quote = NULL;
        token->cmd = NULL;
        token->path = NULL;
        token->type_input = 0;
        token->fd_input = 0;
        token->file_input = NULL;
        token->type_output = 0;
        token->fd_output = 1;
        token->file_output = NULL;
        token->error = 0;
        token->multi_path = ft_split(getenv("PATH"), ':');
        if (token->multi_path)
            flag = 1;
        token = token->next;
    }
    return (flag);
}

int free_token(t_tok *token, int ret)
{
    t_tok *free_token;

    while (token)
    {
        if (token->content)
            free(token->content);
        if (token->quote)
            free(token->quote);
        if (token->cmd)
            free_tab(token->cmd);
        if (token->file_input)
            free(token->file_input);
        if (token->file_output)
            free(token->file_output);
        if (token->path)
            free(token->path);
        if (token->multi_path)
            free_tab(token->multi_path);
        free_token = token;
        token = token->next;
        free(free_token);
    }
    return (ret);
}