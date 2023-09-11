#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    int rc = fork(); // Create a child process
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);

    }else if (rc == 0) { // This code will be executed by the child process
        printf(" this is the child \n");

    } else { // This code will be executed by the parent process
	int rc_wait = wait(NULL);
	printf("this is the parent I was waiting for the child :)\n");
    }

    return 0;
}
/*********************************************
   name: Ala 
   Question 5: Wait () returns the ID of the child when it finished executing. //If we attempt to use wait in the child process it will not work as we expect because the wait call is intended for the process to wait for a child forked from it. when I added the wait in the child it appeared like the parent executed first but the child was waiting for a process that did not exist.

*********************************************/
