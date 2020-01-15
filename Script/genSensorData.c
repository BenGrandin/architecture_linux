#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void generateRandomOutput(char* output);


int main(int argc, char* argv[]){
	printf("genSensorData\n");

    char c;
   /* while(read(0, &c,1) == 1){

        if(75 == c){
            write(1,&c,1);
        }

    }*/

    char buffer[256];
    generateRandomOutput(buffer);

    write(1,buffer,strlen(buffer));

   return 0;
}

void generateRandomOutput(char* output){
    srand(time(0));
    int sensorId = rand()%3;

    char* sensorNames[] = {"heatSensor", "moveSensor", "lightSensor"};
    char* sensorName = sensorNames[sensorId];

    int value = rand()%10;

    int a = rand()%100;
    int b = rand()%100; 
    int c = rand()%100;

    int minValue = (a < b) ? a : b;
    int meanValue = (a+b)/2;
    int maxValue = a < b ? b : a;

    sprintf(output, " sensorId is:%d; sensorName is:%s; minvalue is:%d; meanValue is:%d; maxValue is:%d; \n",
     sensorId, sensorName, minValue, meanValue, maxValue);
}