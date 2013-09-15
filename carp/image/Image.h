#ifndef CARP__IMAGE__IMAGE_H
#define CARP__IMAGE__IMAGE_H

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