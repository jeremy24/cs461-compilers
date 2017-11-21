#!/bin/bash
#
# COSC 461 - Programming Assignment 3: Checker Script (Manual)
#
# Description:
#     Checks if ./cexpr matches with ./ref_cexpr. In order to do the
#     comparison, both the ./cexpr and ./ref_cexpr executables must be in the
#     same directory as this shell script. Then run "./check2.sh" while it has
#     the "x" permission (chmod +x check.sh). It'll tell you if it does not
#     match the solution code and will pop up vimdiff to show you where.
#
# Synopsis:
#     ./check2.sh html_file
#
# Author:
#     Clara Van Nguyen
#

if [[ $# -ne 1 ]]; then
	printf "Usage: %s txt_file\n" "$0"
	exit -1
fi

./ref_cexpr < "$1" > "__output1.txt" 2> "__eoutput1.txt"
./cexpr < "$1" > "__output2.txt" 2> "__eoutput2.txt"

diff "__output1.txt" "__output2.txt" 2> /dev/null > /dev/null
if [[ $? -ne 0 ]]; then
	x='';
	while [[ "$x" -ne 'y' && "$x" -ne 'N' ]]; do
		printf "Does not match! Would you like to see a diff -y? [y/N]"
		read -n x
	done;

	if [[ "$x" -eq 'y' ]]; then
		#diff -y "__output1.txt" "__output2.txt" | less
		vimdiff "__output1.txt" "__output2.txt"
		#vimdiff '__eoutput2.txt' -c 'split __output2.txt' -c 'vsplit __output1.txt' -c 'wincmd j' -c 'vsplit __eoutput1.txt' -c '<C-W>1'
	fi
	

else
	printf "Matches!\n"
fi

rm -rf "__output1.txt" "__output2.txt" "__eoutput1.txt" "__eoutput2.txt"
