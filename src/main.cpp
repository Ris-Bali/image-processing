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

  Image test3("spiderman.jpg");
  Image test4 = test3;
  test4.flipX();
  test4.write("Xflip.jpg");
  Image test5 = test3;
  test5.flipY();
  test5.write("flipy.jpg");

}