/*
 * prog.c
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
int first[10][10], second[10][10];
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

void *complexFunction(void *agrs)
{
	int c, d, k, multiply[10][10], sum;
	int i, j, l, multiply1[10][10], sum1;
	int c2, d2, k2, multiply2[10][10], sum2;
	printf("complex function started\n");

	for(;;){
		for (c = 0; c < 10; c++)
		{
			for (d = 0; d < 10; d++)
			{
				for (k = 0; k < 10; k++)
				{
					sum = sum + first[c][k]*second[k][d] + second[c][k]*first[k][d] + second[c][k] - first[k][d] + second[k][d] * second[k][d] * second[k][d] - first[k][d] * first[k][d] * first[k][d] + second[c][d]*first[k][d] * second[c][d]*first[k][d] * second[c][d]*first[k][d];
				}
				multiply[c][d] = sum;
				sum = 0;
			}
		}


		for (c2 = 0; c2 < 10; c2++)
		{
			for (d2 = 0; d2 < 10; d2++)
			{
				for (k2 = 0; k2 < 10; k2++)
				{
					sum2 = sum2 + first[c2][k2]*second[k2][d2] + second[c2][k2]*first[k2][d2] + second[c2][k2] - first[k2][d2] + second[c2][k2] * second[c2][k2] * second[c2][k2] - first[k2][d2] * first[k2][d2] * first[k2][d2] + second[c2][d2]*first[k2][d2] * second[c2][d2]*first[k2][d2] * second[c2][d2]*first[k2][d2];
				}
				multiply2[c][d] = sum2;
				sum2 = 0;
			}
		}


		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				for (l = 0; l < 10; l++)
				{
					sum1 = sum1 + first[i][l]*second[l][j] + second[i][l]*first[l][j] + second[i][l] - first[l][j] + second[i][l] * second[i][l] * second[i][l] + first[l][j] *first[l][j] * first[l][j] + first[i][j]*second[l][j]*first[i][j]*second[l][j]*first[i][j]*second[l][j] ;
				}
				multiply1[i][j] = sum1;
				sum1 = 0;
			}
		}


		currentTime++;

		if(isFinished == 1)
			break;
	}

	printf("complex function finished\n");

	return NULL;
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
			first[i][c] = rand() % 791;
			second[i][c] = rand() % 791;
		}
	}

	pthread_t tCounter, t1;
	pthread_create(&tCounter, NULL, &threadproc, NULL);
	pthread_create(&t1, NULL, &complexFunction, NULL);

	pthread_join(t1, NULL);
	pthread_join(tCounter, NULL);

	for(i = 0; i < 10; i++)
	{
		printf("GFLOPS = %f\t#OfInst = %g\n", (numOfinstructions[i] * 3000 * 54)/1000000000, numOfinstructions[i]);
	}

}
