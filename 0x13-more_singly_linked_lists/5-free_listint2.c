#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list and sets the head to NULL.
 * @head: Pointer to the head of the list.
 */
void free_listint2(listint_t **head)
{
    listint_t *temp;

    /* Traverse the list and free each node */
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    /* Set the head to NULL */
    *head = NULL;
}

