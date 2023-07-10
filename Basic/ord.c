/*
 ============================================================================
 Author				: Samuele Cieri
 Matricola			: 0001060128
 Description		: Ordering C
 ============================================================================
*/


#include "ord.h"

//funzioni trasversali
void stampaNum (numerello* l, int dim){
	for (int i = 0; i < dim; i++) {
		printf("%s ----> %d\n", l[i].c, l[i].x);
	}
	return;
}
void scambia(numerello *a, numerello *b) {
	numerello temp = *a;
	*a = *b;
	*b = temp;
	return;
}


//Esercizio naive sort
int trovaPosMax(numerello* n, int dim, char* orderBy) {
	int i, posMax = 0;
	for (i = 1; i < dim; i++) {
		if (orderBy == "ASC")
			if ((compare(n[i], n[posMax])) >= 0)			//Crescente
				posMax = i;
		if (orderBy == "DESC")
			if ((compare(n[i], n[posMax])) <= 0)			//Decrescente
				posMax = i;
	}
	return posMax;
}
void naiveSorting(numerello* n, int dim, char* orderBy) {
	if (dim <= 0 && (!strcmp(orderBy, "ASC") || !strcmp(orderBy, "DESC"))) {
		puts("\033[4;31mErrore ordinamento naive sort\033[0m");
		exit(exitErrGeneric);
	}
	int posMax;
	while (dim > 1) {							//finché l'array ha più di un'unità
		posMax = trovaPosMax(n, dim, orderBy);	//trova la posizione del elemento max
		if (posMax < (dim-1))					//Se il valore max si trova prima dell'ultima posizione:
			scambia(&(n[posMax]), &(n[dim-1]));	//scambio valore max con ultima posizione array
		dim--;									//tolgo l'ultimo valore (il max), quindi l'array diminuisce
	}
	return;
}


//Esercizio bubble sort
void bubbleSorting(numerello* n, int dim, char* orderBy) {
	if (dim <= 0 && (!strcmp(orderBy, "ASC") || !strcmp(orderBy, "DESC"))) {
		puts("\033[4;31mErrore ordinamento bubble sort\033[0m");
		exit(exitErrGeneric);
	}
	int i, arrayOrdinato = 0;
	while (dim > 1 && !arrayOrdinato) {				//finché l'array ha più di un'unità ed è disordinato
		arrayOrdinato = 1;							//l'array è ordinato
		for (i = 0; i < (dim-1); i++) {
			if (orderBy == "ASC")
				if ((compare(n[i], n[i + 1])) >= 0) {			//se n[i]>n[i+1]:	//compare determina se l'ordine è crescente o decrescente
					scambia(&(n[i]), &(n[i + 1]));		//scambio elementi
					arrayOrdinato = 0;					//array disordinato
				}
			if (orderBy == "DESC")
				if ((compare(n[i], n[i + 1])) <= 0) {			//se n[i]>n[i+1]:	//compare determina se l'ordine è crescente o decrescente
					scambia(&(n[i]), &(n[i + 1]));		//scambio elementi
					arrayOrdinato = 0;					//array disordinato
				}
		}
		dim--;										//diminuisco la grandezza dell'array
	}
	return;
}


//Esercizio insertion sort
void insOrd(numerello* n, int pos, char* orderBy) {
	int i = pos - 1;
	numerello x = n[pos];
	if (orderBy == "ASC") {
		while (i >= 0 && (compare(n[i], x)) >= 0) {				// compare determina se crescente o decrescente
			n[i + 1] = n[i];					//traslo di 1 per creare lo spazio per l'inserimento
			i--;
		}
		n[i + 1] = x;
	}
	if (orderBy == "DESC") {
		while (i >= 0 && (compare(n[i], x)) <= 0) {				// compare determina se crescente o decrescente
			n[i + 1] = n[i];					//traslo di 1 per creare lo spazio per l'inserimento
			i--;
		}
		n[i + 1] = x;								//inserimento elemento
	}
	return;
}
void insertionSorting(numerello* n, int dim, char* orderBy) {
	if (dim <= 0 && (!strcmp(orderBy, "ASC") || !strcmp(orderBy, "DESC"))) {
		puts("\033[4;31mErrore ordinamento insertion sort\033[0m");
		exit(exitErrGeneric);
	}
	int i;
	for (i = 0; i < dim; i++) {					//esegue insOrd per ogni posizione dell'array
		insOrd(n, i, orderBy);
	}
	return;
}


//Esercizio merge sort
void merge(numerello* n, int i1, int i2, int fine, numerello* nout, char* orderBy) {
	int i = i1, j = i2, k = i1;
	while (i <= (i2-1) && j <= fine) {
		if (orderBy == "ASC")
			if ((compare(n[j], n[i])) >= 0)										// compare(n[i], n[j])		n[i].x < n[j].x
				nout[k] = n[i++];
			else
				nout[k] = n[j++];
		if (orderBy == "DESC")
			if ((compare(n[j], n[i])) <= 0)										// compare(n[i], n[j])		n[i].x < n[j].x
				nout[k] = n[i++];
			else
				nout[k] = n[j++];
		k++;
	}
	while (i <= (i2 - 1)) {
		nout[k] = n[i++];
		k++;
	}
	while (j <= fine) {
		nout[k] = n[j++];
		k++;
	}
	for (i = i1; i <= fine; i++) {
		n[i] = nout[i];
	}
	return;
}
void mergeSorting(numerello* n, int first, int last, numerello* nout, char* orderBy) {
	int mid;
	if (first < last) {
		mid = (first + last) / 2;
		mergeSorting(n, first, mid, nout, orderBy);
		mergeSorting(n, mid + 1, last, nout, orderBy);
		merge(n, first, mid + 1, last, nout, orderBy);
	}
	return;
}


//Esercizio quick sort
void quickSortR(numerello* a, int iniz, int fine, char* orderBy) {
	int i, j, iPivot;
	numerello pivot;
	if (iniz < fine) {
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do {																// trova posizione pivot
			if (orderBy == "ASC") {
				while (i < j && (compare(a[i], pivot)) <= 0)								// a[i].x <= pivot.x	(compare(a[i], pivot)) <= 0
					i++;
				while (j > i && (compare(a[j], pivot)) >= 0)								//	a[j].x >= pivot.x	(compare(a[i], pivot)) >= 0
					j--;
			}																// trova posizione pivot
			if (orderBy == "DESC") {
				while (i < j && (compare(a[i], pivot)) >= 0)	//(compare(a[i], pivot)) >= 0
					i++;
				while (j > i && (compare(a[j], pivot)) <= 0)	//(compare(a[i], pivot)) <= 0
					j--;
			}
			if (i < j)
				scambia(&(a[i]), &(a[j]));
		} while (i < j);

		if (i != iPivot && (compare(a[i], a[iPivot])) != 0) {									//(compare(a[i], a[iPivot])) != 0		a[i].x != a[iPivot].x
			scambia(&(a[i]), &(a[iPivot]));		
			iPivot = i;															//posiziono il pivot
		}
		if (iniz < (iPivot - 1))											//ricorsione se necessaria sulle sottoparti
			quickSortR(a, iniz, iPivot - 1, orderBy);
		if ((iPivot + 1) < fine)
			quickSortR(a, iPivot + 1, fine, orderBy);
	}
	return;
}
void quickSorting(numerello* n, int dim, char* orderBy) {
	if (dim <= 0 && (!strcmp(orderBy, "ASC") || !strcmp(orderBy, "DESC"))) {
		puts("\033[4;31mErrore ordinamento quick sort\033[0m");
		exit(exitErrGeneric);
	}
	quickSortR(n, 0, dim - 1, orderBy);
}