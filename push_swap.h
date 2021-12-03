/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:52:57 by arohmann          #+#    #+#             */
/*   Updated: 2021/12/03 13:52:59 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define GREEN  "\033[32m"
# define VIO  "\033[35m"
# define RED  "\033[31m"
# define YELL  "\033[33m"
# define CYAN  "\033[36;1m"
# define RE  "\033[0m"

# define AD_BD 1
# define AD_BU 2
# define AU_BD 3
# define AU_BU 4

typedef struct s_node
{
	int				lis;
	int				num;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_opti
{
	int	b_up;
	int	b_down;
	int	a_up;
	int	a_down;

	int	au_bu;
	int	au_bd;
	int	ad_bu;
	int	ad_bd;

	int	opti;
	int	mode;
}	t_opti;

typedef struct s_data
{
	t_node	*head_a;
	t_node	*head_b;
	t_node	*stack;
	int		size_a;
	int		size_b;
	int		*arr;
	int		lis_l;
	int		*lis;
	int		sort_m;
	int		best;
	int		best_a;
	int		best_b;
	int		best_n;
}	t_data;

void	create_stack_a(t_data *data);
void	check_input(int	ac, char **av, t_data *data);
t_data	*init_data(void);
void	free_error(t_node *head_a, t_node *head_b, int *arr);
int		is_sorted(t_data *data);
void	sort_small(t_data *data);
void	sort_big(t_data *data);
int		find_smallest(t_node *head, int size);
int		find_s_node(t_node *head, int size);
void	push_smallest(t_data *data, int pos);
int		*find_lis(t_data *data);
void	flag_lis(t_data *data, int *arr);
int		find_biggest(t_node *head, int size);
int		find_l_node(t_node *head, int size);
int		**create_lis_arr(t_data *data);
/**********************************************************/
/*                      OPTI-PUSH                         */
/**********************************************************/
void	solve_opti(t_data *data, t_opti *opti);
int		opti_opti(t_opti *opti);
void	create_opti(t_data *data, t_opti *opti, int posa, int posb);
void	sort_ad_bd(t_data *data, t_opti *opti);
void	sort_ad_bu(t_data *data, t_opti *opti);
void	sort_au_bd(t_data *data, t_opti *opti);
void	sort_au_bu(t_data *data, t_opti *opti);
/**********************************************************/
/*                        PRINT                           */
/**********************************************************/
void	print(t_data *data);
void	printa(t_data *data);
void	printb(t_data *data);
void	print_node(t_node *new);
void	print_node_b(t_node *new, t_node *newb);
/**********************************************************/
/*                        NODES                           */
/**********************************************************/
t_node	*new_node(int content);
void	add_node_prev(t_node **head, t_node *new);
void	add_node_next(t_node **head, t_node *new);
t_node	*rem_node(t_node **r_node);
/**********************************************************/
/*                      INSTRUCTIONS                      */
/**********************************************************/
void	sa(t_data *data, int print);
void	sb(t_data *data, int print);
void	ss(t_data *data, int print);
void	ra(t_data *data, int print);
void	rb(t_data *data, int print);
void	rr(t_data *data, int print);
void	rra(t_data *data, int print);
void	rrb(t_data *data, int print);
void	rrr(t_data *data, int print);
void	pb(t_data *data, int print);
void	pa(t_data *data, int print);
/**********************************************************/
/*                     GET_NEXT_LINE                      */
/**********************************************************/
char	*get_next_line(int fd);

#endif