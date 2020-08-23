# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/21 15:47:34 by vkuikka           #+#    #+#              #
#    Updated: 2020/08/21 15:57:59 by vkuikka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Make sure all arrays have the same amount of numbers and that amount is in the first for loop
#	You can change the values in the two first arrays

TESTS=(  3	5	10	50	100	500)
AMOUNTS=(90	100	1	80	40	40)

RESULTS=(0 0 0 0 0 0)
HARDEST=(0 0 0 0 0 0)
AVERAGE=(0 0 0 0 0 0)

LEN=${#TESTS[@]}
LEN=$((LEN - 1))
for j in $(seq 0 $LEN)
do
	#for i in {1..${AMOUNTS[j]}}
	#for i in {1..50}
	for i in $(seq 1 ${AMOUNTS[j]})
	do
		ARG=`ruby -e "puts (1..${TESTS[j]}).to_a.shuffle.join(' ')"`
		MOVES=$(./push_swap $ARG | wc -l | tr -d "[:space:]")
		AVERAGE[j]=$((AVERAGE[j] + MOVES))
		if [ "$MOVES" -gt "${RESULTS[j]}" ];
		then
			RESULTS[j]="$MOVES"
			HARDEST[j]="$ARG"
		fi
		RES=$(./push_swap $ARG | ./checker $ARG)
		if [ "$RES" != "OK" ]
		then
			echo $RES
			echo $ARG
			exit 1
		fi
	done
	AVERAGE[j]=$((AVERAGE[j] / AMOUNTS[j]))
	echo ${TESTS[j]} numbers required ${RESULTS[j]} moves with average of ${AVERAGE[j]}
	if [ "$1" = "-h" ]
	then
		echo ${HARDEST[j]}
		echo ""
	fi
done

