#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <time.h>
#include <pthread.h>

#define MAX 40
#define CN 1000

int success;
int wait;

typedef struct __Queue {
	int front;
	int rear;
	int mono_inc;
	int remain;
	int item[MAX];
}Queue;

Queue q;

pthread_mutex_t mutex;
pthread_cond_t cond;

pthread_t producer;
pthread_t consumer[CN];

void *producer_func(void *data)
{
	pthread_mutex_lock(&mutex);
	printf("Producer Launch\n");
	for(int i=0;i<MAX;i++) 
		q.item[q.rear++] = q.mono_inc++;
	q.remain = MAX;
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&mutex);

	while(success != CN) {
		pthread_mutex_lock(&mutex);
		while(q.remain == MAX)
			pthread_cond_wait(&cond, &mutex);

		q.item[q.rear % MAX] = q.mono_inc++;
		q.rear++;
		q.remain++;
		printf("Increase %d\n", q.mono_inc-1);
		
		pthread_mutex_unlock(&mutex);
	}	
}

void *consumer_func(void *data)
{
	int get = -1;
	bool wait_cond = false;
retry:
	pthread_mutex_lock(&mutex);
	if(q.remain) {
		get = q.item[q.front % MAX];
		q.front++;
		q.remain--;
		success++;	
		printf("Consumer get [%d]\n", get);
		if(success == CN)
			pthread_cond_signal(&cond);
	} else {
		if(!wait_cond) {
			printf("Consumer wait...\n");
			pthread_cond_signal(&cond);
			wait_cond = true;
			wait++;
		}
	}
	pthread_mutex_unlock(&mutex);
	if(get == -1)
		goto retry;
}

int main()
{
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);	

	int producer_id;
	int consumer_id[CN];

	pthread_mutex_lock(&mutex);
	producer_id = pthread_create(&producer, NULL, producer_func, NULL);
	if(producer_id < 0) {
		perror("producer thread init fail\n");
		exit(-1);	
	}
	pthread_cond_wait(&cond, &mutex);
	pthread_mutex_unlock(&mutex);
	
	for(int i=0;i<CN;i++) {
		consumer_id[i] = pthread_create(&consumer[i], NULL, consumer_func, NULL);
		if(consumer_id[i] < 0) {
			perror("consumer thread init fail\n");
			exit(-1);	
		}
	}	
	pthread_join(producer, NULL);	
	for(int i=0;i<CN;i++) 
		pthread_join(consumer[i], NULL);	
	
	printf("Total Success : %d / Wait : %d\n", success, wait);

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);

	printf("End of program\n");

	return 0;
}

