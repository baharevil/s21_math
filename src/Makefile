CC = gcc
CFLAGS = -Wall -Werror -Wextra -Wfloat-equal -Wconversion -std=c11 -pedantic
TESTFlAGS = -lcheck -lsubunit -lrt -lpthread 
LDFLAGS = -lm
DEBUG = -g

program_name = s21_math
func_dir = function
obj_func_dir_list = $(patsubst %.c, %.o, $(wildcard $(addsuffix /*.c, $(func_dir))))
test_dir = tests
obj_test_dir_list = $(patsubst %.c, %.o, $(wildcard $(addsuffix /*.c, $(test_dir))))


.PHONY: all rebuild clean test
all: $(addsuffix .a, $(program_name))

test: s21_math.a $(obj_test_dir_list) 
	$(CC) -o $@ $(wordlist 2, $(words $^), $^) -L. -l$(basename $<) $(TESTFlAGS) $(LDFLAGS)
	clear
	./$@ -gcov

s21_math.a: $(obj_func_dir_list)
	ar rc $(addprefix lib, $@) $^

%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) -c $^ -o $@

clang:
#	clang-format -n $(addsuffix /*.c, $(test_dir)) $(addsuffix /*.c, $(func_dir))
	clang-format -i $(addsuffix /*.c, $(test_dir)) $(addsuffix /*.c, $(func_dir))

# gcov_report:

rebuild: clean all

clean:
	rm $(obj_func_dir_list) $(obj_test_dir_list) *.a test