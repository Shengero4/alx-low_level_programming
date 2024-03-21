#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the beginning of a dlistint_t list.
 * @head: Pointer to a pointer to the head of the doubly linked list
 * @n: Integer value to be stored in the new node
 *
 * Return: The address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
    dlistint_t *new_node;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    /* Initialize the new node */
    new_node->n = n;
    new_node->prev = NULL;

    /* If the list is empty, set the new node as the head */
    if (*head == NULL)
    {
        new_node->next = NULL;
    }
    else
    {
        /* Set the new node's next pointer to the current head */
        new_node->next = *head;

        /* Set the previous pointer of the current head to the new node */
        (*head)->prev = new_node;
    }

    /* Update the head to point to the new node */
    *head = new_node;

    return (new_node);
}
