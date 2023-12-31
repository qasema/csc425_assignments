#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    int x = 100;

    int rc = fork();

    if (rc < 0) {
        perror("fork failed");
        exit(1);
    }

    else if (rc == 0) {
        // This is the child process
        printf("Child process: x = %d\n", x);
        x = 10; // Modify x in the child process
        printf("Child process: updated x = %d\n", x);
    } else {
        // This is the parent process
       int rc_wait = wait(NULL);
        printf("Parent process: x = %d\n", x);
        x = 50; // Modify x in the parent process
        printf("Parent process: Modified x = %d\n", x);
    }

    return 0;
}

/*********************************************
   Name: Ala 
   Question 1: The variable X is updated by the parent and child, but given that they are two different processes, each process updates it independently they both refer to the original value of x not the updated value by the other process

*********************************************/
