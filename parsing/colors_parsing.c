#include "parsing.h"

int     count_bits(char     *line)
{
    int     i=0;
    while(line[i])
    {
        if(i > 2)
            return (1);
        i++;
    }
    return(0);
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

void    check_valid_bit(char    *line)
{
    if(!line)
    {
        printf("%s%s\n",ERROR,"Invalid rgb Color\033[0m");
        exit(1);
    }
    if(count_bits(line))
    {
        printf("%s%s\n",ERROR,"Invalid rgb Color\033[0m");
        exit(1);
    }
    int     c = ft_atoi(line);
    // printf("line is : %s int is : %d\n",line,c);
    if( c > 255 || c == -1)
    {
        printf("%s%s\n",ERROR,"Invalid rgb Color\033[0m");
        exit(1);
    }
}

int     count_coma(char *line)
{
    int     i = 0;
    int     count=0;
    while (line[i])
    {   
        if(line[i] == ',')
            count++;
    i++;
    }
    return(count);
}
void    check_format(char   *line)
{
    int     i = 0;
    while (line[i] == ' ' || line[i] == '\t')
            i++;
    int coma = count_coma(line + i);
    if(coma != 2)
    {
        printf("%s%s\n",ERROR,"Invalid rgb Color\033[0m");
        exit(1);
    }
    char    **split = NULL;
    split = ft_split2_2(line + i);
    int     j=0;
    while(j < 3)
    {
        check_valid_bit(split[j]);
        j++;
    }
    i=0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
    if(i > 3)
    {
        printf("%s%s\n",ERROR,"Invalid Color\033[0m");
        exit(1);
    }
}

void    check_flor(char     *line)
{
    if((line[0] != 'F' && line[0] != 'C') || line[1] != ' ')
    {
        printf("%s%s\n",ERROR,"Invalid Color Identifier\033[0m");
        exit(0);
    }
    check_format(line + 1);

}

void    check_colors(t_data      *data)
{
    check_flor(data->map[4]);
    check_flor(data->map[5]);
}