/*
 ============================================================================
 Author				: Samuele Cieri
 Matricola			: 0001060128
 Description		: Ordering HEADER
 ============================================================================
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATED

#ifndef _ORDER_H
#define _ORDER_H

#include "element.h"
#include "list.h"

void stampaNum(numerello* l, int dim);
void scambia(numerello* a, numerello* b);

//prototipi naiveSort
int trovaPosMax(numerello* n, int dim, char* orderBy);
void naiveSorting(numerello* n, int dim, char* orderBy);

//prototipi bubbleSort
void bubbleSorting(numerello* n, int dim, char* orderBy);

//Esercizio insertion sort
void insOrd(numerello* n, int dim, char* orderBy);
void insertionSorting(numerello* n, int dim, char* orderBy);


//Esercizio merge sort
void merge(numerello* n, int i1, int i2, int fine, numerello* nout, char* orderBy);
void mergeSorting(numerello* n, int first, int last, numerello* nout, char* orderBy);


//Esercizio quick sort
void quickSortR(numerello* a, int iniz, int fine, char* orderBy);
void quickSorting(numerello* n, int dim, char* orderBy);

#endif