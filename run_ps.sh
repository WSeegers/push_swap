#!/bin/bash

./push_swap `ruby -e "puts (1..$@).to_a.shuffle.join(' ')"`
