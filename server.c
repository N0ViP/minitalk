#include "minitalk.h"

static void	sighandler(int signum, siginfo_t *info, void __attribute__((unused)) *context)
{
	static	t_clients;

}

int	main(void)
{
	struct sigaction	sa;

	ft_display_banner();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sighandler;
	if (sigemptyset(&sa.sa_mask) == -1)
		ft_exit(0);
	if (sigaddset(&sa.sa_mask, SIGUSR1) == -1)
		ft_exit(0);
	if (sigaddset(&sa.sa_mask, SIGUSR2) == -1)
		ft_exit(0);
	
}
