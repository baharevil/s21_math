CC = gcc
CFLAGS =-Wall -Werror -Wextra -Wfloat-equal -std=c11 -pedantic
LDFLAGS = -lm
DEBUG =-g

.PHONY: all clean test
all: s21_math

s21_math: s21_math.o s21_abs.o s21_fabs.o s21_exp.o s21_pow.o
	$(CC) s21_math.o s21_abs.o s21_fabs.o s21_exp.o s21_pow.o -o s21_math $(LDFLAGS)
s21_math.o: s21_math.c
	$(CC) $(CFLAGS) $(DEBUG) -c s21_math.c -o s21_math.o
s21_abs.o: s21_abs.c
	$(CC) $(CFLAGS) $(DEBUG) -c s21_abs.c -o s21_abs.o
s21_fabs.o: s21_fabs.c
	$(CC) $(CFLAGS) $(DEBUG) -c s21_fabs.c -o s21_fabs.o
s21_exp.o: s21_exp.c
	$(CC) $(CFLAGS) $(DEBUG) -c s21_exp.c -o s21_exp.o
s21_pow.o: s21_pow.c
	$(CC) $(CFLAGS) $(DEBUG) -c s21_pow.c -o s21_pow.o

clean:
		rm *.o s21_math

#s21_math.a
#gcov_report:
