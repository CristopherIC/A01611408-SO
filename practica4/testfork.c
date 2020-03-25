#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    int pid = fork();

    if(pid==0){
        printf("Proceso Hijo\n");
    } else {
        printf("Proceso Padre\n");
    }
    
}