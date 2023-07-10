/*
 ============================================================================
 Author				: Samuele Cieri
 Matricola			: 0001060128
 Description		: LIST C
 ============================================================================
*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

// OPERAZIONI PRIMITIVE
list emptyList(void)		// costruttore lista vuota
{
	return NULL;
}

boolean empty(list l)	// verifica se lista vuota
{
	if (l == NULL)
		return true;
	else
		return false;
}

list cons(element e, list l)	// costruttore che aggiunge in testa alla lista
{
	list t;
	t = (list)malloc(sizeof(item));
	if (t != NULL) {
		t->value = e;
		t->next = l;
	}
	return(t);
}

element head(list l) // selettore testa lista
{
	if (empty(l))
		exit(-2);
	else
		return (l->value);
}

list tail(list l)         // selettore coda lista - scorre avanti
{
	if (empty(l))
		exit(-1);
	else
		return (l->next);
}

//	!!!
void showList(list l) {
	element temp;
	if (empty(l)) {
		puts("\n"); //due volte a capo
		return;
	}
	else {
		//showList(tail(l));					//metti qui per stampare al contrario
		temp = head(l);
		stampaElemento(head(l));
		//showList(tail(l));					//CAMBIARE NOME PER RICORSIONE
		return;
	}
}

void freeList(list l) {
	if (empty(l))
		return;
	else {
		freeList(tail(l));
		free(l);
	}
	return;
}

// EXTRA
list addTail(element e, list l)	// costruttore che aggiunge in coda alla lista
{
	if (!empty(l)) {
		list nodoSuccessivo = l;
		while (nodoSuccessivo->next != NULL) {
			nodoSuccessivo = nodoSuccessivo->next;
		}
		nodoSuccessivo->next = cons(e, NULL);
	}
	else {
		l = cons(e, l);
	}
	return l;
}

list addPos(element e, int p, list l) // aggiunge elemento e in posizione p nella lista l
{
	if (p == 0 || l == NULL) {
		l = cons(e, l);
	}
	else if (p > 0) {
		int i = 1;
		list nodoSuccessivo = l;
		while (i < p && nodoSuccessivo->next != NULL) {
			nodoSuccessivo = nodoSuccessivo->next;
			i++;
		}
		nodoSuccessivo->next = cons(e, nodoSuccessivo->next);
	}
	return l;
}

list rmHead(list l)	//ex chiamata: "lista = rmHead(lista);"
{
	if (!empty(l)) {
		list daEliminare = l;
		l = l->next;
		free(daEliminare);
	}
	return l;
}

list rmTail(list l)	//rimuovi in coda 	//ex chiamata: "lista = rmTail(lista);"
{
	if (!empty(l)) {
		if (!empty(l->next)) {

			list attuale = l;
			list daEliminare = l->next;

			while (!empty(daEliminare->next)) {
				attuale = daEliminare;
				daEliminare = daEliminare->next;
			}
			attuale->next = rmHead(daEliminare);
		}
		else {
			l = rmHead(l);
		}
	}
	return l;
}

list rmPos(int p, list l)	//rimuovi in posizione n 	//il primo elemento ha posizione 0
{
	if (p == 0 || empty(l)) {
		l = rmHead(l);
	}
	else if (p > 0) {
		int i = 1;
		list attuale = l;
		list daEliminare = l->next;
		while (i < p && daEliminare->next != NULL) {
			attuale = daEliminare;
			daEliminare = daEliminare->next;
			i++;
		}
		attuale->next = rmHead(daEliminare);
	}
	return l;
}


list insord_p(element el, list l) {
	list pprec = emptyList(), patt = l, paux = emptyList();
	boolean trovato = 0;
	while (!empty(patt) && !trovato) {
		if (isLess(el, head(patt)))												//compare con result 1, -1 o 0 ----> el < patt->value {prima del nodo attuale <}
			trovato = 1;
		else {
			pprec = patt;
			patt = tail(patt);
		}
	}
	paux = (list)malloc(sizeof(item));
	if (paux == NULL) {
		puts("\n\x1B[1;90mpaux restituisce NULL: insord_p function\x1B[0m");
		perror("\033[4;91mErrore di allocazione dinamica\033[0m");				//Messaggio per gli errori allocazione dinamica
		exit(exitErrAlloc);														//Uscita per errore di allocazione dinamica
	}
	paux->value = el;
	paux->next = patt;
	if (patt == l)
		return paux;
	else {
		pprec->next = paux;
		return l;
	}
}

list orderList(list l) {
	list l2 = emptyList();

	while (!empty(l)) {
		l2 = insord_p(head(l), l2);
		l = tail(l);
	}

	return l2;
}

list mergeList(list l1, list l2) {
	if (empty(l1)) return l2;
	else if (empty(l2)) return l1;
	else {
		if (isLess(head(l1), head(l2)))
			return cons(head(l1), mergeList(tail(l1), l2));
		else if (isEqual(head(l1), head(l2)))
			return cons(head(l1), mergeList(tail(l1), tail(l2)));
		else return cons(head(l2), mergeList(l1, tail(l2)));
	}
}

list subListIt(int n, list l) {		// il primo elemento ha posizione 1
	int i = 1;
	while ((l != NULL) && (i < n)) {
		l = l->next;
		i++;
	}
	return l;
}
list subListRec(int n, list l) {		// il primo elemento ha posizione 1
	if ((n == 1) || (l == NULL))
		return l;
	else
		return (subListRec(n - 1, l->next));
}

boolean memberIt(element el, list l) //restituisce vero o falso a seconda se l'elemento dato è presente nella lista data
{
	while (!empty(l)) {
		if (isEqual(el, head(l)))
			return true;
		else
			l = tail(l);
	}
	return false;
}
boolean memberRec(element el, list l) //restituisce vero o falso a seconda se l'elemento dato è presente nella lista data
{
	if (empty(l))
		return false;
	else if (isEqual(el, head(l)))
		return true;
	else
		return memberRec(el, tail(l));
}

int cercaInLista(element el, list l)	//restituisce la posizione dell'elemento trovato
{
	int posizione = -1;
	int trovato = 0;
	int i = 0;
	while (l != NULL && trovato == 0) {
		if (isEqual(el, head(l))) {
			posizione = i;
			trovato = 1;
		}
		i++;
		l = l->next;
	}
	return posizione;
}

void contaList(list l, int* counter) //lunghezza lista
{
	*counter = 0;
	while (!empty(l)) {
		(*counter)++;
		l = tail(l);
	}
	return;
}
int contaListIt(list l) //lunghezza lista
{
	int n = 0;
	while (!empty(l)) {
		n++;
		l = tail(l);
	}
	return n;
}
int contaListRec(list l) //lunghezza lista
{
	if (empty(l))
		return 0;
	else
		return 1 + contaListRec(tail(l));
}

list concatList(list l1, list l2) //concatena due liste costruendone una terza
{
	if (empty(l1))
		return l2;
	else
		return cons(head(l1), concatList(tail(l1), l2));
}

list reverseList(list l)	//genera una lista che è l'inverso di quella in ingresso
{
	if (empty(l))	//Recursive
		return l;
	else
		return addTail(head(l), reverseList(tail(l)));
}

list copyList(list l)	//duplica una lista
{
	if (empty(l))	//Recursive
		return l;
	else
		return cons(head(l), copyList(tail(l)));
}

boolean listEqual(list p, list q)	//1 se liste uguali 0 se liste diverse		// USA isEqual
{
	if (empty(p) && empty(q)) {
		return 1;
	}
	else if (!empty(p) && !empty(q) && isEqual(head(p), head(q))) {
		return listEqual(tail(p), tail(q));
	}
	else
		return 0;
}

list delete(element el, list l) {
	if (empty(l))
		return emptyList();
	else if (el == head(l))
		return copy(tail(l));
	else
		return cons(head(l), delete(el, tail(l)));
}