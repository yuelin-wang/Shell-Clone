# Shell Clone
A side program I wrote while working for FEAST program in the summer to get myself familiar with lower level C programming and the relationship between shell and OS (especially in the envrionment of the Linux kernel and GNU C Library).

## Content
A C program that simulates the command line interface. The C program handles the commands `cd` and `exit` itself, while calling shell to run the rest of commands.

## Build
First clone to your directory:
```git
git clone https://github.com/yuelin-wang/Shell-Clone.git
```
Then run the make file, while compiles the C code:
``` make
make 
```
Lastly run the compiled executable file:
``` shell
./mush
```

## Shell
The basic interface lookes like this:
``` shell
<user>:<current working directory>$ 
```
Similar to any shell, please type your command after `$`.  
To exit, type command `exit (<optional exit status, default 0>)` or EOF by ctrl + D.

## End Note
Have a nice day!