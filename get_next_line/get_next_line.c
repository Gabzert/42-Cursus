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


char	*read_line(int fd, char *stat, char *temp)
{
	int	res;

	while (res != 0)
	{
		res = read(fd, temp, BUFFER_SIZE);
		if (res == -1)
			return (NULL);
		temp[res] = '\0';
		ft_strjoin(stat, temp);
		str = find_end(stat);
		if (str != NULL)
		{
			stat = strcut(stat);
			return (str);		
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*str;
	static char	*offset;
	
	if (fd == NULL)
		return (NULL);
	if (offset == NULL)
		offset = "\0";
	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	str = read_line(fd, offset, buffer);
	free(buffer);
	return (str);
}