#include <stdio.h>
 
int mayuscula(FILE *);
 
int main(int argc,char *argv[])
{
    FILE *fp;
    int estado;
 
    if (argc == 1)
    {
        printf("Faltan argumentos:");
        return 0;
    }
    if (argc > 1)
    {
        fp = fopen(argv[1],"r+");
        estado = mayuscula(fp);
        if (estado == 0)
        {
            printf("Minusculas modificadas \n");
            return 0;
        }
        if (estado == -1)
        {
            printf("error");
            return 0;
        } 
   }
}
 
int mayuscula(FILE *fp)
{
    char character;
    if (fp == NULL)
    {
        perror("no se puede abrir el archivo");
        return -1;
    }
    else
    {
        while (character != EOF)
        {
            character = fgetc(fp);
            //Revisamos que el caracter sea una minuscula
            if ((character >= 'a') && (character <= 'z'))
            {
                //En la tabla ASCII las mayusculas y minusculas estan separadas 32 caracteres asi que disminuimos el valor en 32 para conseguir la mayuscula de esa letra
                character = character - 32;
                fseek(fp,-1,SEEK_CUR);
                fputc(character,fp);
            }    
        }
        return 0;
    }
}