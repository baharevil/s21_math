#ifndef S21_MATH_H
#define S21_MATH_H

#define S21_NAN 0.0f / 0.0f
#define S21_INF 1.0f / 0.0f
#define S21_HUGE_VAL 1e10000f
#define S21_MIN_VAL 1e-323

/* Some useful constants.  */
#define S21_M_E 2.7182818284590452354         /* e */
#define S21_M_LOG2E 1.4426950408889634074     /* log_2 e */
#define S21_M_LOG10E 0.43429448190325182765   /* log_10 e */
#define S21_M_LN2 0.69314718055994530942      /* log_e 2 */
#define S21_M_LN10 2.30258509299404568402     /* log_e 10 */
#define S21_M_PI 3.14159265358979323846       /* pi */
#define S21_M_PI_2 1.57079632679489661923     /* pi/2 */
#define S21_M_PI_4 0.78539816339744830962     /* pi/4 */
#define S21_M_1_PI 0.31830988618379067154     /* 1/pi */
#define S21_M_2_PI 0.63661977236758134308     /* 2/pi */
#define S21_M_2_SQRTPI 1.12837916709551257390 /* 2/sqrt(pi) */
#define S21_M_SQRT2 1.41421356237309504880    /* sqrt(2) */
#define S21_M_SQRT1_2 0.70710678118654752440  /* 1/sqrt(2) */

#include <features.h>
#include <bits/endian.h>

__BEGIN_DECLS

union ieee754_double
  {
    double d;

    /* This is the IEEE 754 double-precision format.  */
    struct
      {
#if	__BYTE_ORDER == __BIG_ENDIAN
	unsigned int negative:1;
	unsigned int exponent:11;
	/* Together these comprise the mantissa.  */
	unsigned int mantissa0:20;
	unsigned int mantissa1:32;
#endif				/* Big endian.  */
#if	__BYTE_ORDER == __LITTLE_ENDIAN
# if	__FLOAT_WORD_ORDER == __BIG_ENDIAN
	unsigned int mantissa0:20;
	unsigned int exponent:11;
	unsigned int negative:1;
	unsigned int mantissa1:32;
# else
	/* Together these comprise the mantissa.  */
	unsigned int mantissa1:32;
	unsigned int mantissa0:20;
	unsigned int exponent:11;
	unsigned int negative:1;
# endif
#endif				/* Little endian.  */
      } ieee;

    /* This format makes it easier to see if a NaN is a signalling NaN.  */
    struct
      {
#if	__BYTE_ORDER == __BIG_ENDIAN
	unsigned int negative:1;
	unsigned int exponent:11;
	unsigned int quiet_nan:1;
	/* Together these comprise the mantissa.  */
	unsigned int mantissa0:19;
	unsigned int mantissa1:32;
#else
# if	__FLOAT_WORD_ORDER == __BIG_ENDIAN
	unsigned int mantissa0:19;
	unsigned int quiet_nan:1;
	unsigned int exponent:11;
	unsigned int negative:1;
	unsigned int mantissa1:32;
# else
	/* Together these comprise the mantissa.  */
	unsigned int mantissa1:32;
	unsigned int mantissa0:19;
	unsigned int quiet_nan:1;
	unsigned int exponent:11;
	unsigned int negative:1;
# endif
#endif
      } ieee_nan;
  };

#define IEEE754_DOUBLE_BIAS	0x3ff /* Added to exponent.  */

union ieee854_long_double
  {
    long double d;

    /* This is the IEEE 854 double-extended-precision format.  */
    struct
      {
#if	__BYTE_ORDER == __BIG_ENDIAN
	unsigned int negative:1;
	unsigned int exponent:15;
	unsigned int empty:16;
	unsigned int mantissa0:32;
	unsigned int mantissa1:32;
#endif
#if	__BYTE_ORDER == __LITTLE_ENDIAN
# if	__FLOAT_WORD_ORDER == __BIG_ENDIAN
	unsigned int exponent:15;
	unsigned int negative:1;
	unsigned int empty:16;
	unsigned int mantissa0:32;
	unsigned int mantissa1:32;
# else
	unsigned int mantissa1:32;
	unsigned int mantissa0:32;
	unsigned int exponent:15;
	unsigned int negative:1;
	unsigned int empty:16;
# endif
#endif
      } ieee;

    /* This is for NaNs in the IEEE 854 double-extended-precision format.  */
    struct
      {
#if	__BYTE_ORDER == __BIG_ENDIAN
	unsigned int negative:1;
	unsigned int exponent:15;
	unsigned int empty:16;
	unsigned int one:1;
	unsigned int quiet_nan:1;
	unsigned int mantissa0:30;
	unsigned int mantissa1:32;
#endif
#if	__BYTE_ORDER == __LITTLE_ENDIAN
# if	__FLOAT_WORD_ORDER == __BIG_ENDIAN
	unsigned int exponent:15;
	unsigned int negative:1;
	unsigned int empty:16;
	unsigned int mantissa0:30;
	unsigned int quiet_nan:1;
	unsigned int one:1;
	unsigned int mantissa1:32;
# else
	unsigned int mantissa1:32;
	unsigned int mantissa0:30;
	unsigned int quiet_nan:1;
	unsigned int one:1;
	unsigned int exponent:15;
	unsigned int negative:1;
	unsigned int empty:16;
# endif
#endif
      } ieee_nan;
  };

#define IEEE854_LONG_DOUBLE_BIAS 0x3fff

__END_DECLS

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exponent);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif