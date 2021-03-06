///*
// * memT1m.c
// *
// *  Created on: Feb 7, 2016
// *      Author: pavan
// */

#include<stdio.h>
#include<string.h>
#include<time.h>

const int memorySize = 100;

void main(void *argv)
{
	int intermediateSize = 1024*1024;
	int fullSize = memorySize * 1024 * 1024;
	char *mainBlk = (char *)malloc(sizeof(char) * fullSize);
	char *coping = (char *)malloc(sizeof(char) * intermediateSize);
	int i;
	clock_t start, end;
	double timeTakenInSec;

	//prepares the source string with 100MB of data
	for(i = 0; i < fullSize ; i++)
	{
		memcpy((mainBlk + i), "a", 1);
	}

	//copies the data from one place to the other
	start = clock();

	for(i = 0; i < fullSize; i +=intermediateSize)
	{
		memcpy(coping, (mainBlk + i), intermediateSize);
	}

	end = clock();

	timeTakenInSec = (double)(end-start)/CLOCKS_PER_SEC;

	printf("latency = %g\n", (double)(timeTakenInSec* 1000)/memorySize);

	printf("throughput =%g MB/s\n ", (double)fullSize /(timeTakenInSec*1024*1024));

	free(mainBlk);
	free(coping);
}
