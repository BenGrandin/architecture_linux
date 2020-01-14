#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	printf("genSensorData\n");

    char c;
    while(read(0, &c,1) == 1){
        printf("gen");
        write(1,&c,1);
    }

   return 0;
}