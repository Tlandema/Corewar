/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:43:03 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/07 13:14:18 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
 ** Transfert indirect Registre > RAM. Charge la valeur contenu dans le
 ** registre passé en premier parametre a l'adresse resultante de
 ** l'addition des deux derniers paramametres. Si cette valeur est nulle,
 ** alors le carry passe a l'etat un, sinon a l'etat zero.
 */

int					check_params_sti(t_process *process)
{
	if (process->op.type_param[0] == REG_CODE && (process->op.param[0] < 1 || process->op.param[0] > REG_NUMBER))
		return (0);
	else if (process->op.type_param[1] == REG_CODE && (process->op.param[1] < 1 || process->op.param[1] > REG_NUMBER))
		return (0);
	else if (process->op.type_param[2] == REG_CODE && (process->op.param[2] < 1 || process->op.param[2] > REG_NUMBER))
		return (0);
	else
		return (1);
}

static void		store_index(t_vm *vm, t_process *process)
{
	int	addr;

	addr = (process->op.param[1] + process->op.param[2]) % IDX_MOD;
	addr = process->op.pos_op_code + addr;
	vm->mem[modulo(addr, MEM_SIZE)] = process->reg[process->op.param[0]] >> 24;
	vm->mem_owner[modulo(addr, MEM_SIZE)] = -process->reg[0];
	vm->mem[modulo(addr + 1, MEM_SIZE)] = process->reg[process->op.param[0]] >> 16;
	vm->mem_owner[modulo(addr + 1, MEM_SIZE)] = -process->reg[0];
	vm->mem[modulo(addr + 2, MEM_SIZE)] = process->reg[process->op.param[0]] >> 8;
	vm->mem_owner[modulo(addr + 2, MEM_SIZE)] = -process->reg[0];
	vm->mem[modulo(addr + 3, MEM_SIZE)] = process->reg[process->op.param[0]];
	vm->mem_owner[modulo(addr + 3, MEM_SIZE)] = -process->reg[0];
}

void    		sti(t_vm *vm, t_process *process)
{
	if (!check_params_sti(process))
		return ;
	if (process->op.type_param[1] == REG_CODE)
	{
		process->op.param[1] = process->reg[process->op.param[1]];
	}
	else if (process->op.type_param[1] == IND_CODE)
		process->op.param[1] = get_indirecte(vm, &process->op, 1);
	if (process->op.type_param[2] == REG_CODE)
	{
		process->op.param[2] = process->reg[process->op.param[2]];
	}
	store_index(vm, process);
	if (vm->verbose)
		show_op(process);
}
