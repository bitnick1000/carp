#ifndef __JASMINE_H__
#define __JASMINE_H__

#include <iostream>
#include <Windows.h>

#include "jasmine/spec.h"
#include "jasmine/describe.h"
#include "jasmine/expect.h"

#define func []

#define Benchmark(description,function)     \
	do{                                                              \
	LARGE_INTEGER time_start;                       \
    LARGE_INTEGER time_over;                       \
    double freq;                                                \
    LARGE_INTEGER f;                                      \
    QueryPerformanceFrequency(&f);             \
    freq = (double)f.QuadPart;                         \
    QueryPerformanceCounter(&time_start);   \
	function;                                                      \
	QueryPerformanceCounter(&time_over);   \
	std::cout <<description<<" "<< ((time_over.QuadPart - time_start.QuadPart))  / freq << "s" << std::endl;\
	}while(0);

#endif