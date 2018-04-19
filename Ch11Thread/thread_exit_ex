#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

void *thr_fun1(void *arg){
	printf("thread1 is returning\n");
	return((void *)1);
}

void *thr_fun2(void *arg){
	printf("thread2 is exiting\n");
	pthread_exit((void *)2);
}
int main(void){
	int err;
	pthread_t tid1,tid2;
	void *tret;

	err = pthread_create(&tid1,NULL,thr_fun1,NULL);
	if (err!=0){
		printf("can't create thread1\n");
		exit(-1);
	}
	err = pthread_create(&tid2,NULL,thr_fun2,NULL);
	if (err!=0){
		printf("can't create thread2\n");
		exit(-1);
	}
	err = pthread_join(tid1,&tret);
	if (err!=0){
		printf("can't join thread1\n");
		exit(-1);
	}
	printf("thread1 exit code: %ld\n",(long)tret);
	err = pthread_join(tid2,&tret);
	if (err!=0){
		printf("can't join thread2\n");
		exit(-1);
	}
	printf("thread2 exit code: %ld\n",(long)tret);
	exit(0);
}
