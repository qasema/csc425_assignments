#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
  int fd = open("text_file.txt", O_CREAT | O_RDWR, 0666);
  if (fd == -1) {
    perror("open");
    exit(1);
  }

  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    // Child process
    printf("Child writing to file\n");
    write(fd, "this is written by child \n", 26);
  } else {
    // Parent process
    printf("Parent writing to file\n");
    write(fd, "this is written by parent \n", 26);

    wait(NULL); // Wait for the child to finish
  }

  // Read file contents
  close(fd);
  return 0;
}
