#!/bin/bash

call_header()
{
	echo ""
	echo "-----------------------------------------"
	echo "             LIST OF SIZE $1             "
	echo "-----------------------------------------"
	echo ""
}

run_tester()
{
	./push_swap "$2" > ps
	./checker "$2" < ps > chk
	line=$(cat chk | grep "OK")
	if [ x"$line" = x ]
	then
		echo -e "NOT SORTED   \033[0;31m✘\033[0m"
	else
	{
		echo -n -e "SORTED\t"
		head -n 1 chk | tr -d '\n'
		SOLUTION=$(cat ps | wc -l | tr -d "\n")
		echo -n -e "\tsolution: " $SOLUTION
		echo -n -e "\tmax: " "$1"
		if [ "$SOLUTION" -le "$1" ]
		then
			echo -e "   \033[0;32m✔\033[0m"
		else
			echo -e "   \033[0;31m✘\033[0m"
		fi
	}
	fi
}

run_input()
{
	while read -r arg
	do
		run_tester $1 "$arg"
	done <<< $(cat $2)
}

run_3()
{
	call_header "3"
	max_instr=2
	run_input $max_instr "./tests/size_3.txt"
}

run_5()
{
	call_header "5"
	max_instr=12
	run_input $max_instr "./tests/size_5.txt"
}

run_100()
{
	call_header "100"
	max_instr=700
	# max_instr=900
	# max_instr=1100
	# max_instr=1300
	# max_instr=1500
	run_input $max_instr "./tests/size_100.txt"
}

run_500()
{
	call_header "500"
	max_instr=5500
	# max_instr=7000
	# max_instr=8500
	# max_instr=10000
	# max_instr=11500
	run_input $max_instr "./tests/size_500.txt"
}


run_rand()
{
	call_header "ALL"
	max_instr=11500
	run_input $max_instr "./tests/rand.txt"
}

#############   TESTER   ############

if [ "$1" == "3" ]
then
	run_3
elif [ "$1" == "5" ]
then
	run_5
elif [ "$1" == "100" ]
then
	run_100
elif [ "$1" == "500" ]
then
	run_500
elif [ "$1" == "rand" ]
then
	run_rand
else
	run_3
	run_5
	run_100
	run_500
fi

rm -rf ps chk file


# ARG=""
# ./push_swap $ARG > ps ; ./checker $ARG < ps > res ; cat res
