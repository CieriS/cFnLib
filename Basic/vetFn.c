/*
 ============================================================================
 Author				: Samuele Cieri
 Matricola			: 0001060128
 Description		: libreria funzioni Cieri Samuele - Vettori
 ============================================================================
*/

#include <stdio.h>
#include "defCie.h"

int swapCount = 0;
int compCount = 0;

void incSwap() {
	swapCount++;
}

void incComp() {
	compCount++;
}

void resetCounters() {
	swapCount = 0;
	compCount = 0;
}

void printCounters() {
	printf("Numero di confronti effettuati: %d\n", compCount);
	printf("Numero di scambi effettuati: %d\n", swapCount);
}

void scambia(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

int isOrdered(int vet[], int dim) {
	int k, p = dim, o = 0;
	do {
		k = 0;
		for (int i = 0; i < (dim - 1); i++)
			if (vet[i] > vet[i + 1]) {
				o = k = 1;
				p = i + 1;
			}
		dim = p;
	} while (k == 1 && dim > 1);
	return o;
}

int bubbleSort(int vet[], int dim) {
	int k, p = dim;
	do {
		k = 0;
		for (int i = 0; i < (dim-1); i++)
			if (vet[i] > vet[i+1]) {
				scambia(&vet[i], &vet[i+1]);
				k = 1;
				p = i + 1;
			}
		dim = p;
	} while (k == 1 && dim > 1);
	return k;
}

int bubbleSortRevert(int vet[], int dim) {
	int k, p = dim;
	do {
		k = 0;
		for (int i = 0; i < (dim-1); i++)
			if (vet[i] < vet[i+1]) {
				scambia(&vet[i], &vet[i+1]);
				k = 1;
				p = i + 1;
			}
		dim = p;
	} while (k == 1 && dim > 1);
	return k;
}

int ricercaBinaria(int vet[], int dim, int srcEl) {
	int fst = 0, lst = dim-1, pos = -1, i;
	do {
		i = (fst + lst) / 2;
		if (vet[i] == srcEl)
			pos = i;
		else
			if (vet[i] < srcEl)
				fst = i + 1;
			else
				lst = i - 1;
	} while (fst <= lst && pos == -1);
	return pos;
}

void dxShift(int vet[], int dim) {
	int temp = vet[dim - 1];
	for (int i = dim - 1; i > 0; i--) {
		vet[i] = vet[i - 1];
	}
	vet[0] = temp;
	return;
}

void sxShift(int vet[], int dim) {
	int temp = vet[0];
	for (int i = 0; i <= dim - 1; i++) {
		vet[i] = vet[i + 1];
	}
	vet[dim - 1] = temp;
	return;
}

float avgVet(int vet[], int dim) {
	int c = 0;
	float media;
	for (int i = 0; i < dim; i++) {
		c += vet[i];
	}
	media = (float)c / dim;
	return media;
}

void vetCopy(int vetToCopy[], int dim, int finalVet[]) {
	for (int i = 0; i < dim; i++) {
		finalVet[i] = vetToCopy[i];
	}
	return;
}

void vetRevert(int vet[], int dim, int vet2[]) {
	vetCopy(vet, dim, vet2);
	for (int i = 0, j = (dim - 1); i <= (dim - 1); i++, j--) {
		vet2[j] = vet[i];
	}
	return;
}

int trovaPosMax(int v[], int n) {
	int i, posMax = 0;
	for (i = 1; i < n; i++) {
		incComp();
		if (v[posMax] < v[i]) {
			posMax = i;
			//incComp(); // ????
		}
	}
	return posMax;
}

void naiveSort(int v[], int n) {
	int p;
	while (n > 1) {
		p = trovaPosMax(v, n);
		// incComp(); // ???
		if (p < n - 1)
			scambia(&v[p], &v[n - 1]);
		n--;
	}
}

void insOrd(int v[], int pos) {
	int i = pos - 1, x = v[pos];
	while (i >= 0 && x < v[i]) {
		v[i + 1] = v[i]; /* crea lo spazio */
		i--;
	}
	v[i + 1] = x; /* inserisce l’elemento */
}

void insertionSort(int v[], int n) {
	int k;
	for (k = 1; k < n; k++)
		insOrd(v, k);
}

void merge(int v[], int i1, int i2,
	int fine, int vout[]) {
	int i = i1, j = i2, k = i1;
	while (i <= i2 - 1 && j <= fine) {
		if (v[i] < v[j])
			vout[k] = v[i++];
		else
			vout[k] = v[j++];
		k++;
	}
	while (i <= i2 - 1) { vout[k] = v[i++]; k++; }
	while (j <= fine) { vout[k] = v[j++]; k++; }
	for (i = i1; i <= fine; i++) v[i] = vout[i];
}

void mergeSort(int v[], int first, int last,
	int vout[]) {
	int mid;
	if (first < last) {
		mid = (last + first) / 2;
		mergeSort(v, first, mid, vout);
		mergeSort(v, mid + 1, last, vout);
		merge(v, first, mid + 1, last, vout);
	}
}

void quickSortR(int a[], int iniz, int fine) {
	int i, j, iPivot, pivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do /* trova la posizione del pivot */
		{
			while (i < j && a[i] <= pivot) i++;
			while (j > i && a[j] >= pivot) j--;
			if (i < j) scambia(&a[i], &a[j]);
		} while (i < j);
		/* determinati i due sottoinsiemi */
		 /* posiziona il pivot */
		if (i != iPivot && a[i] != a[iPivot])
		{
			scambia(&a[i], &a[iPivot]);
			iPivot = i;
		}
		/* ricorsione sulle sottoparti, se necessario */
		if (iniz < iPivot - 1)
			quickSortR(a, iniz, iPivot - 1);
		if (iPivot + 1 < fine)
			quickSortR(a, iPivot + 1, fine);
	} /* (iniz < fine) */
} /* quickSortR */

void quickSort(int a[], int dim) {
	quickSortR(a, 0, dim - 1);
}