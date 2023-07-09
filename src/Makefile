CC = gcc
CFLAGS =-Wall -Werror -Wextra -Wfloat-equal -Wconversion -std=c11 -pedantic
LDFLAGS = -lm
DEBUG =-g

.PHONY: all clean test
all: s21_math

s21_math: s21_math.o s21_abs.o s21_fabs.o s21_exp.o s21_pow.o s21_log.o s21_sqrt.o
	$(CC) s21_math.o s21_abs.o s21_fabs.o s21_exp.o s21_pow.o s21_log.o s21_sqrt.o -o s21_math $(LDFLAGS)
s21_math.o: s21_math.c
	$(CC) $(CFLAGS) $(DEBUG) -c s21_math.c -o s21_math.o
s21_abs.o: s21_abs.c
	$(CC) $(CFLAGS) $(DEBUG) -c s21_abs.c -o s21_abs.o
s21_fabs.o: s21_fabs.c
	$(CC) $(CFLAGS) $(DEBUG) -c s21_fabs.c -o s21_fabs.o
s21_exp.o: s21_exp.c
	$(CC) $(CFLAGS) $(DEBUG) -c s21_exp.c -o s21_exp.o
s21_log.o: s21_log.c
	$(CC) $(CFLAGS) $(DEBUG) -c s21_log.c -o s21_log.o
s21_pow.o: s21_pow.c
	$(CC) $(CFLAGS) $(DEBUG) -c s21_pow.c -o s21_pow.o
s21_sqrt.o: s21_sqrt.c
	$(CC) $(CFLAGS) $(DEBUG) -c s21_sqrt.c -o s21_sqrt.o

clean:
	rm *.o s21_math

#s21_math.a
#gcov_report:
