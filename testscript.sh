#!/bin/bash

# Couleurs
RED="\033[0;31m"
GREEN="\033[0;32m"
NC="\033[0m" # Pas de couleur



# Fonction pour exécuter un test
test_push_swap() {
    local input=$1
    local is_valid_test=$2
	local is_complex=$3
    local result
	expected_error=$(printf "Error\n")

    result=$(./push_swap $input)
    err=$(./push_swap $input 2>&1)

    if [[ "$is_valid_test" == "v" && "$err" != "$expected_error" ]]; then
        printf "${GREEN}Test valide réussi pour l'entrée : $input${NC}"
    elif [[ "$is_valid_test" == "iv" && "$err" == "$expected_error" ]]; then
        printf "${GREEN}Test invalide réussi (erreur attendue) pour l'entrée : $input${NC}"
    else
        printf "${RED}Test échoué pour l'entrée : $input${NC}"
    fi

	if [[ "$is_complex" != "t" ]]; then
        echo "Sortie obtenue: $result"
	fi
    echo "----------------------------------------"
}



# Tests valides
echo ""
echo "==================================="
echo "Tests Valides"
echo "==================================="
test_push_swap "1 3 5 +9 20 -4 50 60 04 08" "v"
test_push_swap "3 4 6 8 9 74 -56 +495" "v"
test_push_swap "2147483647 2 4 7" "v"
test_push_swap "-000042" "v"
test_push_swap "-0000" "v"
test_push_swap "-0000 1" "v"
test_push_swap "+00002" "v"
test_push_swap "+2 -00001" "v"
test_push_swap "99 -2147483648 23 545" "v"
test_push_swap "2147483647 843 56544 24394" "v"
test_push_swap "$(seq 79 100)" "v" # Test avec une séquence de 1 à 100
test_push_swap "$(seq -100 -95)" "v" # Test avec une séquence de -100 à 100

test_push_swap "0" "v"
test_push_swap "+0" "v"
test_push_swap "-0" "v"
test_push_swap "0000000000000000" "v"
test_push_swap "+0000000000000000" "v"
test_push_swap "-0000000000000000" "v"

test_push_swap "00123" "v"
test_push_swap "+00123" "v"
test_push_swap "-00123" "v"
test_push_swap "002147483647" "v"
test_push_swap "+002147483647" "v"
test_push_swap "-002147483647" "v"
test_push_swap "-002147483648" "v"

# Tests invalides
echo ""
echo "==================================="
echo "Tests Invalides"
echo "==================================="
test_push_swap "1 3 dog 35 80 -3" "iv"
test_push_swap "a" "iv"
test_push_swap "1 2 3 5 67b778 947" "iv"
test_push_swap " 12 4 6 8 54fhd 4354" "iv"
test_push_swap "1 --    45 32" "iv"
test_push_swap "1 3 58 9 3" "iv"
test_push_swap "3 03" "iv"
test_push_swap " 49 128     50 38   49" "iv"
test_push_swap "54867543867438 3" "iv"
test_push_swap "-2147483647765 4 5" "iv"
test_push_swap "214748364748385 28 47 29" "iv"
test_push_swap "1 2 4 3 76 90 348 05 00-4" "iv"
test_push_swap "1 2 3 4 5 6 7 8 9 10 1" "iv"  # Test avec un doublon
test_push_swap "2147483647 2147483648" "iv"  # Test avec un nombre supérieur à INT_MAX
test_push_swap "-2147483648 -2147483649" "iv"  # Test avec un nombre inférieur à INT_MIN
test_push_swap "00000000+3" "iv"
test_push_swap "00000000-3" "iv"
test_push_swap "000000003+" "iv"
test_push_swap "000000003," "iv"
test_push_swap "1 000003-2" "iv"
test_push_swap "+0000000-3" "iv"
test_push_swap "+3-3" "iv"
test_push_swap "-100-1" "iv"
test_push_swap "-42+42" "iv"
test_push_swap "--42" "iv"
test_push_swap "0-42" "iv"
test_push_swap "0--42" "iv"
test_push_swap "0+42" "iv"
test_push_swap "0++42" "iv"
test_push_swap "-+42" "iv"
test_push_swap "+-42" "iv"
test_push_swap "-42 +00000-1" "iv"
test_push_swap "1 2 18446744073709551615" "iv"
test_push_swap "1 2 18446744073709551622" "iv"
test_push_swap "1 2 9223372036854775807" "iv"
test_push_swap "1 2 9223372036854775822" "iv"

test_push_swap "500000000000000000000" "iv"
test_push_swap "+500000000000000000000" "iv"
test_push_swap "-500000000000000000000" "iv"
test_push_swap "002147483648" "iv"
test_push_swap "+002147483648" "iv"

test_push_swap "aaa" "iv"
test_push_swap "+aaa" "iv"
test_push_swap "-aaa" "iv"
test_push_swap "0aaa" "iv"
test_push_swap "+0aaa" "iv"
test_push_swap "-0aaa" "iv"
test_push_swap "00123aaa" "iv"
test_push_swap "+00123aaa" "iv"
test_push_swap "-00123aaa" "iv"


