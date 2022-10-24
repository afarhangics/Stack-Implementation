/*
 * list.c
 *
 * Ali Farhangi - N00881073
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"
#include "myfunction.h"


/* push --
 * It dynamically allocates a new node called current. Copies the value of char *s to the current.
 * It then sets the current->next to head and sets head to current because in stack the new items are added at head.
 * Every time that we add an item to the stack, list and head gets updated and that's why we return the head.
 *
 * param:
 * head, address of the current head
 * s, the new item
 *
 * return: the address of the new head
 *
 *
 */
Node* push(struct node *head, char *s)
{
	Node *current = malloc(sizeof(Node));

	strcpy(current->data, s);

	current->next = head;

	head = current;

	return head;

}




/* enqueue --
 * First, it checks if we are adding the first item. if it's the first item, it updates the head and sets next to it to NULL.
 * if it's not the first item, it then adds the new item at the end of the queue.
 * It uses the while loop in order to go to the end of the queue. when it reaches the last item, it then adds the new node.
 * Every time that we add an item to the queue, list gets updated and that's why we return the head.
 *
 * param:
 * head, address of the current head
 * s, the new item
 *
 * return: the address of the new head
 *
 *
 */
Node* enqueue(struct node *head, char *s)
{

	if(head == NULL)
	{
		head = malloc(sizeof(Node));
		strcpy(head->data, s);

		head->next = NULL;
	}

	else
	{
		Node *current =  head;
		Node *newnode =  malloc(sizeof(Node));
		strcpy(newnode->data, s);

		while(current->next != NULL)
		{
			current = current->next;
		}

		current->next = newnode;
	}

	return head;

}





/* deletword --
 * it deletes all occurrences of the char *p from the linked list.
 * The rest of the explanation with details is inside the function.
 *
 * param:
 * head, address of the current head
 * p, the item that we want to delete all occurrences of it from the linked list
 *
 * return: the address of the new head
 *
 *
 */
Node* deleteword(struct node *head, char *p)
{

	// declaring three nodes that all of them point to the head.
	// we need 3 temporary nodes because in some part of the function we need current to be one item ahead of temp.
	// the remove node is the one that we use it to remove a node that is the same as char *p.
	Node *current = head;
	Node *temp = head;
	Node *remove = head;


	while(current != NULL)
	{
		if(strcmp(current->data, p) == 0)
		{

			// if the word that we are removing is the head
			if(strcmp(current->data, head->data) == 0)
			{
				// updates the head
				head = head->next;

				// updates current
				current = current->next;

				// updates temp
				temp = temp->next;

				// removes the remove node
				free(remove);

			}


			else
			{

				// if it's the last item
				if(current->next == NULL)
				{
					// sets remove to current in order to remove it later on
					remove = current;

					// sets the next of the temp to NULL because now temp is the last item
					temp->next = NULL;

					// now removes the remove node
					free(remove);

					// it returns the head because we are now at the end of the list and we don't need to check and do anything else
					return head;

				}


				// if it's neither the head nor the last item
				else
				{
					// remove node points to current
					remove = current;

					// updates current
					current = current->next;

					// sets next of the temp to current
					temp->next = current;

					// now removes the remove node
					free(remove);

				}

			}


		}


		// if we didn't find any nodes that is the same as char *p
		else
		{
			// sets the temp to current
			temp = current;

			// updates the current
			current = current->next;

		}


		// we need to update the remove node and that's why we set it to current
		remove = current;


	}


	// When we delete an item from the linked list, list gets updated and also we may have a new head. that's why we return the head.
	return head;

}




/* printlist --
 * it prints the data of each node from the linked list.
 * it starts from the head and goes to the end of the list.
 * we don't need to return anything since we are not making any changes in the list.
 *
 * param: head, address of the current head
 *
 */
void printlist(struct node *head)
{

	if(head == NULL)
	{
		printf("Can't print because the list is empty\n");
	}

	else
	{
		Node *temp = head;
		while(temp != NULL)
		{
			printf("%s\n" , temp->data);
			temp = temp->next;

		}

	}

	printf("\n");


}




/* deletelist --
 * it frees and removes the nodes from the memory.
 * it starts from the head and goes to the last item.
 * we need 2 temporary nodes. current is always one item ahead of the temp.
 * we remove temp in each iteration. when we reach the last item, the loop ends and that's when we remove the last item ( free(current) ).
 *
 * param: head, address of the current head
 *
 *
 */
void deletelist(struct node *head)
{

	if(head != NULL)
	{
		Node *current = head;
		Node *temp = current;

		while(current->next != NULL)
		{
			current = current->next;
			free(temp);
			temp = current;
		}

		free(current);
	}


}



