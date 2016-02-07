/*
 * memT1.c
// *
// *  Created on: Feb 6, 2016
// *      Author: pavan
// */

#include<stdio.h>
#include<string.h>
#include<time.h>

const int memorySize = 239075328;

void main(void *argv)
{
	char *mainBlk = (char *)malloc(sizeof(char) * 1024 * 1024 * 228);
	char *coping = (char *)malloc(sizeof(char));
	int i;
	clock_t start, end;
	double timeTakenInSec;

	//prepares the source string with 100MB of data
	for(i = 0; i < memorySize ; i++)
	{
		memcpy((mainBlk + i), "a", 1);
	}

	//copies the data from one place to the other
	start = clock();

	for(i = 0; i < memorySize; i++)
	{
		memcpy(coping, (mainBlk + i), 1);
	}

	end = clock();

	timeTakenInSec = (double)(end-start)/CLOCKS_PER_SEC;

	printf("latency = %g ms\n", (double)(timeTakenInSec * 1000)/memorySize);

	printf("throughput =%g MB/s\n ", (double)memorySize/(timeTakenInSec*1024*1024));

	free(mainBlk);
	free(coping);
}
