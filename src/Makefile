CC = gcc
CFLAGS =-Wall -Werror -Wextra -Wfloat-equal -Wconversion -std=c11 -pedantic
LDFLAGS = -lm
DEBUG = -g

program_name = s21_math
dir = function
dir_obj_list = $(patsubst %.c, %.o, $(wildcard $(addsuffix /*.c, $(dir))))

.PHONY: all rebuild clean test
all: $(program_name)

# test
$(program_name): $(addsuffix .o, $(program_name)) s21_math.a
	$(CC) -o $@ $< -L. -ls21_math $(LDFLAGS)

s21_math.a: $(dir_obj_list)
	ar cr $(addprefix lib, $@) $^

%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) -c $^ -o $@

# gcov_report:

rebuild: clean all

clean:
	rm $(dir_obj_list) *.o *.a $(program_name)