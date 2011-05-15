#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

volatile long long array[100];

void alert(int code, char* mes){
	printf("%s",mes);
	exit(code);
}
static void *counter(void *args){
	int id = (int)args;
	for(array[id]=0; array[id]<100000000; array[id]++);
	pthread_exit(NULL);
}
int main(){
	cpu_set_t cpu1, cpu2;
	CPU_ZERO(&cpu1);
	CPU_SET(0, &cpu1);
	CPU_ZERO(&cpu2);
	CPU_SET(1, &cpu2);
	pthread_t thread1;
	pthread_t thread2;

	if (pthread_create(&thread1, NULL, counter, (void*)0)) alert(11, "create thread 1 error");
	if (pthread_create(&thread2, NULL, counter, (void*)20)) alert(21, "create thread 2 error");
	if (pthread_setaffinity_np(thread1, sizeof(cpu_set_t), &cpu1)) alert(10, "set affinity thread 1 error");
	if (pthread_setaffinity_np(thread1, sizeof(cpu_set_t), &cpu2)) alert(20, "set affinity thread 2 error");
	if (pthread_join(thread1, NULL)) alert(12, "join thread 1 error");
	if (pthread_join(thread2, NULL)) alert(22, "join thread 2 error");

	return 0;
}
