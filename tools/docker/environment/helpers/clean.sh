#!/bin/bash

script_directory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

rm -rf ${script_directory}/*
rm -rf ${script_directory}/../bin/*.exe
rm -rf ${script_directory}/../bin/*.test
rm -rf ${script_directory}/../lib/*.so