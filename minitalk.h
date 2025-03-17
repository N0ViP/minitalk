#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

/* SIGUSR1 = 1 */
/* SIGUSR2 = 0 */

typedef struct s_clients
{
	int					client_pid;
	char				*message;
	struct s_clients	next;
}	t_clients;


void	ft_exit(int n);
int		ft_atoi(char *s);
int		ft_isdigit(int c);
int		ft_isspace(int c);
void	ft_display_banner(void);

#endif