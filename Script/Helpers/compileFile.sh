#!/bin/bash
gcc genSensorData.c -o genSensorData
 ./genTick 500 | ./genSensorData