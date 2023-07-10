/*
 ============================================================================
 Author				: Samuele Cieri
 Matricola			: 0001060128
 Description		: LIST HEADER
 ============================================================================
*/

#pragma once
#ifndef LIST_H
#define LIST_H

#include "element.h"

typedef struct list_element {
	element value;
	struct list_element* next;
} item;

typedef  item* list;

// <PRIMITIVE>
list emptyList(void);
boolean empty(list lista);
list cons(element elemento, list lista);
element head(list);
list tail(list);

void showList(list lista);
void freeList(list lista);

// <EXTRA>
list addTail(element elemento, list lista);
list addPos(element elemento, int posizione, list lista);
list rmHead(list lista);
list rmTail(list lista);
list rmPos(int posizione, list lista);

list insord_p(element elemento, list lista);
list orderList(list lista);
list mergeList(list primaLista, list secondaLista);

list subListIt(int posizione, list lista);
list subListRec(int posizione, list lista);

boolean memberIt(element elementoDaCercare, list lista);
boolean memberRec(element elementoDaCercare, list lista);

int cercaInLista(element elementoDaCercare, list lista);

void contaList(list lista, int* counter);
int contaListIt(list lista);
int contaListRec(list lista);

list concatList(list primaLista, list secondaLista);

list reverseList(list lista);

list copyList(list lista);

boolean listEqual(list primaLista, list secondaLista);

list delete(element elementoDaCancellare, list lista);

#endif