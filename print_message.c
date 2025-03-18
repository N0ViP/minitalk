#include "minitalk.h"

void print_message(t_clients **begin_list)
{
	if (!begin_list || !*begin_list)
		return ;
	t_clients *tmp;
	t_clients *ptr;
	while (*begin_list && !(*begin_list)->finish == 1)
	{
		printf("message from client %d : %s\n", (*begin_list)->client_pid, (*begin_list)->message);
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
	}
	ptr = *begin_list;
	while (ptr && ptr->next)
	{
		tmp = ptr->next;
		if (tmp->finish == 1)
		{
			printf("message from client %d : %s\n", (tmp)->client_pid, (tmp)->message);
			ptr->next = tmp->next;
		}
		else
			ptr = ptr->next;
	}
}
