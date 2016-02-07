/*
 * BMFloatT4.c
 *
 *  Created on: Feb 6, 2016
 *      Author: pavan
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

double currentTime, blockCount2, blockCount3, blockCount4, numOfinstructions[60], numOfInstructions2[60], numOfInstructions3[60], numOfInstructions4[60];
const int delay_in_seconds = 1;
float first[10][10], second[10][10];
int isFinished, isFinished2, isFinished3, isFinished4;

void *threadproc(void *args)
{
	int done = 0;

	while(done < 10)
	{
		sleep(delay_in_seconds);
		numOfinstructions[done] = currentTime;
		numOfInstructions2[done] = blockCount2;
		numOfInstructions3[done] = blockCount3;
		numOfInstructions4[done] = blockCount4;
		currentTime = 0;
		blockCount2 = 0;
		blockCount3 = 0;
		blockCount4 = 0;
		done++;
	}

	isFinished = 1;
	isFinished2 = 1;
	isFinished3 = 1;
	isFinished4 = 1;

	return NULL;
}

void *complexFunction(void *agrs)
{
	int c, d, k, i, j, l, c2, d2, k2;
	float multiply[10][10], sum;
	float multiply1[10][10], sum1;
	float multiply2[10][10], sum2;
	printf("complex function thread1 started\n");

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

	printf("complex function thread1 finished\n");

	return NULL;
}

void *complexFunction2(void *agrs)
{
	int c, d, k, i, j, l, c2, d2, k2;
	float multiply[10][10], sum;
	float multiply1[10][10], sum1;
	float multiply2[10][10], sum2;
	printf("complex function thread2 started\n");

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
		blockCount2++;

		if(isFinished2 == 1)
			break;
	}

	printf("complex function thread2 finished\n");

	return NULL;
}

void *complexFunction3(void *agrs)
{
	int c, d, k, i, j, l, c2, d2, k2;
	float multiply[10][10], sum;
	float multiply1[10][10], sum1;
	float multiply2[10][10], sum2;
	printf("complex function thread3 started\n");

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


		blockCount3++;

		if(isFinished3 == 1)
			break;
	}

	printf("complex function thread3 finished\n");

	return NULL;
}

void *complexFunction4(void *agrs)
{
	int c, d, k, i, j, l, c2, d2, k2;
	float multiply[10][10], sum;
	float multiply1[10][10], sum1;
	float multiply2[10][10], sum2;
	printf("complex function thread4 started\n");

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


		blockCount4++;

		if(isFinished4 == 1)
			break;
	}

	printf("complex function thread4 finished\n");

	return NULL;
}

int main(int argc, char *argv[]) {
	int i,c;
	clock_t start, end;
	currentTime = 0;
	blockCount2 = 0;
	blockCount3 = 0;
	blockCount4 = 0;
	isFinished = 0;
	isFinished2 = 0;
	isFinished3 = 0;
	isFinished4 = 0;
	double totalInstructions;

	for(i = 0; i < 10; i++)
	{
		for(c = 0; c < 10; c++)
		{
			first[i][c] = rand() / 791;
			second[i][c] = rand() / 791;
		}
	}

	pthread_t tCounter, t[4];
	pthread_create(&tCounter, NULL, &threadproc, NULL);

	pthread_create(&t[0], NULL, &complexFunction, NULL);
	pthread_create(&t[1], NULL, &complexFunction2, NULL);
	pthread_create(&t[2], NULL, &complexFunction3, NULL);
	pthread_create(&t[3], NULL, &complexFunction4, NULL);

	for(i = 0; i < 4; i++)
		pthread_join(t[i], NULL);

	pthread_join(tCounter, NULL);

	for(i = 0; i < 10; i++)
	{
		totalInstructions = numOfinstructions[i] + numOfInstructions2[i] + numOfInstructions3[i] + numOfInstructions4[i];
		printf("GFLOPS = %f\t#OfInst = %g\n", ((totalInstructions) * 3000 * 54)/1000000000, totalInstructions);
	}

}

