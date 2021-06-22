#!/bin/bash

call_header()
{
	echo ""
	echo "-----------------------------------------"
	echo "             LIST OF SIZE $1             "
	echo "-----------------------------------------"
	echo ""
}

check()
{
	SIZE="$1"
	MAX_OP="$2"

	LIST=$(ruby -e "puts (1..$SIZE).to_a.shuffle.join(' ')")
	OP_SOLUTION=$(./push_swap $LIST)
	NUM_OP=$(./push_swap $LIST | wc -l)
	IS_SORTED=$(echo "$OP_SOLUTION" | ./checker $LIST | grep "OK")

	if [ "$?" -ne "0" ]
	then
		echo -e "NOT SORTED   \033[0;31m✘\033[0m"
	else
	{
		echo -n -e "SORTED"
		echo -n -e "\tsolution: " $NUM_OP
		echo -n -e "\tmax: " "$MAX_OP"
		if [ "$NUM_OP" -le "$MAX_OP" ]
		then
			echo -e "   \033[0;32m✔\033[0m"
		else
			echo -e "   \033[0;31m✘\033[0m"
		fi
	}
	fi
}

run()
{
	SIZE="$1"
	MAX_OP="$2"

	call_header "$SIZE"

	# for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50; do
	for i in 1 2 3 4 5 6 7 8 9 10; do
		check "$SIZE" "$MAX_OP"
	done
}

run "3" "3"
run "4" "12"
run "5" "12"
run "100" "700"
run "500" "5500"
