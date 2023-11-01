CC = gcc
CFLAGS = -Wall -Werror -Wextra -Wfloat-equal -Wconversion -std=c11 -pedantic -I.
TESTFlAGS = -lcheck -lsubunit -lrt -lpthread -lgcov
GCOVFLAGS = -fPIC -fprofile-arcs -ftest-coverage 
LDFLAGS = -lm
DEBUG = -g

project_name = s21_math
func_dir = function
test_dir = tests
dirs = $(func_dir) $(test_dir)
obj_list = $(patsubst %.c, %.o, $(wildcard $(addsuffix /*.c, $(dirs))))

.PHONY: all clean gcov_report
all: $(addsuffix .a, $(project_name))

test: $(addsuffix .a, $(project_name)) $(filter $(test_dir)/%.o, $(obj_list))
	$(CC) -o $@ $(wordlist 2, $(words $^), $^) -L. -l:$< $(TESTFlAGS) $(LDFLAGS)
	./$@

$(addsuffix .a, $(project_name)): $(filter $(func_dir)/%.o, $(obj_list))
	ar rc $@ $^

gcov_report: $(addsuffix .a, $(project_name)) $(filter $(test_dir)/%.o, $(obj_list)) test
	rm -rf $(addsuffix /*.gcda, $(test_dir)) $(addsuffix /*.gcno, $(test_dir))
	~/.local/bin/gcovr --exclude-branches-by-pattern * --html-nested --output gcovr-report/coverage.html
	xdg-open gcovr-report/coverage.html

%.o: %.c
	$(CC) $(GCOVFLAGS) $(CFLAGS) $(DEBUG) -c $^ -o $@

clang:
	clang-format -n $(addsuffix /*.c, $(test_dir)) $(addsuffix /*.c, $(func_dir))

deps:
	pip install gcovr

clean:
	@rm -rf *.a $(obj_list) $(addsuffix /*.gcda, $(dirs)) $(addsuffix /*.gcno, $(dirs)) test gcov_report
