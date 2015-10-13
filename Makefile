
.PHONY : help compilation archive test 

SHELL := /bin/bash

##
## HELP
##

help : 
	@echo "Available:"
	@echo "- compilation ==> compilation (should not produce any error nor warning)"
	@echo "- test        ==> $(T_TEST__LIST) TV* TO*"
	@echo "  - t_sstring => test ./test_sstring"
	@echo "  - t_value   => test ./test_value"
	@echo "  - …"
	@echo "  - TV% (% is a number) => test on prog_v_%.pf  (for value's)"
	@echo "  - TO% (% is a number) => test on prog_o_%.pf  (for operator's)"
	@echo "- archive     => produce the tgz archive"


##
## MODULES
##

VALUES := block boolean double error int protected_label sstring

OPERATOR := addition division multiplication subtraction remainder nop label def less less_equal equal different or and not if if_else copy while pop print print_stack print_dictionary stop_trace start_trace

MODULE := basic_type chunk sstring linked_list_chunk value $(VALUES:%=value_%) read_chunk_io operator $(OPERATOR:%=operator_%) operator_creator_list dictionary interpreter


##
## HEADER FILES
##

HEADERS := $(MODULE:%=%.h) $(wildcard *macro*.h)


##
## PROGRAMS
##

TEST_C_PROGRAM := test_value test_value_int test_sstring test_linked_list_chunk test_dictionary 

MAIN_PROGRAM := ./pf


##
##  COMPILATION
##

## Create modules and test programs
compilation : $(MODULE:%=%.o) $(TEST_C_PROGRAM) $(MAIN_PROGRAM)

## Compiler

CC := gcc

## Compilation options

C_FLAG_OFF_UNUSED := -Wno-unused-but-set-parameter -Wno-unused-variable -Wno-unused-parameter -Wno-abi
# de-activate noisy warnings

CFLAGS := -std=c99 -Wall -Wextra -pedantic -ggdb -lm $(C_FLAG_OFF_UNUSED)

## compilation rules

./%.o : %.c $(HEADERS) 
	$(CC) -c $(CFLAGS) -o $@ $<

./% : %.c $(MODULE:%=%.o) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $(MODULE:%=%.o) $*.c


##
## TEST
##

T_TEST__LIST := t_sstring t_value  t_value_int t_linked_list_chunk t_dictionary
.PHONY : $(T_TEST__LIST)  $(PROGRAM_VALUE_NUMBERS:%=TV%) $(PROGRAM_OPERATOR_NUMBERS:%=TO%)

## Directory of for all data and results
DATA_DIR := DATA

## Directory of programs 
PROGRAM_DIR := $(DATA_DIR)/Programs

## Numbers of programs for test T%
PROGRAM_VALUE_NUMBERS := $(subst $(PROGRAM_DIR)/prog_v_,,$(subst .pf,,$(wildcard $(PROGRAM_DIR)/prog_v_*.pf)))
PROGRAM_OPERATOR_NUMBERS := $(subst $(PROGRAM_DIR)/prog_o_,,$(subst .pf,,$(wildcard $(PROGRAM_DIR)/prog_o_*.pf)))

## Directory to put generated results
RESULTS_DIR := $(DATA_DIR)/Results

## Directory of expected results_dir
RESULTS_EXPECTED_DIR := $(DATA_DIR)/Results_Expected

## Memory checker
VALGRIND := valgrind --leak-check=full --show-leak-kinds=all >/dev/null

## Valgrind returns when there is no leak
VALGRIND_INVALID_READ := "Invalid read"
VALGRIND_NO_MEMORY_LEAK_MESSAGE := "All heap blocks were freed -- no leaks are possible"

## To 1) run 2) compare with expected 3) test memorey leaks
define TEST_F
	$(1) > $(RESULTS_DIR)/$(2).output
	@if ! diff -Z $(RESULTS_DIR)/$(2).output $(RESULTS_EXPECTED_DIR)/$(2).output ; then echo "$(1): *** RÉSUTALT INCORRECT ***" ; false ; else echo "$(1): outputs match -- OK" ; fi
	@if ( ( ! ( 2>&1 $(VALGRIND) $(1) | tee $(RESULTS_DIR)/$(2).valgrind_output | grep $(VALGRIND_NO_MEMORY_LEAK_MESSAGE) ) ) || ( grep $(VALGRIND_INVALID_READ) $(RESULTS_DIR)/$(2).valgrind_output  ) ) ; then cat $(RESULTS_DIR)/$(2).valgrind_output ; fi
endef

## To 1) run 2) compare with expected 3) same with trace 4) test memorey leaks
define TEST_F_TRACE
	$(1) > $(RESULTS_DIR)/$(2).output
	@if ! diff -Z $(RESULTS_DIR)/$(2).output $(RESULTS_EXPECTED_DIR)/$(2).output ; then echo "$(1): *** RÉSUTALT INCORRECT ***" ; false ; else echo "$(1): outputs match -- OK" ; fi
	$(1) -t > $(RESULTS_DIR)/$(2).traced_output
	@if ! diff -Z $(RESULTS_DIR)/$(2).traced_output $(RESULTS_EXPECTED_DIR)/$(2).traced_output ; then echo "$(1): *** TRACE INCORRECT ***" ; false ; else echo "$(1): traced outputs match -- OK" ; fi
	@if ( ( ! ( 2>&1 $(VALGRIND) $(1) | tee $(RESULTS_DIR)/$(2).valgrind_output | grep $(VALGRIND_NO_MEMORY_LEAK_MESSAGE) ) ) || ( grep $(VALGRIND_INVALID_READ) $(RESULTS_DIR)/$(2).valgrind_output  ) ) ; then cat $(RESULTS_DIR)/$(2).valgrind_output ; fi
endef

## TEST sstring module
t_sstring : ./test_sstring
	$(call TEST_F,./test_sstring,test_sstring)

## TEST value_int module only
t_value_int : ./test_value_int
	$(call TEST_F,./test_value_int,test_value_int)

## TEST value modules except value_block
t_value : t_value_int ./test_value $(PROGRAM_VALUE_NUMBERS:%=TV%) 
	$(call TEST_F,./test_value,test_value)

## TEST linked_list_chunk
t_linked_list_chunk : ./test_linked_list_chunk
	$(call TEST_F,./test_linked_list_chunk,test_linked_list_chunk)

## TEST dictionary
t_dictionary : ./test_dictionary
	$(call TEST_F,./test_dictionary,test_dictionary)

## TEST values on programs, % should be a number, the higher the more complex 
TV% : $(MAIN_PROGRAM)
	$(call TEST_F_TRACE,$(MAIN_PROGRAM) $(PROGRAM_DIR)/prog_v_$*.pf,prog_v_$*)

## TEST operator on programs, % should be a number, the higher the more complex 
TO% : $(MAIN_PROGRAM)
	$(call TEST_F_TRACE,$(MAIN_PROGRAM) $(PROGRAM_DIR)/prog_o_$*.pf,prog_o_$*)

## TEST basic
test : t_sstring t_linked_list_chunk t_dictionary t_value $(PROGRAM_OPERATOR_NUMBERS:%=TO%)


##
## PRODUCE THE ARCHIVE (to send to JLD by email from a student account)
## 

ARCHIVE_NAME := PASD_mini-projet.tgz
ARCHIVE_FILES := Makefile *.c *.h compte-rendu.pdf

archive :
	@tar czf $(ARCHIVE_NAME) $(ARCHIVE_FILES)


