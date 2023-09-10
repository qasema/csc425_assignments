# csc425_assignments
/*********************************************

Your name: Ala Qasem
Question 1: The variable X is updated by the parent and child, but given that they are two different processes, each process updates it independently they both refer to the original value of x not the updated value by the other process
Question 2: Both child and parent can write on the same opened file in this case  Parent will write first and then wait for the child to finish and write on the same file before it closes the file. if you do cat text_file.txt you can see both text written by the parent and child.
Question 3: NA
Question 4: The many variants of exec() provide more flexibility. Different programs require different commands. Therefore, these variants provide more arguments such as paths or command arguments to accommodate different purposes.
Question 5: Wait () returns the ID of the child when it finished executing. //If we attempt to use wait in the child process it will not work as we expect because the wait call is intended for the process to wait for a child forked from it. when I added the wait in the child it appeared like the parent executed first but the child was waiting for a process that did not exist.
Question 6: The waitpid() call allows the parent to wait for a particular child to finish in case of multiple child processes.
Question 6: //When you use close(STDOUT_FILENO), you close the standard output file descriptor (STDOUT), which means that any subsequent attempts to write to STDOUT, such as using printf() in the example above, will have no effect, and the output will be discarded without being displayed.
Question 6: NA

*********************************************/
