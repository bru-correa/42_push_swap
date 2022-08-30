#!/bin/bash

# ********** Constants ********** #

# PS = Push Swap prefix for avoiding conflict with environment variables
readonly PS_DIR=.
readonly PS_PROGRAM=$PS_DIR/push_swap
readonly PS_CHECKER=$PS_DIR/checker_linux

# HACK: Try solve this more elegantly
readonly PS_TEST_DIR=./tests

readonly PS_COLOR_RED="\033[31;1m"
readonly PS_COLOR_GREEN="\033[32;1m"
readonly PS_COLOR_YELLOW="\033[33;1m"
readonly PS_COLOR_NORMAL="\033[0m"

# ********** General Utils Functions ********** #

print_red() {
  printf "$PS_COLOR_RED$1$PS_COLOR_NORMAL\n"
}

print_green() {
  printf "$PS_COLOR_GREEN$1$PS_COLOR_NORMAL\n"
}

print_yellow() {
  printf "$PS_COLOR_YELLOW$1$PS_COLOR_NORMAL\n"
}

# Print a line with 80 '-' characters followed by a newline character
print_div() {
  echo -n "--------------------------------------------------"
  echo "------------------------------"
}

# Remove all previous log files, if they exist
clean_log_files() {
  rm -f $PS_TEST_DIR/logs/*.log
}

# NOTE: Maybe add space after the array parenthesis
# Generate a random list of non repeating integers
# First Parameter: range. Example: "0-5"
get_random_list() {
  local _range="$1"
  if [[ "${_range:0:1}" == "-" ]]; then
    local _min _max
    _min=$(echo $_range | perl -ne '/-(\w+)/ && print $1')
    _max=$(echo $_range | perl -ne '/-\w+-(\w+)/ && print $1')
    list=($(shuf -i 1-$_min | perl -pe 's/^/-/'))
    list+=($(shuf -i 0-$_max))
  else
    list=($(shuf -i $_range))
  fi
}

# NOTE: Maybe add space after the array parenthesis
# WARNING: Not being used at the moment
# Sort the list from 'list' and store it in 'sorted' global variable
sort_list() {
  IFS=$'\n' # Delimiter
  sorted=($(sort -n <<<"${list[*]}"))
  unset IFS # Reset IFS value to default
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
  printf "Checking push_swap exists: "
  if [[ -x $PS_PROGRAM ]]; then
    print_green "[OK]"
  else
    print_red "[KO]"
    exit 1
  fi
  print_div
}

# Check if wrong inputs return an error message
# First parameter: the test name
# Second parameter: push_swap args
check_invalid_input() {
  local _test_name="$1"
  local _args=($2)

  printf "$_test_name: "
  local _output
  _output=$($PS_PROGRAM ${_args[@]})
  local _first_line
  _first_line=$(echo "$_output" | head -1)
  if [[ "$_first_line" == "Error\n" ]]; then
    print_green "[OK]"
  else
    print_red "[KO]"
    printf "Expected Output:\nError\n" >> "$PS_TEST_DIR/logs/$_test_name.log"
    printf "Output:\n$_output" >> "$PS_TEST_DIR/logs/$_test_name.log"
  fi
}

# Check if already sorted lists don't crash the program or return an instruction
# First parameter: the test name
# Second parameter: push_swap args
check_sorted_lists() {
  local _test_name="$1"
  local _args=($2)

  printf "$_test_name: "
  local _output
  _output=`$PS_PROGRAM ${_args[@]}`
  if [[ -z "$_output" ]]; then
    print_green "[OK]"
  else
    print_red "[KO]"
    printf "Expected no output!\n" >> "$PS_TEST_DIR/logs/$_test_name.log"
    printf "Output:\n$_output" >> "$PS_TEST_DIR/logs/$_test_name.log"
  fi
}

# Test with the checker if the printed instructions sorts the list
# First parameter: the test name
# Second parameter: the range. Example: "0-5"
check_unsorted_lists() {
  local _test_name="$1"
  local _range="$2"

  printf "$_test_name: "
  get_random_list $_range # Store the list in 'list' variable
  local _output
  _output=$($PS_PROGRAM ${list[@]} | $PS_CHECKER ${list[@]} 2>&1)
  if [[ "$_output" == "OK\n" ]]; then
    print_green "[OK]"
  else
    print_red "[KO]"
    # WARNING: Debugging
    printf "The list:\n"
    printf '%s ' "${list[@]}"
    printf "\n"
  fi
}

# TODO: Check push_swap optimization. Rate with stars '*'
# See https://github.com/laisarena/push_swap_tester.


# ********** Main Function ********** #

main () {
  clean_log_files
  check_norm
  check_push_swap
  printf "Checking invalid inputs\n"
  check_invalid_input "alpha_chars" "a b c d e"
  check_invalid_input "num_and_alpha" "42 36 24 forty-two"
  check_invalid_input "max_int" "42 24 2147483648"
  check_invalid_input "min_int" "42 24 -2147483649"
  check_invalid_input "repeated" "4 8 15 16 23 42 8"
  print_div
  printf "Checking sorted lists\n"
  check_sorted_lists "no_args"
  check_sorted_lists "sorted_list0" "42"
  check_sorted_lists "sorted_list1" "24 42 36 48 70"
  check_sorted_lists "sorted_list2" "1 2"
  print_div
  printf "Checking unsorted lists\n"
  check_unsorted_lists "unsorted_0" "0-10"
  check_unsorted_lists "unsorted_1" "-5-5"
}

main

# TODO: Change all `` to subshells $()
# TODO: Create a function for each test section so you can skip them later
# TODO: Read the cli args and save the config in a file like tester.conf
# TODO: Check timeout in tests
# TODO: Check for memory leaks
