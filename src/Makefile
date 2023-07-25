CC = gcc
CFLAGS = -Wall -Werror -Wextra -Wfloat-equal -Wconversion -std=c11 -pedantic -I.
TESTFlAGS = #-lcheck -lsubunit -lrt -lpthread -lgcov
LDFLAGS = -lm
DEBUG = -g

project_name = s21_math
func_dir = function
test_dir = .
dirs = $(func_dir) $(test_dir)
obj_list = $(patsubst %.c, %.o, $(wildcard $(addsuffix /*.c, $(dirs))))

.PHONY: all clean gcov_report
all: $(project_name)

# Функции используемые в целях
# https://rus-linux.net/nlib.php?name=/MyLDP/algol/gnu_make/gnu_make_3-79_russian_manual.html#SEC78

$(project_name): $(addsuffix .a, $(project_name)) $(addsuffix .o, $(project_name)) $(filter $(func_dir)/%.o, $(obj_list))
	$(CC) -o $@ $(wordlist 2, $(words $^), $^) -L. -l$(basename $<) $(TESTFlAGS) $(LDFLAGS)
	

$(addsuffix .a, $(project_name)): $(filter $(func_dir)/%.o, $(obj_list))
	ar rc $@

%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) -c $^ -o $@

# gcov_report:

clang:
#	clang-format -n $(addsuffix /*.c, $(test_dir)) $(addsuffix /*.c, $(func_dir))
	clang-format -i $(addsuffix /*.c, $(test_dir)) $(addsuffix /*.c, $(func_dir))

clean:
	@rm $(project_name) *.o *.a
