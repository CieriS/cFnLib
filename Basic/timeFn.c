#include <stdio.h>
#include "timeFn.h"

tempo leggiTime() {
	tempo time;
	do {
		puts("inserisci ore: (prime due cifre)");
		scanf_s("%2d", &(time.ora));
	} while (time.ora < 0 || time.ora > 23);
	do {
		puts("inserisci minuti: (prime due cifre)");
		scanf_s("%2d", &(time.min));
	} while (time.min < 0 || time.min > 59);
	do {
		puts("inserisci secondi: (prime due cifre)");
		scanf_s("%2d", &(time.sec));
	} while (time.sec < 0 || time.sec > 59);
	return time;
}

int leggiMoreTimes(tempo v[], int dim) {
	int i = 0;
	for (int i = 0; i < dim; i++) {
		v[i] = leggiTime();
	}
	return i;
}

int convertToSec(tempo t) {
	return (t.ora * 60 * 60) + (t.min * 60) + (t.sec);
}

tempo convertToTime(int secFin) {
	tempo tempoFin;
	tempoFin.ora = secFin / (60 * 60);
	secFin %= (60 * 60);
	tempoFin.min = secFin / 60;
	secFin %= 60;
	tempoFin.sec = secFin;
	return tempoFin;
}

tempo substract(tempo t1, tempo t2) {
	int secT1, secT2;
	secT1 = convertToSec(t1);
	secT2 =	convertToSec(t2);
	int secFin = secT1 > secT2 ? (secT1 - secT2) : (secT2 - secT1);
	return convertToTime(secFin);
}

tempo addUpTime(tempo t1, tempo t2) {
	int secT1, secT2, sumSec;
	secT1 = convertToSec(t1);
	secT2 = convertToSec(t2);
	sumSec = secT1 + secT2;
	return convertToTime(sumSec);
}