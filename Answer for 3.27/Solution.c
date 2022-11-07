#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    FILE* input;
    FILE* copy;
    char str[1000]={0};
    input = fopen("input.txt", "a+");
    copy = fopen("copy.txt", "w");
 
    if (input == NULL) {
        printf("file can't be opened \n");
    }
 
 
    fread(str, sizeof(char), 1000,input);



    int fd[2];
    if(pipe(fd) == -1)
        return 1;
    int pid = fork();

    if(pid == 0){
        
        str[strlen(str) - 1] = '\0';

        int n = strlen(str) + 1;
        write(fd[1], str, sizeof(char)*n);
        printf("child prcoess copied content from input.txt to pipe\n");
    

        char temp[1000]={0};

        
        read(fd[0],(void *) temp, sizeof(char)*n);
    
        fwrite(temp,sizeof(char),n,copy);
        printf("child process written the content from pipe to destination file copy.txt\n");
        
    }
    else{

        printf("Parent process waiting for child process to finish execution\n");
        wait(NULL);
    }

    fclose(input);
    fclose(copy);
}

