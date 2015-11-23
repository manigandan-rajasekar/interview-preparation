#!/bin/bash
echo "Input"
cat grid_walking.input.1
g++ grid_walking.cpp -o grid_walking
cat grid_walking.input.1 | ./grid_walking > grid_walking.output.1
echo "Output"
cat grid_walking.output.1 

