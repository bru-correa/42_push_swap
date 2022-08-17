#!/bin/bash

# ********** Constants ********** #

# PS = Push Swap
PS_DIR=./
PS_PROGRAM=$PROJECT_DIR/push_swap
PS_CHECKER=$PROJECT_DIR/checker

COLOR_RED="\033[31;1m"
COLOR_GREEN="\033[32;1m"
COLOR_YELLOW="\033[33;1m"
COLOR_NORMAL="\033[0m"

# ********** General Utils Functions ********** #

print_red() {
  printf "$COLOR_RED$1$COLOR_NORMAL\n"
}

print_green() {
  printf "$COLOR_GREEN$1$COLOR_NORMAL\n"
}

print_yellow() {
  printf "$COLOR_YELLOW$1$COLOR_NORMAL\n"
}

# Print a line with 80 '-' characters followed by a newline character
print_div() {
  echo -n "--------------------------------------------------"
  echo "------------------------------"
}

# Remove all previous log files, if they exist
clean_log_files() {
  rm -f ./logs/*
}


# ********** Testing Functions ********** #

# Check for norminette errors
check_norm() {
  printf "Checking Norminette: "
  local _output
  _output=`norminette $PS_DIR`
  if [[ $? -eq 0 ]]; then
    print_green "[OK]"
  else
    print_red "[KO]"
    local _output_error
    _output_error=`printf "$_output" | grep Error`
    printf "$_output_error\n"
  fi
  print_div
}

# Check if the push swap file exists
check_push_swap() {
  printf "Checking if can execute push_swap: "
  if [[ -x $PS_PROGRAM ]]; then
    print_green "[OK]"
  else
    print_red "[KO]"
    exit 1
  fi
  print_div
}

# TODO: Put the output in a log file
# Check if wrong inputs return an error message
# First parameter: the test name
# Second parameter: push_swap args
check_invalid_input() {
  local _test_name="$1"
  local _args="$2"

  local _output
  _output =`$PS_PROGRAM $1`
  if [[ "$_output" == "Error\n" ]]; then
    print_green "[OK]"
  else
    print_red "[KO]"
    `printf "Expected:\nError\n" > ./logs/$_test_name`
    `printf "Output:\n$_output" >> ./logs/$_test_name`
  fi
}

# TODO: Check if push_swap printed something
# Check if already sorted lists don't crash the program or return an instruction
check_sorted_lists() {
  local _args="$1"

  local _output
  _output = $($PS_PROGRAM | wc -l)
  if [[ $_output -eq 0 ]]; then
    print_green "[OK]"
  else
    print_red "[KO]"
  fi
}

# TODO: Download the checker program
# Test with the checker if the printed instructions sorts the list
check_unsorted_lists() {
  local _args="$1"

  local _output
  output = $($_output | wc -l)
}

# TODO: Check push_swap optimization. See https://github.com/laisarena/push_swap_tester. Rate with 5*


# ********** Main Function ********** #

main () {
  clean_log_files
  check_norm
  check_push_swap
  check_invalid_input
}

main
