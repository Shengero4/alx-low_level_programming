#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: Pointer to the head of the list.
 * @idx: Index of the list where the new node should be added.
 * @n: Value to be assigned to the new node.
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *new_node, *temp;
    unsigned int i;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return NULL;

    /* Assign values to the new node */
    new_node->n = n;

    /* If inserting at the beginning, update the head */
    if (idx == 0)
    {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    /* Traverse the list to the desired index */
    temp = *head;
    for (i = 0; temp != NULL && i < idx - 1; i++)
        temp = temp->next;

    /* Check if it's not possible to add the new node at the desired index */
    if (temp == NULL || i < idx - 1)
    {
        free(new_node);
        return NULL;
    }

    /* Insert the new node at the desired index */
    new_node->next = temp->next;
    temp->next = new_node;

    return new_node;
}

