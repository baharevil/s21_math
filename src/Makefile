CC = gcc
CFLAGS =-Wall -Werror -Wextra -Wfloat-equal -Wconversion -std=c11 -pedantic
LDFLAGS = -lm
DEBUG =-g

program_name = s21_math
dir = function/
obj_list = s21_abs.o s21_ceil.o s21_cos.o s21_fabs.o s21_floor.o s21_exp.o s21_fmod.o s21_pow.o s21_log.o s21_sqrt.o
dir_obj_list = $(addprefix $(dir), $(obj_list))

.PHONY: all rebuild clean test
all: $(program_name)

# test
$(program_name): s21_math.o s21_math.a
	$(CC) -o $@ s21_math.o -L. -ls21_math $(LDFLAGS)

s21_math.a: $(dir_obj_list)
	ar cr $(addprefix lib, $@) $^

s21_math.o: s21_math.c
	$(CC) $(CFLAGS) $(DEBUG) -c $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) -c $^ -o $@

# gcov_report

clean:
	rm $(dir_obj_list) *.o *.a $(program_name)

