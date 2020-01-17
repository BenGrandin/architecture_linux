#!/bin/bash

if [ $USER == "jisseaudamien" ] || [ $USER == "grandinbenjamin" ] || [ $USER == "duhalgouetmelec" ]; then
  #Forcing the use of 3 parameters
  if [ "$#" -eq "0" ]; then
    echo "No argument supplied, need 3"
  elif [ "$#" -eq "1" ]; then
    echo "1 arguments supplied, need 3"
  elif [ "$#" -eq "2" ]; then
    echo "2 arguments supplied, need 3"
  else
    echo "alright"
    echo "$USER"

  #Dynamic creation of Directory and log and error files
    cd
    mkdir -p "$1"
    touch ./"$1"/"$2".txt
    touch ./"$1"/"$3".txt

    chmod +x ./Documents/architecture_linux/Script/genTick
    chmod +x ./Documents/architecture_linux/Script/genSensorData

    gcc ./Documents/architecture_linux/Script/genTick.c -o genTick
    gcc ./Documents/architecture_linux/Script/genSensorData.c -o genSensorData

  #writing in log and error files, >> write at the end of the files to keep previous logs
    ./genTick 100 | ./genSensorData >> ./"$1"/"$2".txt 2>> ./"$1"/"$3".txt
    # ./genTick 500 | ./genSensorData >> ./Users/$USER/Desktop/architecture_linux/Script/"$1"/"$2".txt 2>> ./Users/$USER/Desktop/architecture_linux/Script/"$1"/"$3".txt
    # ./genTick 100 | ./genSensorData 2>> ./"$1"/"$2".txt | stdbuf -oL cut -d';' -f2 > ./"$1"/"$3".txt
    # ./genTick 100 | ./genSensorData 2>> $3/$1 | stdbuf -oL cut -d'#' -f2 >> $3/$2
  fi

else
  echo "ACCESS DENIED"
fi