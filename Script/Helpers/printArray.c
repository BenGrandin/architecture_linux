#include <stdio.h>

void printArray(int array[],int length){
    printf("printArray\n");
    int loop;
    printf("%d ",length);

    printf("[ ");
    for(loop = 0; loop < length; loop++){
         printf("%d ", array[loop]);
         if(loop != length){
            printf(", ");
         }
    }
    printf("]");

}


int main(){
    printf("main\n");

    int array[] = {1,2,3};
    int length = 3;

    printf("%d",length);

    printArray(array,length);

    return 0;
}

