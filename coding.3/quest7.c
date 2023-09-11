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
	close(STDOUT_FILENO);
	printf("Child process continues here \n");

    } else { // This code will be executed by the parent process
	printf("this is the parent I was waiting for the child :)\n");
        int rc_wait = wait(NULL);
	printf("parent is Done :)\n");
    }

    return 0;
}
/*********************************************
   name: Ala 
   Question 7: When you use close(STDOUT_FILENO), you close the standard output file descriptor (STDOUT), which means that any subsequent attempts to write to STDOUT, such as using printf() in the example above, will have no effect, and the output will be discarded without being displayed.

*********************************************/
