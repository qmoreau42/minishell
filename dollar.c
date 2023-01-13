
#include "minish.h"

int	len_varsenv(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\"' && str[i] != '\'')
		i++;
	return (i);
}

char	*concat_str(char *str, char *var_env, int i, int len)
{
	char	*str_tmp;
	char	*ret;
	char	*ret_bis;

	str_tmp = malloc(sizeof(char *) * (i + 1));
	ft_strlcpy(str_tmp, str, i + 1);
	ret = ft_strjoin(str_tmp, var_env);
	free(str_tmp);
	str_tmp = malloc(sizeof(char *) * (ft_strlen(str) - (i + len) + 1));
	ft_strlcpy(str_tmp, str + i + len, ft_strlen(str) - (i + len) + 1);
	ret_bis = ft_strjoin(ret, str_tmp);
	free(str_tmp);
	free(ret);
	return(ret_bis);
}


/*attention on peut pas export VAR$ car ca fini par un $*/
char	*import_varsenv(char *str)
{
	int		i;
	int		len;
	char	*var_env;
	char	*name_var;
	char	*new_str;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			len = len_varsenv(str + i);
			if (len > 1)
			{
				name_var = ft_substr(str, i + 1, len - 1);
				var_env = getenv(name_var);
				free(name_var);
				new_str = concat_str(str, var_env, i, len);
				free(str);
				str = new_str;
			} 
		}
		i++;
	}
	return (str);
}
