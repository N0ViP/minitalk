#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>	//?????

typedef struct  s_client
{
	int		client_pid;
    int		bit;
	int		i;
    char	byte;
    char	message[4096];
}	t_client;

#endif