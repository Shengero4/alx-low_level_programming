#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: Pointer to a pointer to the head of the doubly linked list
 * @idx: Index of the list where the new node should be added
 * @n: Integer value to be stored in the new node
 *
 * Return: The address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node, *current_node;
    unsigned int i;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    /* Initialize the new node */
    new_node->n = n;

    /* If the list is empty and the index is 0, set the new node as the head */
    if (*h == NULL && idx == 0)
    {
        new_node->prev = NULL;
        new_node->next = NULL;
        *h = new_node;
        return (new_node);
    }

    /* If the index is 0, insert the new node at the beginning of the list */
    if (idx == 0)
    {
        new_node->prev = NULL;
        new_node->next = *h;
        (*h)->prev = new_node;
        *h = new_node;
        return (new_node);
    }

    /* Traverse the list to find the node at the given index */
    current_node = *h;
    for (i = 0; current_node != NULL && i < idx; i++)
    {
        current_node = current_node->next;
    }

    /* If the index is beyond the end of the list, free the new node and return NULL */
    if (current_node == NULL && i == idx)
    {
        free(new_node);
        return (NULL);
    }

    /* If the index is beyond the end of the list, return NULL */
    if (current_node == NULL)
    {
        return (NULL);
    }

    /* Insert the new node at the given index */
    new_node->prev = current_node->prev;
    new_node->next = current_node;
    current_node->prev->next = new_node;
    current_node->prev = new_node;

    return (new_node);
}
