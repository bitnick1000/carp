#include "console.h"
#include "console.h"
#include "log.h"
#include "log.h"
#include <iostream>
enum class Clor {
    RED = FOREGROUND_RED
};
void main() {
    Log log;
    log.Hello();
    /*Console console;*/
    //Console::color=
    //Console::color=Console::Color::FONT_COLOR_RED;
    Console::PrintAllColors();
    int a = (int)Clor::RED;

    printf("%d\n", a);
}