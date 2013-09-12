#include "console.h"
#include "console.h"
#include "log.h"
#include "log.h"
#include <iostream>

#include "jasmine.h"
//#include "jasmine\spec.h"
enum class Clor {
    RED = FOREGROUND_RED
};

void main() {
    Describe("Player", []() {
        Expect(true).ToBeTruthy();
        It("should be able to play a Song", []() {
            Expect(true).ToBeTruthy();
        });
        Describe("when song has been paused", []() {
            It("should indicate that the song is currently paused", []() {
                Expect(true).ToBeTruthy();
            });
            It("should be possible to resume", []() {
                Expect(true).ToBeTruthy();
            });
        });
        It("tells the current song if the user has made it a favorite", []() {
            Expect(true).ToBeTruthy();
        });
        Describe("alway error", []() {
            Expect("always error").ToBe("error");
        });
    });
}