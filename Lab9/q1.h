#ifndef __Q1__
#define __Q1__

#include <stdlib.h>

void Q1();
size_t  getAsciiSum(const char* str);
size_t  sum(const char* str, size_t(*getSum)(const char* str));

#endif