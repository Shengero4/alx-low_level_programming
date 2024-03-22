#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at index of a dlistint_t list.
 * @head: Pointer to a pointer to the head of the doubly linked list
 * @index: Index of the node to delete
 *
 * Return: 1 if successful, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current_node, *temp;
    unsigned int i;

    /* If the list is empty, return -1 */
    if (*head == NULL)
        return (-1);

    /* If index is 0, delete the first node */
    if (index == 0)
    {
        temp = *head;
        *head = (*head)->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return (1);
    }

    /* Traverse the list to find the node at the given index */
    current_node = *head;
    for (i = 0; current_node != NULL && i < index; i++)
    {
        current_node = current_node->next;
    }

    /* If the index is beyond the end of the list, return -1 */
    if (current_node == NULL)
        return (-1);

    /* If the node to delete is the last node */
    if (current_node->next == NULL)
    {
        current_node->prev->next = NULL;
        free(current_node);
        return (1);
    }

    /* If the node to delete is in the middle of the list */
    current_node->prev->next = current_node->next;
    current_node->next->prev = current_node->prev;
    free(current_node);
    return (1);
}
