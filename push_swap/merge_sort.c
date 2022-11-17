int sort(char **a, int first, int last)
{
	int	center;

	if (first < last)
	{
		center = (first + last) / 2;
		sort(a, first, center);
		sort(a, center, last);
	}
		merge(a, first , center, last)
}

int merge (char **a, int first, int center, int last)
{
	int		i;
	int		j;
	char	**b;

	i = first;
	j = last;
	b = malloc(last * sizeof(char **));

	while (i < center)
		push(a, b);
	 
}