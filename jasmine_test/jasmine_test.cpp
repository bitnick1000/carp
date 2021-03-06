#include <jasmine.h>

void main() {
    Describe("Player", func() {
        Expect(true).ToBeTruthy();
        It("should be able to play a Song", func() {
            Expect(true).ToBeTruthy();
        });
        Describe("when song has been paused", func() {
            It("should indicate that the song is currently paused", func() {
                Expect(true).ToBeTruthy();
            });
            It("should be possible to resume", func() {
                Expect(true).ToBeTruthy();
            });
        });
        It("tells the current song if the user has made it a favorite", func() {
            Expect(true).ToBeTruthy();
        });
        Describe("alway error", func() {
            Expect("always error").ToBe("error");
        });
    });
}