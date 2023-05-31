/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiessaiy <wiessaiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 00:51:06 by wiessaiy          #+#    #+#             */
/*   Updated: 2023/05/23 08:40:33 by wiessaiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

    


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