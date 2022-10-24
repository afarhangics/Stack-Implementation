/*
 * list.h
 *
 *  Ali Farhangi - N00881073
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "myfunction.h"

#ifndef MYFUNCTIONS_H_
#define MYFUNCTIONS_H_

struct node
{
	char data[100];
	struct node* next;
};
typedef struct node Node;

Node* push(struct node *head, char *s);
Node* enqueue(struct node *head, char *s);
Node* deleteword(struct node *head, char *p);
void printlist(struct node *head);
void deletelist(struct node *head);


#endif /* MYFUNCTIONS_H_ */
