/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:07:45 by jgautier          #+#    #+#             */
/*   Updated: 2023/01/13 18:25:29 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# define DB_REDIR_IN 1
# define SP_REDIR_IN 2
# define DB_REDIR_OUT 3
# define SP_REDIR_OUT 4


typedef struct s_token
{
	char			*content;
	char			*quote;
	char			**cmd;
	char			*path;
	char			**multi_path;
	int				type_input;
	int				*fd_input;//fini par un -1
	char			*file_input;
	int				type_output;
	int				fd_output;
	char			*file_output;
	int				heredoc;
	char			**limiter;
	int				error;
	struct s_token	*next;
}	t_tok;

typedef struct s_prompt
{
	char			*str;
	char			*quote;
}	t_prpt;

/*main*/
void	free_tab(char **tab);
/*token-izer*/
t_tok	*token_izer(char *str, char *str_desac);
char	*cp_cmd(char *str, char *quote, int *i);
t_tok	*reorganize_token(t_tok *lst_tok);
void	insert_token(t_tok *lst_tok, t_tok *new);
/*tok_lst*/
int		tok_lstadd_back(t_tok **alst, t_tok *new);
t_tok	*tok_lstlast(t_tok *lst);
t_tok	*tok_lstnew(char *content);
int		tok_lstsize(t_tok *lst);
void	tok_lstclear(t_tok *lst);
/*lexer*/
char    *quote_secur(char *str);
/*ft_split_cmd*/
char	**ft_split_cmd(char const *s);
/*dollars*/
char	*import_varsenv(char *str);
/*launch_minishell*/
int 	launch_minish(char **env);
/*parsing*/
t_tok   *parsing(char *str);
int		token_split_and_varenv(t_tok *token);
/*init_token*/
int 	init_token(t_tok *token);
int 	free_token(t_tok *token, int ret);
/*bin_path*/
int		path_cmd(t_tok *token);
int    	cmd_is_path(char *str, char *quote);
char	*find_path(char **multi_path, char *cmd);
/*exec_cmd*/
void	multi_cmd(t_tok *token, char **env, int fdin, int fdout);
int	multi_cmd_2(pid_t pid, int *fd, int fdin);
/*gestion_error*/
int path_is_dir(char *str);
int 	gestion_error(t_tok *token);
int		path_error(char *str, int error);

#endif
