/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: V <V@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:55:20 by V                 #+#    #+#             */
/*   Updated: 2022/03/19 09:54:11 by V                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

// swap (swap first two numbers)
void	ll_swap(t_stack *l, char c)
{
	t_node	**head;
	t_node	*tmp;
	t_node	*t2;

	head = &l->head;
	tmp = l->head;
	t2 = tmp->next;
	ptr_2_ptr(tmp, t2);
	t2->prev = NULL;
	*head = t2;
	l->c++;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
	else if (c == 's')
		write(1, "ss\n", 3);
}

// rotate = top number goes bottom
void	ll_rotate(t_stack *l, char c)
{
	t_node	**head;
	t_node	**tail;
	t_node	*tmp;
	t_node	*t2;

	head = &l->head;
	tail = &l->tail;
	tmp = l->head;
	t2 = tmp->next;
	t2->prev = NULL;

	ptr_2_ptr(tmp, l->tail);
	*head = t2;
	*tail = tmp;

	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
	else if (c == 'r')
		write(1, "rr\n", 3);
	l->c++;
}

// rotate = bottom number goes top (why would we use this)
void	ll_rr(t_stack *l, char c)
{
	t_node	**head;
	t_node	**tail;
	t_node	*tmp;
	t_node	*t2;

	head = &l->head;
	tail = &l->tail;
	tmp = l->tail;
	t2 = l->tail->prev;
	t2->next = NULL;
	tmp->prev = NULL;
	tmp->next = l->head;
	l->head->prev = tmp;
	*head = tmp;
	*tail = t2;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
	l->c++;
}

void	ll_pushB(t_stack *a, t_stack *b)
{
	t_node	*t2;
	t_node	*n;

	n = a->head;
	t2 = n->next;
	if (n->next != NULL)
		t2->prev = n->prev;
	if (n->prev != NULL)
		n->prev->next = n->next;
	if (n->next == NULL && n->prev != NULL)
		t2 = n->prev;
	n->prev = NULL;
	n->next = NULL;
	if (b->head != NULL)
	{
		n->next = b->head;
		b->head->prev = n;
	}
	else
		b->tail = n;
	b->head = n;
	a->head = rt_ll_head(t2);
	a->tail = rt_ll_tail(a->head);
	a->c ++;
	write(1, "pb\n", 3);
}

void	ll_pushA(t_stack *a, t_stack *b)
{
	t_node	*t2;
	t_node	*n;

	n = b->head;
	t2 = n->next;
	if (n->next != NULL)
		t2->prev = n->prev;
	if (n->prev != NULL)
		n->prev->next = n->next;
	if (n->next == NULL && n->prev != NULL)
		t2 = n->prev;
	// if (n->next == NULL && n->prev == NULL)
	// 	t2 = NULL; MAYBE NOT NEEDED
	n->prev = NULL;
	n->next = NULL;
	if (a->head != NULL)
	{
		n->next = a->head;
		a->head->prev = n;
	}
	else
		a->tail = n;
	a->head = n;
	b->head = rt_ll_head(t2);
	b->tail = rt_ll_tail(b->head);
	a->c ++;
	write(1, "pa\n", 3);
}
