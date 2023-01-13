#include "minish.h"

int launch_minish(char **env)
{
    t_tok   *token;
    t_tok   *first_token;
    char    *str;

    while (1)
    {
        str = readline("minishell->");
        if (!str)
            return (0);
        if (str[0])
        {
            add_history(str);
			token = parsing(str);
            if (!gestion_error(token))
			    multi_cmd(token, env, 0, 1);
			first_token = token;
			free_token(first_token, 1);
        }
		free(str);
    }
	return (1);
}