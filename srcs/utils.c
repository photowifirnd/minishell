#include "../includes/minishell.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*tmp;
	size_t	i;

	if (!str)
		return (NULL);
	if(!(tmp = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	j = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(tmp = (char *)malloc(sizeof(char) * j)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		tmp[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		tmp[i++] = s2[j++];
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	if (!str || !c)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strsub(const char *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (!str)
		return (NULL);
	if (!(tmp = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len-- > 0 && str[i] != '\0')
		tmp[i++] = str[start++];
	tmp[i] = '\0';
	return (tmp);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (s1[i] != '\0' || s2[i] !='\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (ret);
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

static size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int		ft_countwords(char *str, char sep)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (str[i] && str[i] == sep)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != sep)
			i++;
		result++;
		while (str[i] && str[i] == sep)
			i++;
	}
	return (result);
}

static char		*next_word(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static void		cleanup(char **split, size_t cur)
{
	size_t	i;

	i = 0;
	while (i < cur)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char			**ft_split(char const *s, char c)
{
	char	**split;
	size_t	cur;
	size_t	wordcount;

	if (!s)
		return (NULL);
	wordcount = ft_countwords((char *)s, c);
	split = (char **)malloc((wordcount + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	cur = 0;
	while (cur < wordcount)
	{
		s = next_word(s, c);
		split[cur] = ft_strsub(s, 0, word_len(s, c));
		if (split[cur] == NULL)
		{
			cleanup(split, cur);
			return (NULL);
		}
		cur++;
		s += word_len(s, c);
	}
	split[wordcount] = NULL;
	return (split);
}
