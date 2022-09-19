#!/usr/bin/bash

clear

echo "----------CHECKOUT----------"

echo "----------CONFIG----------"

cd build
cmake ..

echo "----------CONFIG----------"


echo "----------BUILD----------"

cmake --build .

echo "----------BUILD----------"


echo "----------RUN----------"

cd src
./ProjectName

echo "----------RUN----------"
