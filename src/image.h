#include<iostream>
#include<stdint.h>

enum  ImageType {
  PNG , JPG,BMP , TGA 
};


class Image
{

public:

uint8_t * data = NULL;
size_t size = 0;
int width;
int height;
int channels;




Image(const char* filename);

Image(int width,int height,int channels);

Image(const Image & image);

~Image();

bool read(const char * filename);

bool write(const char * filename);

ImageType getFileType(const char * filename);

Image & grayscale_avg();
Image & grayscale_lum();
Image & grayscale_light();

};