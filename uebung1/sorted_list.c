#include <stddef.h>
#include <stdlib.h>
#include "sorted_list.h"

struct SortedLinkedListNode
{
	SortedLinkedListNode* next;
	int data;
};

struct SortedLinkedList
{
	SortedLinkedListNode* first;
};

SortedLinkedList* SortedLinkedList_create() {
	SortedLinkedList* linkedList = malloc( sizeof(SortedLinkedList) );
	linkedList->first = NULL;
	return linkedList;
}

void SortedLinkedList_addToList( SortedLinkedList* list, int data ) {
	SortedLinkedListNode* new_node = malloc( sizeof(SortedLinkedListNode) );
	new_node->data = data;
	if (list->first == NULL) list->first = new_node;
	else {
		SortedLinkedListNode* actual_node = list->first;
		SortedLinkedListNode* next_node;
		while (actual_node->next != NULL) {
			next_node = actual_node->next;
			if (next_node->data > data) { // es gibt Node mit größerem Wert in der Liste
				new_node->next = actual_node->next; // neuer Node soll auf größeren Node zeigen
				actual_node->next = new_node; // vorheriger Node soll auf neuen Node zeigen
				return;
			}
		}
		actual_node->next = new_node; // es gab keinen größeren Node: hänge neuen Node ans Ende der Liste
		new_node->next = NULL;
	}
	return;
}

void SortedLinkedList_delete( SortedLinkedList* list ) {
	if (list->first == NULL) free( list ); 
	else {
		SortedLinkedListNode* actual_node = list->first;
		SortedLinkedListNode* next_node;
		while (actual_node != NULL) {
			next_node = actual_node->next;
			free( actual_node );
		}
	}
	free( list );
	return;
}

SortedLinkedListNode* SortedLinkedList_getSmallest( SortedLinkedList* list ) {
	if (list->first == NULL) return NULL;
	else return list->first;
}

int main() {
	
}