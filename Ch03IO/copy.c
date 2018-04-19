#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define BUFFSIZE 4096

#define err_sys(info)                                                        \
        {                                                                        \
                fprintf(stderr, "%s:%s\n", info, strerror(errno));                \
                exit(EXIT_FAILURE);                                                \
        }

int main(void){
	int n;
	char buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE))>0){
		if (write(STDOUT_FILENO, buf, n)!=n)
				err_sys("write error");
	}

	if (n<0)
		err_sys("read_error");
	
	exit(0);
}
