#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argn, char **argv){
    char *fileName = argv[1];
    char buffer;
    int fd = open(fileName, O_RDONLY);
    if (fd < 0){
        printf("No se puede abrir\n");
        exit(1);
    }
    while (read(fd, &buffer, 1)){
        printf("%d ", buffer);
    }
    close(fd);
    exit(0);
}