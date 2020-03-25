#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    int pid = fork();

    if(pid==0){
        execlp("ls","ls","-a","/",(char *)NULL); //,(char *)NULL es opcional
    } else {
        printf("Proceso Padre\n");
    }
    
}