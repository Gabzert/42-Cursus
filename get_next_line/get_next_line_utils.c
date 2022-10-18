#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		c;
	int		x;

	c = 0;
	x = 0;
	new = (char *)malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)
			* sizeof(char));
	if (new == NULL)
		return (NULL);
	while (((char *)s1)[x] != '\0')
	{
		new[c] = ((char *)s1)[x];
		c++;
		x++;
	}
	x = 0;
	while (((char *)s2)[x] != '\0')
	{
		new[c] = ((char *)s2)[x];
		c++;
		x++;
	}
	new[c] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	c;
	char	*sub;

	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	c = 0;
	while (((char *)s)[start] != '\0' && c < len)
	{
		sub[c] = ((char *)s)[start];
		c++;
		start++;
	}
	sub[c] = '\0';
	return (sub);
}

char	*strcut(char *str)
{
	char	*cut;
	int		i;
	int		len;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break;
	}
	len = ft_strlen(&str[i + 1]);
	cut = malloc(sizeof(char *) * (len + 1));
	while (str[i] != '\0')
	{
		*cut = str[i];
		i++;
		cut++;
	}
	*cut = '\0';
	return (cut);
}