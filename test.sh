#!/bin/sh

run_tester()
{
	./push_swap "$2" > ps
	./checker "$2" < ps > chk

	echo "-----------------------------"

	line=$(cat chk | grep "OK")
	if [ x"$line" = x ]
	then
		echo "NOT SORTED"
	else
		echo "SORTED"
	fi

	echo -n "solution: "
	cat ps | wc -l | tr -d "\n"

	echo "\tmax: " "$1"

}


### size 2 ###




max_instr=2
### size 3 ###
run_tester $max_instr "5 3 2"



### size 4 ###
#NOT WORKING

max_instr=12
### size 5 ###
# run_tester "5 4 1 2 3"	# NAO FUNCIONA
# run_tester "1 3 4 2 5"	# NAO FUNCIONA
run_tester $max_instr "3 4 1 5 2"





