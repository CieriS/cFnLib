/*
 ============================================================================
 Author				: Samuele Cieri
 Matricola			: 0001060128
 Description		: libreria funzioni Cieri Samuele - Ordinamento e Ricerca
 ============================================================================
*/

void incSwap();

void incComp();

void resetCounters();

void printCounters();

void scambia(int *primaVariabile, int *secondaVariabile);

int isOrdered(int vettore[], int dimensione);

void bubbleSort(int vettore[], int dimensione);

int bubbleSortRevert(int vettore[], int dimensione);

int ricercaBinaria(int vettore[], int dimensione, int elementoCercato);

void dxShift(int vettore[], int dimensione);

void sxShift(int vettore[], int dimensione);

float avgVet(int vettore[], int dimensione);

void vetCopy(int vettoreSorgente[], int dimesione, int vettoreDestinazione[]);

void vetRevert(int vettoreSorgente[], int dimensione, int vettoreDestinazione[]);

int trovaPosMax(int vettoreSorgente[], int dimensione);

void naiveSort(int vettoreSorgente[], int dimensione);

void insOrd(int vettoreSorgente[], int posizione);

void insertionSort(int vettoreSorgente[], int dimensione);

void merge(int vettoreSorgente[], int i1, int i2,
	int fine, int vout[]);

void mergeSort(int vettoreSorgente[], int first, int last,
	int vout[]);

void quickSortR(int a[], int iniz, int fine);

void quickSort(int a[], int dim);