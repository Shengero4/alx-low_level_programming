#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list
 * @head: Pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *slow, *fast;
    size_t count = 0;

    if (head == NULL)
        return (0);

    slow = head;
    fast = head->next;

    while (fast != NULL && fast != head)
    {
        printf("[%p] %d\n", (void *)slow, slow->n);
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        count++;
    }

    if (fast == head)
    {
        printf("-> [%p] %d\n", (void *)slow, slow->n);
        count++;
    }
    else
    {
        printf("[%p] %d\n", (void *)slow, slow->n);
        count++;
    }

    return (count);
}

