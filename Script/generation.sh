#!/bin/bash

#Forcing the use of 3 parameters
if [ "$#" -eq "0" ]; then
  echo "No argument supplied, need 3"
elif [ "$#" -eq "1" ]; then
   echo "1 arguments supplied, need 3"
elif [ "$#" -eq "2" ]; then
  echo "2 arguments supplied, need 3"
else
  echo "alright"

#Dynamic creation of Directory and log and error files
  mkdir -p "$1"
  touch ./"$1"/"$2".txt
  touch ./"$1"/"$3".txt

  chmod +x genTick
  chmod +x genSensorData

  gcc genTick.c -o genTick
  gcc genSensorData.c -o genSensorData

#writing in log and error files, >> write at the end of the files to keep previous logs
  ./genTick 500 | ./genSensorData >> ./"$1"/"$2".txt 2>> ./"$1"/"$3".txt
fi
