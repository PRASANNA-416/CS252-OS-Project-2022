#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    if(n > 0){
        int id = fork();
        if(id == 0){
            printf("Child process is printing = \t");
            int i = n;
            while(i != 1){
                printf("%d\t",i);
                if(i %2 == 0)
                    i = i/2;
                else
                    i = 3*i + 1;
            }
        }
        else{
            printf("Parent process waiting for child to finish...\n");
            wait(NULL);
        }
        if(id == 0)
            printf("1\n");
    }
}
