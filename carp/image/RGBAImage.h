#ifndef __RGBA_IMAGE_H__
#define __RGBA_IMAGE_H__

#include <iostream>
#include <fstream>
#include <Windows.h>
#include "RGBAColor.h"
using namespace std;

template<typename T>
class RGBAImage {
    typedef T value_type ;
    //origin upper left
    T *data;
    int width, height;
public:
    RGBAImage(char* filename) {
        ReadFromFile(filename);
    }
    int Width() {
        return this->width;
    }
    int Height() {
        return this->height;
    }
    RGBAColor<T> GetPixel(int x, int y) {
        T *p = data + y * width + x;
        return *((RGBAColor<T>*)p);
    }
    void ReadFromFile(char* filename) {
        int len   = lstrlen(filename);
        TCHAR ch  = filename[len - 1];
        if(ch == 'g') {
            throw ;
            //ReadFromPngFile(filename);
        } else
            ReadFromBmpFile(filename);
    }
    void ReadFromBmpFile(char* filename) {
        BITMAPFILEHEADER bmpFileHeader;
        BITMAPINFO bmpInfo;
        fstream file;
        file.open(filename, ios::in | ios::binary);
        if(!file)
            return ;
        file.read((char*)&bmpFileHeader, sizeof(BITMAPFILEHEADER));
        file.read((char*)&bmpInfo.bmiHeader, sizeof(BITMAPINFOHEADER));

        this->width = bmpInfo.bmiHeader.biWidth;
        this->height = bmpInfo.bmiHeader.biHeight;
        int spectrum = bmpInfo.bmiHeader.biBitCount / 8;
        int readOffset = 4 - spectrum * this->width & 0x3;

        int  dataSize = this->width * this->height * 4 ;
        data = (T*)malloc(dataSize);
        if( spectrum == 3) {
            file.seekg(bmpFileHeader.bfOffBits);
            char* p = (char*)this->data;
            for(int y = 0; y < this->height; y++) {
                for(int x = 0; x < this->width; x++) {
                    file.read(p, 3);
                    p[3] = (T)~(T)0; //T MAX, byte 255, uint16 65535
                    p += 4;
                }
                file.seekg(readOffset, ios::cur);
            }
        } else if( spectrum == 4 ) {
            file.seekg(bmpFileHeader.bfOffBits);
            file.read((char*)data, dataSize);
        } else {
            printf("error");
            //ASSERT(FALSE);
        }
        file.close();
    }
};


#endif