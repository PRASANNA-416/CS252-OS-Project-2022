# Q 3.27 Solution (Unix Pipes)

Note: All the information written below is specific to Ubuntu operating system


## Requirements
Ubuntu operating system and GCC compiler to compile the C code.

[Steps to install GCC compiler on Ubuntu](https://linuxize.com/post/how-to-install-gcc-compiler-on-ubuntu-18-04/#installing-gcc-on-ubuntu)

## Steps to run the programs

### Solution.c
 - Open the terminal and navigate to the directory where the file **Solution.c** is present
 - Write some text int the file "input.txt"
 - Also create destination file with name "copy.txt"
-  gcc Solution.c
- ./a.out


## Implementation
- Made two files "input.txt" and destination file "copy.txt"
- Created a pipe (fd[0] -> for reading from the pipe. fd[1] -> for writing into the pipe).
- Invoked the fork sys call.
- Using write() sys call the child process pushed the content into pipe from the input.txt file.
- And using the read() sys call, child process read the content from the pipe to the output destination file.


## About Unix Pipes
-Pipe is one-way communication only i.e we can use a pipe such that One process write to the pipe, and the other process reads from the pipe. It opens a pipe, which is an area of main memory that is treated as a "virtual file".

-The pipe can be used by the creating process, as well as all its child processes, for reading and writing. One process can write to this "virtual file" or pipe and another related process can read from it.

![App Screenshot](https://github.com/PRASANNA-416/CS252-OS-Project-2022/blob/main/Answer%20for%203.27/pipe1.jpg)

## About write() and read() to pipe sys call
int pipe(int fds[2]);

Parameters :
fd[0] will be the fd(file descriptor) for the 
read end of pipe.
fd[1] will be the fd for the write end of pipe.
Returns : 0 on Success.
-1 on error.

- write(file descriptor to pipe, pointer from where to copy, size of memory)
- read(file descriptor to pipe, pointer to where to write , size of memory)

## Parent and child sharing a pipe

When we use fork in any process, file descriptors remain open across child process and also parent process. If we call fork after creating a pipe, then the parent and child can communicate via the pipe

![App Screenshot](https://github.com/PRASANNA-416/CS252-OS-Project-2022/blob/main/Answer%20for%203.27/pipe2.jpg)

