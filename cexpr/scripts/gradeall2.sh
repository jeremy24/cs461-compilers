#!/bin/bash
#
# COSC 461 - Programming Assignment 3: Gradescript (Manual)
#
# Description:
#     Requires "./ref_cexpr", "./cexpr", and all input files that are in
#     "gradescript/input/". The script will loop through all files and pipe
#     them in to both the solution executable and your own executable. Then it
#     will run a diff on both programs' outputs. If the output matches, then
#     it will mark it as "PASSED". Otherwise, it will mark it as "FAILED".
#
#     If you want a version of this gradescript that doesn't rely on the
#     solution executable, then run "gradeall.sh".
#
# Synopsis:
#     ./gradeall2.sh
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

	./ref_cexpr < "$i" > "__output1.txt" 2> "__eoutput1.txt"
	if [[ -s "err.log" ]]; then
		printf "[${red}FAILED${normal}]\n"
		printf "[${red}FATAL${normal}] \"ref_cexpr\" failed to execute. Error log below:\n"
		cat "err.log"
		rm -f "err.log" "__output1.txt"
		exit 4
	fi
	rm -f "err.log"
	./cexpr < "$i" > "__output2.txt" 2> "__eoutput2.txt"
	diff "__output1.txt" "__output2.txt" 2> /dev/null > /dev/null
	if [[ $? -ne 0 ]]; then
		printf "[${red}FAILED${normal}]\n"
	else
		printf "[${green}PASSED${normal}]\n"
		let "correct++"
	fi
done

rm "__output1.txt" "__output2.txt" "__eoutput1.txt" "__eoutput2.txt"
printf "%s out of %s correct.\n" "$correct" "$num"
exit $correct
