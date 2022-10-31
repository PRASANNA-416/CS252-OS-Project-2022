#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>

#include <sys/wait.h>

int main()
{
char c,num[10];
int n,len,i;
while(1)
 {
 printf("\nWhat is your number");
 gets(num);//Read input from console
 if(strcmp(num,"q")==0)// Quit if input is q
 exit(0);
 n=atoi(num);// String to number conversion
 if(n>2)// Wrong input checking
  {
        collatz(n);// Function calling
  }
 else
  {
        printf("enter valid input...\n");
  }

 }
return 0;

}

int collatz(int i)// Called Function
 {

  pid_t child_pid, wpid;

  int status = 0;

        if ((child_pid = fork()) == 0)// Child process creation

   {

    while(i != 1){

        printf("%d\t", i);

        if(i%2 == 0){// If n is even

            i /= 2;

           }

        else{// if n is odd

          i = 3*i + 1;

         }

       }

   printf("1\n");
   exit(1);

   }
 while ((wpid = wait(&status)) > 0)

   {

   printf("Child process exited\n");

   }

return;

}
