int s21_abs(int x) {
    unsigned int result = 0;
    if (x > 0)
        result = x;
    else
        result = -x;
    return result;
}