#!/bin/bash

PS_ARG=$(seq 10 | shuf | paste -s -d ' ')
./push_swap $PS_ARG
