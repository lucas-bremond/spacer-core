#!/bin/bash

script_directory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

if [[ -z ${1} ]]; then
    gdb --args ${script_directory}/../bin/*.test
else
    gdb --args ${script_directory}/../bin/*.test --gtest_filter=${1}
fi