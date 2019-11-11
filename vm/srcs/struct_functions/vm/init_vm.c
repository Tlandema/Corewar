/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:27:42 by paullaurent       #+#    #+#             */
/*   Updated: 2019/11/11 19:08:51 by tlandema         ###   ########.fr       */
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
