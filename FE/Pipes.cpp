/*
 testPipes.c
 
 Demonstrates a parent talking to a child,
 and the child listening.
 
 */

#include <unistd.h>	// close, for, pipe, read, write
#include <stdio.h>	// printf, fprintf, stderr
#include <stdlib.h>  	// exit

const int MAXLINE = 80;

int main() {
    
    int fd[2];
    pid_t pid;
    char line[MAXLINE];
    
    // After a successful pipe, fd[0] is the end to read from
    // and fd[1] is the end to write to.
    if (pipe (fd) < 0) {
        fprintf(stderr, "Failed to create pipe\n");
        exit(1);
    }
    
    // Create a child process.
    if ((pid = fork()) < 0) {
        fprintf(stderr, "Failed to fork\n");
        exit(1);
    }
    else if (pid > 0) {
        // parent
        close(fd[0]);
        printf("Parent: %d about to send message\n", getpid());
        write(fd[1], "Listen to me!\n", 15);
        //    wait(NULL);  // Waiting for child to finish.
    }
    else {
        // child
        close(fd[1]);
        read(fd[0], line, MAXLINE);  // listen to your parent.
        printf("Child: %d receiving message from parent: %d\n",
               getpid(), getppid());
        printf("%s", line);  // This is just to show that we heard them.
    }
}
