#include<stdio.h>
#include<sys/types.h> 
#include<unistd.h>
#include<stdlib.h>

int main ()
{
	printf("this is parent\n");
	pid_t child_pid ;
	child_pid =fork();
	if(child_pid == 0){
		printf("this is child 1\n");
		pid_t p = fork();
		if(p == 0){
			printf("this is child 2\n");
			pid_t p2 = fork();
			if(p2 == 0)
			{
				printf("this is child 3\n");
				pid_t p3 = fork();
				if (p3==0){
					printf("this is child 4");
				}
			}

		}


	}
}
//execlp("ls","ls",NULL);
