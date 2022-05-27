#include "image.h"


int main(int argc , char** argv)
{
    Image test("Kohli.jpg");
    Image gray_scale = test;
    gray_scale.grayscale_avg();
    gray_scale.write("Average_gray.png");
    
    Image gray_scale1 = test;
    gray_scale1.grayscale_lum();
    gray_scale1.write("Lum_gray.jpg");

    Image gray_scale2 = test;
    gray_scale2.grayscale_light();
    gray_scale2.write("Light_gray.png");

}