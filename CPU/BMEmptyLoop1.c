#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

double currentTime, numOfinstructions[60];
const int delay_in_seconds = 1;
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
	int c, d, k, c1, d1, k1;

	for(;;){
		for (c = 0; c < 10; c++) {
			for (d = 0; d < 10; d++) {
				for (k = 0; k < 10; k++) {
				}
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

	printf("calculating Empty Loop Performance\n");

	pthread_t tCounter;
	pthread_create(&tCounter, NULL, &threadproc, NULL);

	i = complexFunction();

	for(i = 0; i < 10; i++)
	{
		printf("GFLOPS = %g\t #ofIns = %g\n", (numOfinstructions[i] * 1000 * 3)/1000000000, numOfinstructions[i]);
	}
}
