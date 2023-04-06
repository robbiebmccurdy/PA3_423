#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int *nums;
int size;
double avg = 0.0;
int min = 0;
int max = 0;
void *calcAvg(void *param);
void *calcMin(void *param);
void *calcMax(void *param);

int main (int argc, char **argv)
{
	//error checking
	if(argc < 2) {
		fprintf(stderr, "usage: %s <integer value>\n", argv[0]);
		return -1;
	}
	int i;

	--argc;
	++argv;
	
	//allocating memory for the array
	nums = calloc(argc, sizeof(int));

	for(i = 0; i < argc; i++) {
		nums[i] = atoi(argv[i]);
		size++;
	}

	//establish threads
	pthread_t avgT;
	pthread_t minT;
	pthread_t maxT;

	//create threads
	pthread_create(&avgT, NULL, calcAvg, nums);
	pthread_create(&minT, NULL, calcMin, nums);
	pthread_create(&maxT, NULL, calcMax, nums);

	//wait & join
	pthread_join(avgT, NULL);
	pthread_join(minT, NULL);
	pthread_join(maxT, NULL);

	//casting avg to int: 
	int newAvg = (int) avg;	
	
	//printing
	printf("\nAverage: %d \n", newAvg);
	printf("\nMinimum: %d \n", min);
	printf("\nMaximum: %d \n", max);
}

void *calcAvg(void *param)
{

	int sum = 0;
	int i = 0;
	int *nums;
	
	nums = param;

	for(i = 0; i < size; i++)
		sum += nums[i];
	avg = sum / (double) size;
	
	return (void *) 0;
}

void *calcMin(void *param)
{

	int i = 0;
	int *nums;
	nums = param;
	min = nums[0];

	for(i = 0; i < size; i++){
		if(nums[i] < min) {
			min = nums[i];
		}
	}

	return (void *) 0;
}

void *calcMax(void *param)
{

	int i = 0;
	int *nums;
	nums = param;
	max = nums[0];

	for(i = 0; i < size; i++){
		if(nums[i] > max)
			max = nums[i];
	}

	return (void *) 0;
}