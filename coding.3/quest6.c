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
        printf(" this is the child and my ID is child (PID %d)\n", getpid());

    } else { // This code will be executed by the parent process
	int status;
        int rc_wait = waitpid(rc,&status, 0);
        printf("this is the parent I was waiting for the child (PID %d)\n", rc);
	printf("Parent process (PID %d) is done\n", rc_wait);

    }
	
    return 0;
}
// the waitpid allow the parent to wait for a particular child to finish in case of multiple child processes
