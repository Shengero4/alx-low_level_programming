#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list safely
 * @h: Pointer to a pointer to the head of the list
 *
 * Return: The size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
    listint_t *slow, *fast, *temp;
    size_t count = 0;

    if (h == NULL || *h == NULL)
        return (0);

    slow = *h;
    fast = (*h)->next;

    while (fast != NULL && fast != slow)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        free(temp);
        count++;
    }

    if (fast == slow)
    {
        count++;
        free(fast);
    }
    else
    {
        free(slow);
        count++;
    }

    *h = NULL;

    return (count);
}

