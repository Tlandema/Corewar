/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:35:29 by brichard          #+#    #+#             */
/*   Updated: 2019/10/23 17:35:35 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_vm	init_vm(size_t mem_size)
{
	t_vm	new_vm;

	new_vm.process_list = NULL;
	ft_bzero((void *)new_vm.champ_names, sizeof(int32_t) * MAX_PLAYERS);
	new_vm.cycles_to_die = CYCLE_TO_DIE;
	new_vm.mem = ft_memalloc(mem_size);
	return (new_vm);
}
