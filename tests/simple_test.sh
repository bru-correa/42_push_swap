#!/bin/bash

PS_ARG=$(seq 500 | shuf | paste -s -d ' ')
echo "List: $PS_ARG"
./push_swap $PS_ARG | wc -l
