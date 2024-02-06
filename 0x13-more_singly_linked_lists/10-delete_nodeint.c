#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given index.
 * @head: Pointer to the head of the list.
 * @index: Index of the node that should be deleted.
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *temp, *prev;
    unsigned int i;

    /* Check if the list is empty */
    if (*head == NULL)
        return -1;

    temp = *head;

    /* If deleting the head node */
    if (index == 0)
    {
        *head = (*head)->next;
        free(temp);
        return 1;
    }

    /* Traverse the list to the desired index */
    for (i = 0; temp != NULL && i < index; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    /* Check if it's not possible to delete the node at the desired index */
    if (temp == NULL || i < index)
        return -1;

    /* Delete the node at the desired index */
    prev->next = temp->next;
    free(temp);

    return 1;
}

