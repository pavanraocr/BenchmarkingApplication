/*
/*
 * progFloatT1.c
 *
 *  Created on: Feb 2, 2016
 *      Author: pavan
 */


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

double currentTime, numOfinstructions[60];
const int delay_in_seconds = 1;
float first[10][10], second[10][10];
int isFinished;

void *threadproc(void *args)
{
	int done = 0;

	while(done < 10)
	{
		sleep(delay_in_seconds);
		numOfinstructions[done] = currentTime;
		currentTime = 0;
		done++;
	}

	isFinished = 1;

	return NULL;
}

int complexFunction()
{
	int c, d, k;
	float  multiply[10][10], sum;
	int i, j, l, multiply1[10][10], sum1;
	printf("complex function started\n");

	for(;;){
		for (c = 0; c < 10; c++) {
			for (d = 0; d < 10; d++) {
				for (k = 0; k < 10; k++) {
					sum = sum + first[c][k]*second[k][d];
				}
				multiply[c][d] = sum;
				sum = 0;
			}
		}
		currentTime++;

		if(isFinished == 1)
			break;
	}

	printf("complex function finished\n");

	return 0;
}

int main(int argc, char *argv[]) {
	int i,c;
	clock_t start, end;
	currentTime = 0;
	isFinished = 0;

	for(i = 0; i < 10; i++)
	{
		for(c = 0; c < 10; c++)
		{
			first[i][c] = rand() / 791;
			second[i][c] = rand() / 791;
		}
	}

	pthread_t tCounter;
	pthread_create(&tCounter, NULL, &threadproc, NULL);

	i = complexFunction();

	for(i = 0; i < 10; i++)
	{
		printf("%f\n", (numOfinstructions[i] * 1000 * 6)/1000000000);
	}
}


