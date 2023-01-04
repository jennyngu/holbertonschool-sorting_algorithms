#include "sort.h"

/**
 * swap_pair - swaps any pair of a doubly linked list except the last
 * @index: a node to be swaped
 * @temp: a node to be swaped
 * @list: a pointer to the head of the list
*/

void swap_pair(listint_t *index, listint_t *temp, listint_t **list)
{
	if (index->next != NULL)
	{
		temp->next = index->next;
		index->next = index->prev;
		index->prev = index->next->prev;
		temp->prev = temp->next->prev;
		temp->next->prev = index->next;
	}

	if (index->prev == NULL)
	{
		*list = index;
	}
	else
	{
		index->prev->next = temp->prev;
	}
}

/**
 * swap_last_pair - swaps the last pair of a doubly linked list
 * @index: the last node of a doubly linked list
 * @temp: the previous node
*/

void swap_last_pair(listint_t *index, listint_t *temp)
{
	index->next = index->prev;
	index->prev = index->next->prev;
	temp->prev = temp->next;
	index->prev->next = temp->prev;
	temp->next = NULL;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: a pointer to the head of a doubly linked list
 *
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *index;
	listint_t *temp;
	int sorted;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	if ((*list)->next->next == NULL)
	{
		index = (*list)->next;
		temp = *list;
		if (index->n < temp->n)
		{
			index->next = index->prev;
			temp->prev = temp->next;
			index->prev = NULL;
			temp->next = NULL;
			*list = index;
		}
		return;
	}

	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		index = *list;
		temp = *list;
		while (index->next != NULL)
		{
			if (index->n < temp->n)
			{
				swap_pair(index, temp, list);
				print_list(*list);
				index = index->next;
				sorted = 0;
			}
			index = index->next;
			temp = index->prev;
		}
		if (index->n < temp->n && index->next == NULL)
		{
			swap_last_pair(index, temp);
			print_list(*list);
		}
	}
}
