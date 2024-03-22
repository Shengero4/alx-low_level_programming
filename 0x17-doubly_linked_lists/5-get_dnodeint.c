#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
 * @head: Pointer to the head of the doubly linked list
 * @index: Index of the node to return, starting from 0
 *
 * Return: Pointer to the nth node, or NULL if the node does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
    unsigned int i;

    /* Traverse the list until reaching the desired index */
    for (i = 0; head != NULL && i < index; i++)
    {
        head = head->next;
    }

    /* Return the node at the desired index, if it exists */
    return (head);
}
