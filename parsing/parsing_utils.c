#include "parsing.h"


int check_name(char *str)
{   
    int  i = -1;

    while(str[++i]);
    
    i--;

    if(str[i] == 'b' && str[i-1] == 'u' && str[i-2] == 'c' && str[i-3] == '.')
        return 0;
    else
    {
        printf("%s\n",NAME_ERROR);
        return 1;
    }
}


int     count_lines(int fd)
{
    int count = 0;
    while(gnl(fd))
        count++;
    close(fd);
    return(count);
}


char*        gnl(int fd)
{

char    bit;

char    result[20000];

int     i=0;

int n;

n = read(fd,&bit,1);

while(n > 0)
{
    result[i++] = bit;
    if(bit == '\n')
        break;
    n = read(fd,&bit,1);
}

if(i == 0 && n <= 0)
    return 0;

result[i] = '\0';

return(strdup(result));

}
char**   parse_map(char *str)
{
    int fd;
    char    **map;

    fd = open(str,O_RDONLY);

    if(fd < 0)
    {
        printf("%s",FILE_NOT_FOUND);
        exit(1);
    }
    int nbr_lines = count_lines(fd);

    fd = open(str,O_RDONLY);
    
    map = NULL;

    map = malloc(sizeof(char*) * nbr_lines);

   	fill_map(map,fd);
    
    return(map);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 || s2)
	{
        if(s1)
		    len1 = strlen(s1);
        else
            len1 = 0;
        if(s2)
		    len2 = strlen(s2);
        else
            len2 = 0;
		str = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		if(s1){
		while (s1[++i])
			str[i] = s1[i];
		}
		i = -1;
        if(s2)
        {
		    while (s2[++i])
		    {
			    str[len1] = s2[i];
			    len1++;
		    }
        }
		str[len1] = '\0';
		return (str);
	}
    
	return (NULL);
}

static int	numwords(char const *s, char c)
{
	int	cur;
	int	word_num;

	cur = 0;
	word_num = 0;
	while (s[cur] != 0)
	{
		if (s[cur] != c && (s[cur + 1] == c || s[cur + 1] == 0))
			word_num++;
		cur++;
	}
	return (word_num);
}

static int	split_words(char **result, char const *s, char c, int word)
{
	int		start_cur;
	int		end_cur;

	end_cur = 0;
	start_cur = 0;
	while (s[end_cur])
	{
		if (s[end_cur] == c || s[end_cur] == 0)
			start_cur = end_cur + 1;
		if (s[end_cur] != c && (s[end_cur + 1] == c || s[end_cur + 1] == 0))
		{
			result[word] = malloc(sizeof(char) * (end_cur - start_cur + 2));
			if (!result[word])
			{
				while (word++)
					free(result[word]);
				return (0);
			}
			strlcpy(result[word], (s + start_cur), end_cur - start_cur + 2);
			word++;
		}
		end_cur++;
	}
	result[word] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (numwords(s, c) + 1));
	if (!result)
		return (NULL);
	if (!split_words(result, s, c, 0))
		return (NULL);
	return (result);
}





char *ft_strncpy(char *s1, char *s2, int n)
{
	int i = -1;

	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

char	**ft_split2_2(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int wc = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == ','))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != ','))
			i++;
	}
	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == ','))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != ','))
			i++;
		if (i > j)
		{
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(out[k++], &str[j], i - j);
		}
	}
	out[k] = NULL;
	return (out);
}
char	**ft_split2(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int wc = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (i > j)
		{
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(out[k++], &str[j], i - j);
		}
	}
	out[k] = NULL;
	return (out);
}


int		ft_atoi(char *str)
{
	int	sum;
	int	sign;
	int	found;

	sum = 0;
	sign = 1;
	found = 1;
	if (*str == '-')
		return(-1);
	while (*str && found)
	{
		if (*str >= '0' && *str <= '9')
			sum = sum * 10 + *str - '0';
		else 
			return(-1);
		str++;
	}
	return (sign * sum);
}
