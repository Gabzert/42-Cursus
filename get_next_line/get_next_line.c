#include "get_next_line.h"

static char		*find_end(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		{
			if (str[i] == '\n')
			{
				return (ft_substr(str, 0, i));
			}
			i++;
		}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*str;
	static char	*offset;
	int			res;

	if (offset == NULL)
		offset = "\0";
	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	while (res != 0)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (res == -1)
			return (NULL);
		buffer[res] = '\0';
		ft_strjoin(offset, buffer);
		str = find_end(offset);
		if (str != NULL)
		{
			offset = strcut(offset);
			free(temp);
			return (str);		
		}
	}
	free(temp);
	return (NULL);
}