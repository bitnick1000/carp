#ifndef __LOG_H__
#define __LOG_H__

#include "console.h"

#include <iostream>

class Log {
public:
    void Hello() ;
};
void Log::Hello() {
        printf("hello");
    }
#endif