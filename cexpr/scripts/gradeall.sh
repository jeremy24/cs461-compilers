#!/bin/bash
#
# COSC 461 - Programming Assignment 3: Gradescript (Cached)
#
# Description:
#     Requires "./cexpr", all input files in "gradescript/input/", and all
#     cached output files in "gradescript/outputs/". The script will loop
#     through all files and pipe them in to your exectuable. Then it will run a
#     diff on both your program's output, and the cached output in the output
#     directory. If the output matches, then it will mark it as "PASSED".
#     Otherwise, it will mark it as "FAILED".
#     
#     If you want a version of this gradescript that runs both your solution
#     and the solution executable and checks outputs from that, then run
#     "gradeall2.sh"
#
# Synopsis:
#     ./gradeall.sh
#
# Author:
#     Clara Van Nguyen
#

# Set up our colours.
red=$(tput setaf 1)
green=$(tput setaf 2)
normal=$(tput sgr 0)

# Check if files exist
if [[ ! -f "cexpr" ]]; then
	printf "[${red}FATAL${normal}] Missing \"cexpr\".\n"
	exit 2
elif [[ ! -f "ref_cexpr" ]]; then
	printf "[${red}FATAL${normal}] Missing \"ref_cexpr\".\n"
	exit 3
fi

# Get number of gradescript cases.
num=0
for i in "gradescript/input/"*".txt"; do
	let "num++"
done

# Get number of digits
s=$(echo "$num" | grep -o "[0-9]" | grep -c "")

# Iterate through and compare.
correct=0
c=0
for i in "gradescript/input/"*".txt"; do
	fname=$(printf "%03d.txt" $c)
	let "c++"
	str=$(printf "(%*d/%*d) Checking \"%s\"..." $s $c $s $num $fname)
	printf "%-48s" "$str"

	./cexpr < "$i" > "__output.txt" 2> "__eoutput.txt"
	diff "__output.txt" "gradescript/output/$fname" 2> /dev/null > /dev/null
	if [[ $? -ne 0 ]]; then
		printf "[${red}FAILED${normal}]\n"
	else
		printf "[${green}PASSED${normal}]\n"
		let "correct++"
	fi
done

rm "__output.txt" "__eoutput.txt"
printf "%s out of %s correct.\n" "$correct" "$num"
exit $correct
