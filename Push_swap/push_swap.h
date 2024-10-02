/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:27:01 by acarro-v          #+#    #+#             */
/*   Updated: 2024/10/01 14:26:34 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_addnodes(int argc, char **argv);
int		ft_checksort(t_stack	*stack_a);
int		ft_checkdup(t_stack	*a);
void	ft_error(void);
void	ft_freestr(char **lst);
void	ft_free(t_stack **lst);
void	ft_sort(t_stack **stack_a);
void	ft_sa(t_stack **a);
void	ft_sort_b_until_three(t_stack **stack_a, t_stack **stack_b);
int		ft_find_rotate_case_ab(t_stack *a, t_stack *b);
int		ft_case_rarb_b(t_stack *a, t_stack *b, int nbr);
int		ft_connection_in_b(t_stack *stack_b, int pushed_nbr);
int		ft_min(t_stack *a);
int		ft_max(t_stack *a);
int		ft_find_index(t_stack *a, int nbr);
int		ft_case_rrarrb_b(t_stack *a, t_stack *b, int nbr);
int		ft_case_rrarb_b(t_stack *a, t_stack *b, int nbr);
int		ft_case_rarrb_b(t_stack *a, t_stack *b, int nbr);
int		ft_apply_rarb(t_stack **a, t_stack **b, int c, char n);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);
int		ft_connection_in_a(t_stack *stack_a, int pushed_nbr);
void	ft_pa(t_stack **a, t_stack **b);
int		ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char n);
void	ft_rrr(t_stack **a, t_stack **b);
void	ft_rrr_2(t_stack **b);
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
int		ft_apply_rrarb(t_stack **a, t_stack **b, int c, char n);
int		ft_apply_rarrb(t_stack **a, t_stack **b, int c, char n);
void	ft_sort_three(t_stack **stack_a);
int		ft_find_rotate_case_ba(t_stack *a, t_stack *b);
int		ft_case_rarb_a(t_stack *a, t_stack *b, int nbr);
int		ft_case_rrarrb_a(t_stack *a, t_stack *b, int nbr);
int		ft_case_rrarb_a(t_stack *a, t_stack *b, int nbr);
int		ft_case_rarrb_a(t_stack *a, t_stack *b, int nbr);
int		ft_sizelist(t_stack *lst);
t_stack	*ft_ltlast(t_stack *lst);
void	ft_add_back(t_stack **stack, t_stack *stack_new);
t_stack	*ft_stack_new(int content);

#endif