#include <ieee754.h>

#include "s21_math.h"

//Метод половиного деления
long double s21_sqrt(double x) {
  long double result = 0;

  // Проверка на отрицательную
  if (x < 0)
    result = -S21_NAN;
  else 
    result = s21_pow(x, 0.5);
    
  return (double)result;
}