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
        printf("Child process (rc %d) running /bin/ls:\n", getpid());

	printf("Using execle\n");
	execl("/bin/ls", "ls", NULL);
	
	// these will not execute  because the child program has been replaced 
	printf("Using execl\n");
	execl("/bin/ls", "ls", NULL);
	
	printf("Using execlp\n");
	execlp("ls", "ls", NULL);

	printf("Using execv\n");
	char *argv[] = {"ls", NULL};
	execv("/bin/ls", argv);
	
	printf("Using execvpe\n");
	execvp("ls", argv);
	

    } else { // This code will be executed by the parent process
        printf("this is the parent\n");
    }

    return 0;
}
