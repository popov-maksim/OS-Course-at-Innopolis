#!/bin/bash

for i in `seq 1 500`;
do
   ./ex2.sh &
   ./ex2.sh
done
