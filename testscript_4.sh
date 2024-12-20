#!/bin/bash

ARG="1 2 3 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 2 4 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 3 2 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 3 4 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 4 2 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 4 3 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 1 3 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 1 4 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 3 1 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 3 4 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 4 1 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="2 4 3 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 1 2 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 1 4 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 2 1 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 2 4 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 4 1 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 4 2 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 1 2 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 1 3 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 2 1 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 2 3 1"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 3 1 2"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 3 2 1"; ./push_swap $ARG | ./checker_linux $ARG

echo "Counts:"

ARG="1 2 3 4"; ./push_swap $ARG | wc -l
ARG="1 2 4 3"; ./push_swap $ARG | wc -l
ARG="1 3 2 4"; ./push_swap $ARG | wc -l
ARG="1 3 4 2"; ./push_swap $ARG | wc -l
ARG="1 4 2 3"; ./push_swap $ARG | wc -l
ARG="1 4 3 2"; ./push_swap $ARG | wc -l
ARG="2 1 3 4"; ./push_swap $ARG | wc -l
ARG="2 1 4 3"; ./push_swap $ARG | wc -l
ARG="2 3 1 4"; ./push_swap $ARG | wc -l
ARG="2 3 4 1"; ./push_swap $ARG | wc -l
ARG="2 4 1 3"; ./push_swap $ARG | wc -l
ARG="2 4 3 1"; ./push_swap $ARG | wc -l
ARG="3 1 2 4"; ./push_swap $ARG | wc -l
ARG="3 1 4 2"; ./push_swap $ARG | wc -l
ARG="3 2 1 4"; ./push_swap $ARG | wc -l
ARG="3 2 4 1"; ./push_swap $ARG | wc -l
ARG="3 4 1 2"; ./push_swap $ARG | wc -l
ARG="3 4 2 1"; ./push_swap $ARG | wc -l
ARG="4 1 2 3"; ./push_swap $ARG | wc -l
ARG="4 1 3 2"; ./push_swap $ARG | wc -l
ARG="4 2 1 3"; ./push_swap $ARG | wc -l
ARG="4 2 3 1"; ./push_swap $ARG | wc -l
ARG="4 3 1 2"; ./push_swap $ARG | wc -l
ARG="4 3 2 1"; ./push_swap $ARG | wc -l

