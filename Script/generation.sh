#!/bin/bash
if [ "$1" -eq "0" ]; then
  echo "No argument 1 supplied"
  errorFile="errors.txt"
else
  errorFile=$1
fi

if [ "$1" -eq "0" ]; then
  echo "No argument 2 supplied"
  logsFile="logs.txt"
else
  logsFile=$1
fi

echo "$logsFile"
echo "$errorFile"

./genTick 1000 | ./genSensorData 2>>errorFile >>logsFile
