int	ft_strndup(char *src, int end)
{
	char	*dup;
	int		i;

	if (!src || end < 0)
		return (NULL);
	dup = (char *)malloc(sizeof(char) * (end + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < end && src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_strnjoin(char *dest, char *src, int end)
{
	char	*joined;
	int		i;
	int		j;

	if (!dest || !src || end < 0)
		return (-1);
	if (!joined)
		joined = (char *)malloc(sizeof(char) * (end + 2));
	else
		joined = (char *)malloc(sizeof(char) * (ft_strlen(dest) + end + 2));
	i = 0;
	while (dest[i])
	{
		joined[i] = dest[i];
		i++;
	}
	j = 0;
	while (j < end && src[j])
	{
		joined[i + j] = src[j];
		j++;
	}
	joined[i + j] = '\0';
	free(dest);
	return (joined);
}
