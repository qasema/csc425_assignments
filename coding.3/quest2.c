#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int rc = fork();
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child: redirect standard output to a file
        close(STDOUT_FILENO);
        open("./ls_output.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);

        // now exec "ls"...
        char *myargs[2];
        myargs[0] = strdup("ls");    // program: ls (list directory contents)
        myargs[1] = NULL;            // mark end of array
        execvp(myargs[0], myargs);   // runs "ls"
    } else {
        // parent goes down this path (main)
        int rc_wait = wait(NULL);
    }
    return 0;
}
