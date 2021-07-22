#!/bin/bash

call_header()
{
	echo ""
	echo "-----------------------------------------"
	echo "             LIST OF SIZE $1             "
	echo "-----------------------------------------"
	echo ""
}

get_max_ops()
{
	L_SIZE=$1
	if ((0<=L_SIZE && L_SIZE<=3))
	then
		MAX_OP=3
	elif ((4<=L_SIZE && L_SIZE<=5))
	then
		MAX_OP=12
	elif ((5<=L_SIZE && L_SIZE<=100))
	then
		MAX_OP=700
	elif ((101<=L_SIZE && L_SIZE<=500))
	then
		MAX_OP=5500
	else
		MAX_OP=10000
	fi
}

check()
{
	SIZE=$1
	get_max_ops $SIZE
	LIST=$(ruby -e "puts (1..$SIZE).to_a.shuffle.join(' ')")
	NUM_OP=$(./push_swap $LIST | wc -l)
	IS_SORTED=$(./push_swap $LIST | ./checker $LIST | grep "OK")

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
			echo -e "   \033[0;32mOK ✔\033[0m"
		else
			echo -e "   \033[0;31mK0 ✘\033[0m"
		fi
	}
	fi
}

run()
{
	SIZE=$1
	call_header $SIZE
	for i in range {1..15}; do
		check $SIZE
	done
}

if [ ! -f "push_swap" ]; then
	echo -e "bin ./push_swap not found"
	echo -e "please run:\033[1m make\033[0m"
	exit
fi

if [ ! -f "checker" ]; then
	echo -e "bin ./checker not found"
	echo -e "please run:\033[1m make bonus\033[0m"
	exit
fi

if [ "$1" != "" ]; then
	run $1
else
	run 3
	run 5
	run 100
	run 500
fi
