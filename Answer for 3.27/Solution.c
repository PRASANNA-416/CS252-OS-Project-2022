#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]){

    FILE* input;
    FILE* copy;
    char str[1000];
    input = fopen("input.txt", "a+");
    copy = fopen("copy.txt", "w");
 
    if (input == NULL) {
        printf("file can't be opened \n");
    }
 
 
    fgets(str, 1000, input);



    int fd[2];
    if(pipe(fd) == -1)
        return 1;
    int pid = fork();

    if(pid == 0){
        
        close(fd[0]);
        str[strlen(str) - 1] = '\0';

        int n = strlen(str) + 1;
        write(fd[1], &n, sizeof(int));
        write(fd[1], str, sizeof(char)*n);

        close(fd[1]);
    }
    else{

        close(fd[1]);
        char str[1000];
        int n;

        read(fd[0], &n, sizeof(int));
        read(fd[0], str, sizeof(char)*n);

        fputs(str, copy);
        close(fd[0]);
        wait(NULL);
    }

    fclose(input);
    fclose(copy);
}
