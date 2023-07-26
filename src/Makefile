CC = gcc
CFLAGS = -Wall -Werror -Wextra -Wfloat-equal -Wconversion -std=c11 -pedantic -I.
TESTFlAGS = -lcheck -lsubunit -lrt -lpthread -lgcov
LDFLAGS = -lm
DEBUG = -g

project_name = test
func_dir = function
test_dir = tests
dirs = $(func_dir) $(test_dir)
obj_list = $(patsubst %.c, %.o, $(wildcard $(addsuffix /*.c, $(dirs))))

.PHONY: all clean gcov_report
all: $(project_name)

$(project_name): s21_math.a $(filter $(test_dir)/%.o, $(obj_list))
ifeq ($(test_dir), tests)
	$(CC) -o $@ $(wordlist 2, $(words $^), $^) -L. -l:$< $(TESTFlAGS) $(LDFLAGS)
	clear
	./$@
else
	$(CC) -o $@ $(wordlist 2, $(words $^), $^) -L. -l:$< $(LDFLAGS)
endif

s21_math.a: $(filter $(func_dir)/%.o, $(obj_list))
	ar rc $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) -c $^ -o $@

# gcov_report:

clang:
#	clang-format -n $(addsuffix /*.c, $(test_dir)) $(addsuffix /*.c, $(func_dir))
	clang-format -i $(addsuffix /*.c, $(test_dir)) $(addsuffix /*.c, $(func_dir))

clean:
	@rm *.a $(obj_list) test