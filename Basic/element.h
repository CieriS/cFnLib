/*
 ============================================================================
 Author				: Samuele Cieri
 Matricola			: 0001060128
 Description		: STRUCT, Macro & type definition
 ============================================================================
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATED

#ifndef _ELEMENT_H
#define _ELEMENT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

//codici di uscita
#define exitErrAlloc -3		//errore allocazione dinamica non riuscita (MALLOC == NULL)
#define exitErrFile -2		//errore apertura file non riuscito (STREAM == NULL)
#define exitErrGeneric -1	//errore di uscita generico (Uscite anomale da funzioni, etc...)
#define FAILURE 0			//false
#define SUCCESS 1			//true

//dimensioni stringhe nelle strutture dati
#define dimCodice 6
#define dimNomeSpecie 21
#define dimTipo 2
#define dimNomeAvvistamento 16

typedef struct {
	int x;
	char* c;
} numerello;

typedef struct birdType {
	char codice[dimCodice], nome[dimNomeSpecie];
	float raro;
	char tipo[dimTipo];
} Specie;

typedef struct uccelliVisti {
	char nome[dimNomeAvvistamento], codice[dimCodice];
	unsigned int numero, distanza;
} Avvistamento;

typedef numerello element;

typedef enum {
	false,
	true
} boolean;

int isEqual(element primoElemento, element secondoElemento);

int isLess(element primoElemento, element secondoElemento);

element getElement(void);

void stampaElemento(element elemento);

int compare(numerello b1, numerello b2);

#endif