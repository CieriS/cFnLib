/*
 ============================================================================
 Author				: Samuele Cieri
 Matricola			: 0001060128
 Description		: main function
 ============================================================================
*/

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <time.h>
//#include <limits.h>	//max e min delle variabili

//#include "timeFn.h"
//#include "vetFn.h"

#include "element.h"
#include "list.h"
//#include "modulo.h"

int main(void) {

	puts("\033[1;100mTitolo Compito - Samuele Cieri { 0001060128 } - Gio 06/07/2023\x1B[0m");

	//	<variableDeclaration>
	
	//	</variableDeclaration>


	//	<Esercizio 1>
	puts("\033[1;92mEsercizio 1\033[0m");
	puts("\x1B[1;90mElenco Array:\x1B[0m");

	puts("\x1B[1;90mElenco Lista:\x1B[0m");

	puts("\x1B[1;90m--------------------------------\x1B[0m\n");
	//	</Esercizio 1>




	//	<Esercizio 2>
	puts("\033[1;93mEsercizio 2\033[0m");

	puts("\x1B[1;90m--------------------------------\x1B[0m\n");
	//	</Esercizio 2>




	//	<Esercizio 3>
	puts("\033[1;96mEsercizio 3\033[0m");

	puts("\x1B[1;90m--------------------------------\x1B[0m\n");
	//	</Esercizio 3>




	//	<Esercizio 4>
	puts("\033[0;95mEsercizio 4 ---> Funzione Main\033[0m");

	puts("\x1B[1;90m--------------------------------\x1B[0m\n");
	//	</Esercizio 4>


	
	/*
	//	<Deallocazione, ChiusuraFile>
	free();
	freeList();
	fclose();
	//	</Deallocazione, ChiusuraFile>



	/* Formattazione

	printf("\n\x1B[1;90m%s:\x1B[0m\n", fileName);
	perror("\033[4;91mErrore apertura file\033[0m");				//Messaggio per gli errori apertura file
	exit(exitErrFile);												//Uscita per errore apertura file

	puts("\n\x1B[1;90mNome Puntatore:\x1B[0m");
	perror("\033[4;91mErrore di allocazione dinamica\033[0m");		//Messaggio per gli errori allocazione dinamica
	exit(exitErrAlloc);												//Uscita per errore di allocazione dinamica

	perror("\033[4;91mErrore\033[0m");								//Messaggio per gli errori generici
	exit(exitErrGeneric);											//Uscita per errore generico



	//ORDINAMENTO: MAIN
	int dimMax = 10;
	numerello* test = (numerello*)malloc(sizeof(numerello)*dimMax);
	numerello* test2 = (numerello*)malloc(sizeof(numerello)*dimMax);
	if (test == NULL || test2 == NULL) {
		return 0;
	}
	test[0].x = 4;
	test[1].x = 7;
	test[2].x = 1;
	test[3].x = 4;
	test[4].x = 8;
	test[5].x = 5;
	test[6].x = 0;
	test[7].x = 2;
	test[8].x = 6;
	test[9].x = 9;
	test[0].c = "Dariozzo";
	test[1].c = "Harry";
	test[2].c = "Boris";
	test[3].c = "Elena";
	test[4].c = "Ilenia";
	test[5].c = "Franco";
	test[6].c = "Alberto";
	test[7].c = "Carlo";
	test[8].c = "Gianluca";
	test[9].c = "Luca";
	puts("\x1B[1;30mElenco Default:\x1B[0m");
	stampaNum(test, dimMax);
	puts("\x1B[1;30mElenco Naive Sort:\x1B[0m");
	//naiveSorting(test, dimMax, "ASC");				stampaNum(test, dimMax);
	//naiveSorting(test, dimMax, "DESC");				stampaNum(test, dimMax);
	puts("\x1B[1;30mElenco Bubble Sort:\x1B[0m");
	//bubbleSorting(test, dimMax, "ASC");				stampaNum(test, dimMax);
	//bubbleSorting(test, dimMax, "DESC");				stampaNum(test, dimMax);
	puts("\x1B[1;30mElenco Insertion Sort:\x1B[0m");
	//insertionSorting(test, dimMax, "ASC");			stampaNum(test, dimMax);
	//insertionSorting(test, dimMax, "DESC");			stampaNum(test, dimMax);
	puts("\x1B[1;30mElenco Merge Sort:\x1B[0m");
	//mergeSorting(test, 0, dimMax - 1, test2, "ASC");	stampaNum(test, dimMax);
	//mergeSorting(test, 0, dimMax - 1, test2, "DESC");	stampaNum(test, dimMax);
	puts("\x1B[1;30mElenco Quick Sort:\x1B[0m");
	//quickSorting(test, dimMax, "ASC");				stampaNum(test, dimMax);
	//quickSorting(test, dimMax, "DESC");				stampaNum(test, dimMax);



	lettura stringa con spazi delimitata da ';'
	char c;
	tipoStrutturato s;
	int i = 0;
	fgetc(fp);							//scarto lo spazio
	do{

		c = fgetc(fp);					//raccolgo carattere
		s.nome[i++] = c;				//lo inserisco in posizione i nella stringa

	} while(c != ';' && i < DIM);		//oppure se delimitato da 'a capo' --> (c != '\n') && (c != EOF) && (i < DIM)
	s.nome[i] = '\0'					//inserisco terminatore di stringa
										//assegno la stringa generata

	*/



	return 0;
}