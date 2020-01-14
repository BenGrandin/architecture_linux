#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    printf("coucou\n");
    printf("nb d'arg= %d \n", argc);
    for(int i = 0; i < argc; i++){
        printf("%s\n", argv[i]);
    }

    char c;
    while(read(0, &c,1) == 1){
        write(2,&c,1);
    }
    return 0;
}