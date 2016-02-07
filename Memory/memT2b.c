/*
 * memT1m.c
 *
 *  Created on: Feb 7, 2016
 *      Author: pavan
 */

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<pthread.h>

const int memorySize = 100 * 1024 *1024;
char *mainBlk, *coping;
int intermediateSize = 1;
int fullSize;

void *transfer(void *argv)
{
	int i;
	for(i = 0; i < fullSize; i +=intermediateSize)
	{
		memcpy(coping, (mainBlk + i), intermediateSize);
	}
}

void main(void *argv)
{
	fullSize = memorySize;
	mainBlk = (char *)malloc(sizeof(char) * fullSize);
	coping = (char *)malloc(sizeof(char) * intermediateSize);
	int i;
	clock_t start, end;
	double timeTakenInSec;
	pthread_t t[2];

	//prepares the source string with 100MB of data
	for(i = 0; i < fullSize ; i++)
	{
		memcpy((mainBlk + i), "a", 1);
	}

	//copies the data from one place to the other
	start = clock();

	for(i=0; i<2;i++)
	{
		pthread_create(&t[i], NULL, &transfer, NULL);
	}

	pthread_join(t[0], NULL);
	pthread_join(t[1], NULL);

	end = clock();

	timeTakenInSec = (double)(end-start)/CLOCKS_PER_SEC;

	printf("latency = %g\n", (double)(timeTakenInSec* 1000)/memorySize);

	printf("throughput =%g MB/s\n ", (double)fullSize /(timeTakenInSec*1024*1024));

	free(mainBlk);
	free(coping);
}
