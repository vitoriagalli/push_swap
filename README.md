# push_swap

ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')"); ./push_swap $ARG | wc -l

 make fclean; mkdir -p .objs/stack ; make
