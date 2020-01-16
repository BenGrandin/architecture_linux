#!/bin/bash
gcc ../genSensorData.c -o genSensorData
gcc ../genTick.c -o genTick
 ./genTick 500 | ./genSensorData