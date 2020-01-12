/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:35:29 by brichard          #+#    #+#             */
/*   Updated: 2020/01/12 18:16:00 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_process	init_process(int32_t reg_1, int32_t pc, uint8_t num)
{
	t_process	new_process;

	new_process.active = 1;
	new_process.next = NULL;
	new_process.prev = NULL;
	ft_bzero((void *)new_process.reg, sizeof(int32_t) * REG_NUMBER + 1);
	ft_bzero((void **)&new_process.op, sizeof(t_op));
	new_process.reg[0] = -reg_1;
	new_process.pc = pc;
	new_process.cycles_left = 0;
	new_process.carry = FALSE;
	new_process.last_live = 0;
	new_process.num = num;
	return (new_process);
}
