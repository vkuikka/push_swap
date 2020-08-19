
while true
do
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
	./push_swap $ARG | wc -l
	echo ""
done
