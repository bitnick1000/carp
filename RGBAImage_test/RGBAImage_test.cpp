#include <jasmine.h>
#include <image.h>

#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>

void debug() {

}
void main() {
    debug();
    Describe("RGBAImage<byte>", []() {
        It("should be able to read data from bmp file", []() {
            RGBAImage<byte> image("TestResources/rgbw_2x2.bmp");
            Expect(image.GetPixel(0, 0)).ToBe(RGBAColor<byte>(255, 0, 0, 255));
            Expect(image.GetPixel(1, 0)).ToBe(RGBAColor<byte>(0, 255, 0, 255));
            Expect(image.GetPixel(0, 1)).ToBe(RGBAColor<byte>(0, 0, 255, 255));
            Expect(image.GetPixel(1, 1)).ToBe(RGBAColor<byte>(255, 255, 255, 255));
        });
        Describe("when read lena.bmp finished", []() {
            RGBAImage<byte> image("TestResources/Lena.bmp");
            It("should be able to get width and height", [&image]() {
                Expect(image.Height()).ToBe(512);
                Expect(image.Width()).ToBe(512);
            });
            It("should be able to get pixel", [&image]() {
                //RGBAColor<byte> color={1,2,94,0};
                Expect(image.GetPixel(0, 0)).ToBe(RGBAColor<byte>(225, 138, 128, 255));
                /*		std::for_each(
                image.GetPixel*/
            });
        });
    });
}