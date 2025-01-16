/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banner_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:54:02 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/08 03:58:44 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	banner_part1(void)
{
	ft_printf("%s",
		"\n\n"
		"\t\t█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗"
		"█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗"
		"█████╗█████╗█████╗█████╗█████╗\n"
		"\t\t╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝"
		"╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝"
		"╚════╝╚════╝╚════╝╚════╝╚════╝\n"
		"\n"
		"\t\t\t░▒▓██████████████▓▒░  ░▒▓█▓▒░ ░▒▓███████▓▒░  "
		"░▒▓█▓▒░ ░▒▓████████▓▒░  ░▒▓██████▓▒░  ░▒▓█▓▒░      "
		"░▒▓█▓▒░░▒▓█▓▒░ \n"
		"\t\t\t░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ "
		"░▒▓█▓▒░    ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░      "
		"░▒▓█▓▒░░▒▓█▓▒░ \n"
		"\t\t\t░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ "
		"░▒▓█▓▒░    ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░      "
		"░▒▓█▓▒░░▒▓█▓▒░ \n"
		"\t\t\t░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ "
		"░▒▓█▓▒░    ░▒▓█▓▒░     ░▒▓████████▓▒░ ░▒▓█▓▒░      "
		"░▒▓███████▓▒░  \n"
		);
}

void	banner_part2(void)
{
	ft_printf("%s",
		"\t\t\t░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ "
		"░▒▓█▓▒░    ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░      "
		"░▒▓█▓▒░░▒▓█▓▒░ \n"
		"\t\t\t░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ "
		"░▒▓█▓▒░    ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░      "
		"░▒▓█▓▒░░▒▓█▓▒░ \n"
		"\t\t\t░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ "
		"░▒▓█▓▒░    ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓████████▓▒"
		"░▒▓█▓▒░░▒▓█▓▒░ \n"
		"\n"
		);
}

void	banner_part3(void)
{
	ft_printf("\t\t\t\t\t\t\t\t\t<<PID = %i>>\n\n%s", getpid(),
		"\t\t█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗"
		"█████╗█████╗█████╗█████╗█████╗█████╗█████╗█████╗"
		"█████╗█████╗█████╗█████╗█████╗\n"
		"\t\t╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝"
		"╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝╚════╝"
		"╚════╝╚════╝╚════╝╚════╝╚════╝\n"
		"\n\n"
		);
}

void	ft_display_banner(void)
{
	banner_part1();
	banner_part2();
	banner_part3();
}
