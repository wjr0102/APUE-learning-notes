#include<stdio.h>
#include<unistd.h>

int main(){
	printf("Hello world.\nFrom:%d\n",getpid());
	return 0;
}
