#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argn, char **argv){
    char *filename = argv[1];
    char buffer;
    char espacio = 0;
    int fd = open(filename, O_RDONLY);
    if (fd < 0){
        printf("No se pudo abrir \n");
        exit(1);
    }
    unsigned int numChar = 0, numNewL = 0, numWord = 0;
    while(read(fd, &buffer, 1)) {
        numChar++;
        if (buffer == 10) numNewL++;
        if ((buffer == ' ' || buffer == '\n' ) && espacio == 0) {
            espacio = 1;
            numWord += 1;
        } else if (buffer != ' ' && buffer != '\n' && buffer != EOF) {
            espacio = 0;
        }
    }
    numWord += 1;
    printf(" %d  %d %d %s\n", numNewL, numWord, numChar, filename);
    close(fd);
    exit(0);

}