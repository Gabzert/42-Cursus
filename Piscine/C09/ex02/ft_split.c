/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:55:08 by gfantech          #+#    #+#             */
/*   Updated: 2022/05/26 16:55:13 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != 0)
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	if (c == 0)
		return (1);
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (separator(str[i], charset) == 0
			&& separator(str[i + 1], charset) == 1)
			count++;
		i++;
	}
	return (count);
}

char	*ft_strdup(char *start, char *end)
{
	char	*copy;
	char	*temp;

	copy = (char *)malloc(sizeof(char) * (end - start + 1));
	temp = copy;
	while (start != end)
	{
		*copy = *start;
		copy++;
		start++;
	}
	*copy = 0;
	copy = temp;
	return (copy);
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	char	*temp;
	int		i;
	int		key;

	array = (char **)malloc((sizeof(char *) * (count_word(str, charset) + 1)));
	array[count_word(str, charset)] = 0;
	i = 0;
	while (*str)
	{
		key = 0;
		while (*str && separator(*str, charset) == 0)
		{
			if (key == 0)
			{
				temp = str;
				key = 1;
			}
			str++;
		}
		if (key == 1)
			array[i++] = ft_strdup(temp, str);
		str++;
	}
	return (array);
}
/*int main(void)
{
	char str[500] = "a12a34,,aa56a78aa90";
//	char str[500] = "  \t ";
//	char charset[500] = " \t";
	char charset[500] = "a";
	char **result = ft_split(str, charset);
	printf("%s\n%s\n--------------\n", str, charset);
	for(int i = 0; result[i]; i++)
		printf("%s\n", result[i]);

	return 0;
}*/
