#include "pipex.h"

char	*ft_get_path(char *envp[])
{
	int		i;
	char	*path;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4))
		i++;
	path = ft_strdub((envp[i] + 5));
	return (path);
}
