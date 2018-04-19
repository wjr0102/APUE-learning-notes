#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#define err_sys(info)                                                        \
        {                                                                        \
                fprintf(stderr, "%s:%s\n", info, strerror(errno));                \
                exit(EXIT_FAILURE);                                                \
		}
static void my_exit1(void);
static void my_exit2(void);

int main(void){
	if (atexit(my_exit2) !=0)
			err_sys("can't register my_exit2");
	
	if (atexit(my_exit1) !=0)
			err_sys("can't register my_exit1");

	if (atexit(my_exit1) !=0)
			err_sys("can't register my_exit1");

	printf("main is done\n");
	return(0);
}

static void my_exit1(void){
	printf("first exit handler\n");
}

static void my_exit2(void){
	printf("second exit handler\n");
}
