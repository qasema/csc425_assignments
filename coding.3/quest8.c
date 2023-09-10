#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
  int pipefd[2];

  if (pipe(pipefd) == -1) {
     fprintf(stderr, "pipe failed\n");
     exit(1);
  }

  int rc_child1 = fork();
  if (rc_child1 == -1) {
    fprintf(stderr, "fork child 1 failed\n");
    exit(1);
  }

  if (rc_child1 == 0) {
    // First child
    close(pipefd[0]);
    dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to write end
    execlp("ls", "ls", NULL); // output of child 1 
  } else {
    int rc_child2 = fork();
    if (rc_child2 == -1) {
      fprintf(stderr, "fork child 2 failed \n");
      exit(1);
    }

    if (rc_child2 == 0) {
      // Second child
      close(pipefd[1]); 

      dup2(pipefd[0], STDIN_FILENO);
      fprintf(stderr, "the number of file in the directory( word count):  "); 
      execlp("wc", "wc", "-l", NULL); // output of child 2 using the output of child1 as an inpute 
    } else {
      close(pipefd[0]);
      close(pipefd[1]);
      int status;
      int rc_wait = waitpid(rc_child1,&status, 0);
      int rcc_wait = waitpid(rc_child2,&status, 0);
    }
  }

  return 0;
}
