CC = gcc
CFLAGS =-Wall -Werror -Wextra -Wfloat-equal -Wconversion -std=c11 -pedantic
LDFLAGS = -lm
DEBUG =-g
DIR = function/
OBJ = s21_abs.o s21_ceil.o s21_cos.o s21_fabs.o s21_floor.o s21_exp.o s21_fmod.o s21_pow.o s21_log.o s21_sqrt.o
OBJ_DIR = $(addprefix $(DIR), $(OBJ))

.PHONY: all rebuild clean test
all: s21_math

s21_math: s21_math.o $(OBJ)
	$(CC) s21_math.o $(OBJ_DIR) -o s21_math $(LDFLAGS)

s21_math.o: s21_math.c
	$(CC) $(CFLAGS) $(DEBUG) -c s21_math.c -o s21_math.o

s21_abs.o: $(DIR)s21_abs.c
	$(CC) $(CFLAGS) $(DEBUG) -c $(DIR)s21_abs.c -o $(DIR)s21_abs.o

s21_ceil.o: $(DIR)s21_ceil.c
	$(CC) $(CFLAGS) $(DEBUG) -c $(DIR)s21_ceil.c -o $(DIR)s21_ceil.o

s21_cos.o: $(DIR)s21_cos.c
	$(CC) $(CFLAGS) $(DEBUG) -c $(DIR)s21_cos.c -o $(DIR)s21_cos.o

s21_exp.o: $(DIR)s21_exp.c
	$(CC) $(CFLAGS) $(DEBUG) -c $(DIR)s21_exp.c -o $(DIR)s21_exp.o

s21_fabs.o: $(DIR)s21_fabs.c
	$(CC) $(CFLAGS) $(DEBUG) -c $(DIR)s21_fabs.c -o $(DIR)s21_fabs.o

s21_floor.o: $(DIR)s21_floor.c
	$(CC) $(CFLAGS) $(DEBUG) -c $(DIR)s21_floor.c -o $(DIR)s21_floor.o

s21_fmod.o: $(DIR)s21_fmod.c
	$(CC) $(CFLAGS) $(DEBUG) -c $(DIR)s21_fmod.c -o $(DIR)s21_fmod.o

s21_log.o: $(DIR)s21_log.c
	$(CC) $(CFLAGS) $(DEBUG) -c $(DIR)s21_log.c -o $(DIR)s21_log.o

s21_pow.o: $(DIR)s21_pow.c
	$(CC) $(CFLAGS) $(DEBUG) -c $(DIR)s21_pow.c -o $(DIR)s21_pow.o

s21_sqrt.o: $(DIR)s21_sqrt.c
	$(CC) $(CFLAGS) $(DEBUG) -c $(DIR)s21_sqrt.c -o $(DIR)s21_sqrt.o

clean:
	rm *.o s21_math $(OBJ_DIR)

#s21_math.a
#gcov_report:
