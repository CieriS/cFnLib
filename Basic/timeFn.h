typedef struct time {
	int ora, min, sec;
} tempo;

typedef struct date {
	int a, m, g;
} data;

typedef struct datetime {
	data d;
	tempo t;
} datetime;

tempo leggiTime();

int convertToSec(tempo tempoDaConvertireInSecondi);

tempo convertToTime(int tempoDaConvertireInOrario);

int leggiMoreTimes(tempo vettore[], int dimensione);

tempo substract(tempo primoTempo, tempo secondoTempo);

tempo addUpTime(tempo primoTempo, tempo secondoTempo);