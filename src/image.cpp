#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "image.h"
#include "stb_image.h"
#include "stb_image_write.h"

using namespace std;

Image :: Image(const char * filename)
{
if (read(filename))
{
std::cout<<"Read the image successfully"<<std::endl;
size = width*height*channels;
}
else 
{
    std::cout<<"Couldn't read filename"<<std::endl;
}
}

Image::Image(int width, int height , int channels) : width(width),height(height),channels(channels)
{
    size = width * height * channels;
    data = new uint8_t[size];
}

Image::Image(const Image & image) : Image(image.width,image.height,image.channels)
{
    memcpy(data,image.data,size);
}


Image :: ~Image()
{
    stbi_image_free(data);
}

bool Image::read(const char* filename)
{
   data = stbi_load(filename,&width,&height,&channels,0);
   return data!=nullptr;

}

bool Image::write(const char *filename)
{
   ImageType type = getFileType(filename);
   int success;
   switch(type)
   {  case PNG:
        success = stbi_write_png(filename,width,height,channels,data,width*channels);
        break;
      case BMP :
         success = stbi_write_bmp(filename,width,height,channels,data);
         break;
      case JPG:
         success = stbi_write_jpg(filename,width,height,channels,data,100);
         break;
       case TGA:
         success = stbi_write_tga(filename,width,height,channels,data);
         break;

   }

   return success!=0;


}


ImageType Image::getFileType(const char * filename)
{
    const char * extension = strchr(filename,'.');
    ImageType x;
    if(extension!=nullptr)
    {
        
        if(strcmp(extension,".jpg")==0)
        {
            x = JPG;
        }
        else if (strcmp(extension,".png")==0)
        {
            x = PNG;
        }
        else if (strcmp(extension,".bmp")==0)
        {
            x = BMP;
        }

        else if (strcmp(extension,".tga")==0)
        {
            x = TGA;
        }
    }
    else 
    {
        x = PNG;
    }

 return x;
}

Image& Image::grayscale_avg()
{
    if(channels < 3 )
    {
        std::cout<<"Image is already grayscale "<<std::endl;

    }
    else 
    {
        for(int i=0;i<size;i+=channels)
        {
              int gray = (data[i] + data[i+1] +data[i+2])/3;
              memset(data+i,gray,3);
        }
    }
     return *this;
}

Image& Image::grayscale_lum()
{
    if(channels<3)
    {
        std::cout<<"Image is already grayscale"<<std::endl;
    }
    else
    {  for(int i=0;i<size;i+=channels){
        int gray = (0.3*data[i] + 0.59*data[i+1] + 0.11*data[i+2])/3;
        memset(data+i,gray,3);
    }

    }

    return *this;
}

Image& Image::grayscale_light()
{
    if(channels<3)
    {
        std::cout<<"Image is already grayscale"<<std::endl;
    }

    else 
    {  int min,max;
        for(int i=0;i<size;i+=channels)
        {
            if(data[i]<=data[i+1] && data[i]<=data[i+2])
            {
                min = data[i];
            }
            else if(data[i+1]<=data[i]&&data[i+1]<=data[i+2])
            {
                min = data[i+1];
            }
            else 
            {
                min = data[i+2];
            }
  if(data[i]>=data[i+1] && data[i]>=data[i+2])
            {
                max = data[i];
            }
            else if(data[i+1]>=data[i]&&data[i+1]>=data[i+2])
            {
                max = data[i+1];
            }
            else 
            {
                max = data[i+2];
            }

            int gray = (max+min)/2;
            memset(data+i,gray,3);

            
        }
    }

    return *this;
   
}

Image &Image::flipX()
{
    uint8_t temporaray[4];
    uint8_t *px1;
    uint8_t *px2;
    for(int y=0;y<height;++y)
    {
        for(int x=0;x<width/2;++x)
        {
            px1 = &data[(x+y*width)*channels];
            px2 = &data[((width-1-x)+y*width)*channels];
            memcpy(temporaray,px1,channels);
            memcpy(px1,px2,channels);
            memcpy(px2,temporaray,channels);
        }
    }
    return *this;
}

Image& Image::flipY() 
{
    uint8_t temporaray[4];
    uint8_t *px1;
    uint8_t *px2;
    for(int x=0;x<width;++x)
    {
        for(int y=0;y<height/2;++y)
        {
            px1 = &data[(x+y*width)*channels];
            px2 = &data[(x+(height-1-y)*width)*channels];
            memcpy(temporaray,px1,channels);
            memcpy(px1,px2,channels);
            memcpy(px2,temporaray,channels);
        }
    }
    return *this;
}


