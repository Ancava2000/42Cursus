/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:27:01 by acarro-v          #+#    #+#             */
/*   Updated: 2024/08/19 16:46:44 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H;
# define PUSH_SWAP_H;

#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_addnodes(int argc, char **argv);

#endif;