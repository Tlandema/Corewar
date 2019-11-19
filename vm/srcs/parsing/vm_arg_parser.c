/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_arg_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:27:05 by brichard          #+#    #+#             */
/*   Updated: 2019/11/19 16:15:44 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int8_t		vm_arg_parser(t_parser *parser, char **av)
{
	t_parser			d_parser;
	static t_get_func	get_func[GET_F_NUM] = {get_opt, get_dump, get_chpnum
																, get_champ};

	parser->env = init_vm();
	d_parser = *parser;
	while (d_parser.state != S_ERR && *av != NULL)
	{
		get_func[d_parser.state](&d_parser, av);
		++av;
	}
	*parser = d_parser;
	return (d_parser.state != S_ERR ? SUCCESS : FAILURE);
}
