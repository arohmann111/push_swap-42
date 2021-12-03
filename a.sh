#ARG="1 2 4 3 7 6 5"
ARG=""
#ARG="`ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`"

./push_swap $ARG | ./check/checker $ARG