#include "pipex.h"

char	*ft_get_bin(char *cmd_name, char **tab_env)
{
	char	*new_path;
	int		i;

	if (!ft_strncmp(cmd_name, "./", 3))
	{
		if (access(cmd_name, X_OK) != -1)
			return (cmd_name);
	}
	else
	{
		i = 0;
		while (tab_env[i])
		{
			new_path = ft_pathmaker(tab_env[i], cmd_name);
			if (!new_path)
				perror("pipex_cmd.c - ft_get_bin");
			if (new_path && access(new_path, X_OK) != -1)
				return (new_path);
			free(new_path);
			i++;
		}
		perror("ft_get_bin - command not found");
	}
	return (NULL);
}

char	**ft_get_flag(char *format)
{
	int	i;

	return (NULL);
}

size_t	ft_count_arg(char *format)
{
	int		state_s;
	int		i;
	size_t	count;

	i = 0;
	state_s = 1;
	count = 1;
	if (format[i] != '\0')
		return (0);
	while (format[i])
	{
if (format[i] == "'")
		if (ft_isspace(format[i]) && state_s)
		{
			while (ft_isspace(format[i]))
				i++;
			count++;
		}
		i++;
	}
	return (count);
}
