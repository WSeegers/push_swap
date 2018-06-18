#!/bin/bash

echo -e '\033[0mGetting an average in a range from 0 to 2'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

./tester res
rm res

echo -e '\033[0mGetting an average in a range from 0 to 3'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..3).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

./tester res
rm res

echo -e '\033[0mGetting an average in a range from 0 to 4'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

./tester res
rm res

echo -e '\033[0mGetting an average in a range from 0 to 5'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..5).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

./tester res
rm res

echo -e '\033[0mGetting an average in a range from 0 to 6'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..6).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

./tester res
rm res

echo -e '\033[0mGetting an average in a range from 0 to 7'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..7).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

./tester res
rm res

echo -e '\033[0mGetting an average in a range from 0 to 99'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

./tester res
rm res

echo -e '\033[0mGetting an average in a range from 0 to 499'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

./tester res
rm res
