#ARG="1 2 4 3 7 6 5"
ARG="1 4 7 48 49 0 57 69"
#ARG="`ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`"

./push_swap $ARG | ../checker $ARG
#./push_swap $ARG 