#ifndef S21_MATH
#define S21_MATH

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

int s21_abs(int x);
long double s21_fabs(double);
long double s21_exp(double);
long double s21_log(double x);
long double s21_fmod(double x, double y);
long double s21_pow(double base, double exponent);
long double s21_sqrt(double x);

// 1	int abs(int x)	                            | +
// 2	long double acos(double x)	                | 
// 3	long double asin(double x)	                | 
// 4	long double atan(double x)	                | 
// 5	long double ceil(double x)	                | 
// 6	long double cos(double x)	                | 
// 7	long double exp(double x)	                | +
// 8	long double fabs(double x)	                | +
// 9	long double floor(double x)	                |
// 10	long double fmod(double x, double y)        | +
// 11	long double log(double x)	                | +
// 12	long double pow(double base, double exp)	| +-
// 13	long double sin(double x)	                |
// 14	long double sqrt(double x)	                | +-
// 15	long double tan(double x)                   | 

#endif