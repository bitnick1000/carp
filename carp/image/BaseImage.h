#ifndef __BASE_IMAGE_H__
#define __BASE_IMAGE_H__

class Image {
protected:
    int width, height;
public:
    //properties
    int Width() const {
        return this->width;
    }
    int Height() const {
        return this->height;
    }
};

#endif