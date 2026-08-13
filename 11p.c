#include<stdio.h>
#include<unistd.h>
void main () {
     int pid= fork();
     if(pid>0)
     fork();
     printf("%d\n",getpid());
    }
