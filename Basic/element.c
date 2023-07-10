/*
 ============================================================================
 Author				: Samuele Cieri
 Matricola			: 0001060128
 Description		: element C
 ============================================================================
*/

#include "element.h"

int isEqual(element e1, element e2) {
	return ( ( e1.x == e2.x ) && ( !strcmp(e1.c, e2.c) ) );
}

int isLess(element e1, element e2) {
	return ( ( e1.x < e2.x ) && ( (strcmp(e1.c, e2.c)) < 0 ) );
}

element getElement(void) {
	element el;
	int res;
	do {
		puts("inserisci x:");
		res = scanf("%d", &(el.x));
	} while ( res != 1 );
	do {
		puts("inserisci c:");
		res = scanf("%s", el.c);
	} while ( res != 1 );
	return el;
}

void stampaElemento(element el) {
	printf("%s --> %d\n", el.c, el.x);
}

/*
int compare(numerello b1, numerello b2) {
	if (b1.x < b2.x)
		return -1;
	else if (b1.x > b2.x)
		return 1;
	else
		return strcmp(b1.c, b2.c);
}
*/