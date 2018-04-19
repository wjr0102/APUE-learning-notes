#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void cleanup(void *arg);
void *thr_fn1(void *arg);
void *thr_fn2(void *arg);


int main(void){
	int err;
	pthread_t tid1,tid2;
	void *tret;

	err = pthread_create(&tid1,NULL,thr_fn1,(void *)1);
	if (err!=0){
		printf("can't create thread 1\n");
		exit(-1);
	}

	err = pthread_create(&tid2,NULL,thr_fn2,(void *)2);
	if (err!=0){
		printf("can't create thread 2\n");
		exit(-1);
	}

	err = pthread_join(tid1,&tret);
	if (err!=0){
		printf("can't join thread 1\n");
		exit(-1);
	}
	printf("thread 1 exit code: %ld\n",(long)tret);
	err = pthread_join(tid2,&tret);
	if (err!=0){
		printf("can't join thread 2\n");
		exit(-1);
	}
	printf("thread 2 exit code: %ld\n",(long)tret);
	exit(0);
}

void cleanup(void *arg){
	printf("cleandup: %s\n", (char *) arg);
}

void *thr_fn1(void *arg){
	printf("thread 1 start\n");
	pthread_cleanup_push(cleanup, "thread 1 first handler");
	pthread_cleanup_push(cleanup, "thread 1 second handler");
	printf("thread 1 push complete\n");
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(1);
	if (arg)
			return ((void *)1);
	return ((void *)1);
}

void *thr_fn2(void *arg){
	printf("thread 2 start\n");
	pthread_cleanup_push(cleanup, "thread 2 first handler");
	pthread_cleanup_push(cleanup, "thread 2 second handler");
	printf("thread 2 push complete\n");
	if (arg)
			pthread_exit((void *)2);
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
	pthread_exit((void *)2);

}
