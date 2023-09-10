#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
    int rc = fork();
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // This is the child process
        printf("hello\n");
    } else {
        // This is the parent process
	sleep(1);
        printf("goodbye\n");
    }
    return 0;
}
