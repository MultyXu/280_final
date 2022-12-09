# Makefile
# Build rules for EECS 280 project 3

# Compiler
CXX ?= g++

# Compiler flags
CXXFLAGS ?= --std=c++11 -Wall -Werror -pedantic -g -Wno-sign-compare -Wno-comment -fsanitize=address -fsanitize=undefined

# CXXFLAGS ?= --std=c++11 #-fsanitize=address -fsanitize=undefined


# Run a regression test

char.exe: char.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@

poly.exe: polymorphism_non_ptr.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@

trim_lines.exe: trim_lines.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@

IntSet_test.exe: IntSet_test.cpp IntSet.h
	$(CXX) $(CXXFLAGS) $^ -o $@

UnsortedSet.exe: UnsortedSet.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

all: q1.exe q2.exe q3.exe q4.exe q5.exe q6.exe q7.exe q8.exe q9.exe q10.exe

q1.exe: q1.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@

q2.exe: q2.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@

q3.exe: q3.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@

q4.exe: q4.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@

q5.exe: q5.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@

q6.exe: q6.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@

q7.exe: q7.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@

q8.exe: q8.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@

q9.exe: q9.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@

mid1_review.exe: mid1_review.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@

q10.exe: q10.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@

main.exe: main.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@

.SUFFIXES:

.PHONY: clean

clean:
	rm -rvf *.out *.exe *.dSYM *.stackdump

# Style check
CPD ?= /usr/um/pmd-6.0.1/bin/run.sh cpd
OCLINT ?= /usr/um/oclint-0.13/bin/oclint
FILES := \
	q1.cpp \
	q2.cpp \
	q3.cpp \
	q4.cpp \
	q5.cpp \
	q6.cpp \
	q7.cpp \
	q8.cpp \
	q9.cpp \
	q10.cpp \
	IntSet.h \
	UnsortedSet.cpp \
	IntSet_test.cpp \



style :
	$(OCLINT) \
    -no-analytics \
    -rule=LongLine \
    -rule=HighNcssMethod \
    -rule=DeepNestedBlock \
    -rule=TooManyParameters \
    -rc=LONG_LINE=90 \
    -rc=NCSS_METHOD=40 \
    -rc=NESTED_BLOCK_DEPTH=4 \
    -rc=TOO_MANY_PARAMETERS=4 \
    -max-priority-1 0 \
    -max-priority-2 0 \
    -max-priority-3 0 \
    $(FILES) \
    -- -xc++ --std=c++11
	$(CPD) \
    --minimum-tokens 100 \
    --language cpp \
    --failOnViolation true \
    --files $(FILES)
	@echo "########################################"
	@echo "EECS 280 style checks PASS"
