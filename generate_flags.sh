#!/bin/bash

echo "-Wall" >compile_flags.txt
echo "-Wextra" >>compile_flags.txt
echo "-Werror" >>compile_flags.txt

find . -name "*.h" -printf '%h\n' | sort -u | while read dir; do
	echo "-I$dir" >>compile_flags.txt
done
