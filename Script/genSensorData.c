#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void generateOkOutput(char* okOutput){
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

    sprintf(okOutput, " sensorId is:%d; sensorName is: '%s'; value is:%d minvalue is:%d; meanValue is:%d; maxValue is:%d; \n",
     sensorId, sensorName, value, minValue, meanValue, maxValue);
}


void generateErrorOutput(char* errorOutput){

    int sensorId = rand()%3;
    int errorCode = rand()%600; 

	char* errorDetails[] = {"You break everything", "RTFM !", "You shouldn't practice C, go for python noob."};
    char* errorDetail = errorDetails[rand()%3];

    sprintf(errorOutput, " sensorId is:%d; errorCode is: %d; errorDetails is: '%s'; \n",
     sensorId,errorCode,errorDetail);

}


int main(int argc, char* argv[]){
    srand(time(0));


	printf("genSensorData\n");

    char c;
    while(read(0, &c,1) == 1){

        if(c == 'K'){
			char okBuffer[256];
			generateOkOutput(okBuffer);
		    write(1, okBuffer, strlen(okBuffer) );
		}else if (c == 'E'){
			char errorBuffer[256];
    		generateErrorOutput(errorBuffer);
		    write(2, errorBuffer,strlen(errorBuffer) );
		}
		

    }


   return 0;
}