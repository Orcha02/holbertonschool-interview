#include <stdlib.h>
#include "lists.h"
/**
 * insert_node - Insert node in sorted linked list
 * Description: Function inserts a number into a sorted singly linked list
 * @head: Pointer to a pointer, head of the list
 * @number: Integer value to insert
 * Return: The address of the new node, or NULL if it failed
 **/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newNode, *tmp = *head;

	newNode = malloc(sizeof(listint_t)); /* Assign memory space for newNode */
	if (newNode == NULL)
		return (NULL);
	newNode->n = number;
	if (*head == NULL) /* Validate if the list is empty */
	{
		*head = newNode;
		newNode->next = NULL;
		return (newNode);
	}
	if (tmp->next == NULL) /*Validate if there is only one element in the list*/
	{
		newNode->next = NULL;
		tmp->next = newNode;
		return (newNode);
	}
	if (number <= tmp->n) /* To insert number in a sorted way */
	{
		newNode->next = tmp;
		*head = newNode;
		return (newNode);
	}
	while (tmp->next != NULL) /* Go through the list */
	{
		if (number <= tmp->next->n)
		{
			newNode->next = tmp->next;
			tmp->next = newNode;
			return (newNode);
		}
		tmp = tmp->next;
	}
	tmp->next = newNode;
	newNode->next = NULL;
	return (newNode);
}
