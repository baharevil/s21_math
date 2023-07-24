CC = gcc
CFLAGS = -Wall -Werror -Wextra -Wfloat-equal -Wconversion -std=c11 -pedantic
TESTFlAGS = -lcheck -lsubunit -lrt -lpthread 
LDFLAGS = -lm
DEBUG = -g

project_name = s21_math
func_dir = function
test_dir = tests
dirs = $(func_dir) $(test_dir)
obj_list = $(patsubst %.c, %.o, $(wildcard $(addsuffix /*.c, $(dirs))))

.PHONY: all clean test s21_math.a gcov_report
# all: $(addsuffix .a, $(project_name))
all: test

# Функции используемые в целях
# https://rus-linux.net/nlib.php?name=/MyLDP/algol/gnu_make/gnu_make_3-79_russian_manual.html#SEC78
test: s21_math.a $(filter $(test_dir)/%.o, $(obj_list)) 
	$(CC) -o $@ $(wordlist 2, $(words $^), $^) -L. -l$(basename $<) $(TESTFlAGS) $(LDFLAGS)
	clear
	./$@ -gcov

s21_math.a: $(filter $(func_dir)/%.o, $(obj_list))
	ar rc $(addprefix lib, $@) $^

%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) -c $^ -o $@

# gcov_report:

clang:
#	clang-format -n $(addsuffix /*.c, $(test_dir)) $(addsuffix /*.c, $(func_dir))
	clang-format -i $(addsuffix /*.c, $(test_dir)) $(addsuffix /*.c, $(func_dir))

clean:
	rm $(obj_list) *.a test