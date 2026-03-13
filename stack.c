/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadarbeh <hadarbeh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 20:36:42 by hadarbeh          #+#    #+#             */
/*   Updated: 2026/02/15 20:36:55 by hadarbeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	fatal(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	stack_init(Stack *s)
{
	s->head = NULL;
	s->tail = NULL;
	s->size = 0;
}

Node *node_new(int value)
{
	Node *n = (Node *)malloc(sizeof(Node));
	if (!n)
		fatal("malloc");
	n->value = value;
	n->next = NULL;
	return (n);
}

void	stack_append_tail(Stack *s, Node *n)
{
	if (!n)
		return ;
	n->next = NULL;
	if (s->size == 0)
	{
		s->head = n;
		s->tail = n;
	}
	else
	{
		s->tail->next = n;
		s->tail = n;
	}
	s->size++;
}

void	stack_push_head(Stack *s, Node *n)
{
	if (!n)
		return ;
	if (s->size == 0)
	{
		n->next = NULL;
		s->head = n;
		s->tail = n;
	}
	else
	{
		n->next = s->head;
		s->head = n;
	}
	s->size++;
}

Node *stack_pop_head(Stack *s)
{
	Node	*n;

	if (s->size == 0)
		return (NULL);
	n = s->head;
	s->head = s->head->next;
	s->size--;
	if (s->size == 0)
		s->tail = NULL;
	n->next = NULL;
	return (n);
}

void	stack_free(Stack *s)
{
	Node *cur = s->head;
	while (cur)
	{
		Node *next = cur->next;
		free(cur);
		cur = next;
	}
	stack_init(s);
}

void	stack_print(const char *name, const Stack *s)
{
	const	Node *cur = s->head;
	printf("%s (size=%d): ", name, s->size);
	while (cur)
	{
		printf("%d ", cur->value);
		cur = cur->next;
	}
	printf("\n");
}

int main(void)
{
    Stack a, b;
    stack_init(&a);
    stack_init(&b);

    // Simulate parsing input: append in input order
    stack_append_tail(&a, node_new(10));
    stack_append_tail(&a, node_new(20));
    stack_append_tail(&a, node_new(30));

    stack_print("A after parsing", &a); // 10 20 30

    // Simulate pb (push top of A to B): pop_head(A) then push_head(B)
    Node *moved = stack_pop_head(&a);
    stack_push_head(&b, moved);

    stack_print("A after pb", &a); // 20 30
    stack_print("B after pb", &b); // 10

    // Cleanup
    stack_free(&a);
    stack_free(&b);
    return 0;
}
