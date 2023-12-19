#ifndef _LISTS_H_
#define _LISTS_H_

/**
 * struct listint_t - self referencial struct
 * for nodes creation
 *
 * @n: interger data
 * @next: pointer
 * pointer to the next node of list
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

size_t print_listint(const listini_t*h);

#endif
