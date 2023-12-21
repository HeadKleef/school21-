#!/bin/bash


RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' 

make test

./test
clang-format -i *.[ch]
if clang-format -n *.[ch]
then printf "${GREEN}CLANG TEST DONE${NC}\n"
else printf "${RED}CLANG TEST FAILED${NC}\n"
fi

if valgrind --track-origins=yes -q ./test >log.txt
then printf "${GREEN}VALGRIND TEST DONE${NC}\n\n"
else printf "${RED}VALGRIND TEST FAILED${NC}\n"
fi
rm log.txt
if cppcheck *.[ch]
then printf "${GREEN}CPPCHECK DONE${NC}\n"
else printf "${RED}CPPCHECK FAILED${NC}\n"
fi
make clean 