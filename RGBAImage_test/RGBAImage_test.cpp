#include <jasmine.h>
#include <image.h>

#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>

void main() {
    Describe("RGBAImage<byte>", []() {
		std::cout<<(UINT16)~(UINT16)0;
	//std::cout<< ~((UINT16)0);
        Expect(true).ToBeTruthy();
        It("should be able to read data from bmp file", []() {
            RGBAImage<byte> image("TestResources/Lena.bmp");
            Expect(image.Height()).ToBe(512);
            Expect(image.Width()).ToBe(512);
        });
        Describe("when read lena.bmp finished", []() {
            RGBAImage<byte> image("TestResources/Lena.bmp");
            It("should be able to get pixel", [&image]() {
                //RGBAColor<byte> color={1,2,94,0};
                Expect(image.GetPixel(0, 0)).ToBe(RGBAColor<byte>(255, 138, 128, 255));
                /*		std::for_each(
                		image.GetPixel*/
            });
        });
    });
}