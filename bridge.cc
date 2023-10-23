#include<iostream>
#include<string>
using namespace std;
class Matrix{

};
class ImageImp{
public:
    virtual void doPaint(Matrix m)=0;
    //present image matrix 
};
class WinImp: public ImageImp{
public:
    void doPaint(Matrix m){
//call the Window system painting code to paint image matrix 
    }
};
class LinuxImp:public ImageImp{
    public:
    void doPaint(Matrix m){
//call the Linux system painting code to paint image matrix 

    }
};
class Image{
    public:
    void setImp(ImageImp *imp){
        //(1)=imp;
        this->imp=imp;
    }
    virtual void parseFile(string fileName)=0;
    protected:
    //(2)*imp;
    ImageImp *imp;
};
class BMP:public Image{
    public:
    void parseFile(string fileName)
    {
        //here parse the BMPfile and attain an object of image matrix named 'm'
         Matrix m;//my addition
        //(3);present image matrix m
        imp->doPaint(m);
       

    }
};
class GIF:public Image{
//...
};
class JPEG:public Image{
    //...
};

int main()
{
    //watch demo.bmp image file in Window system
    // Image* image1=(4);
    Image* image1=new BMP();
    // ImageImp *imageImp1=(5);
    ImageImp *imageImp1=new WinImp();
    // (6);
    image1->setImp(imageImp1);
    image1->parseFile("demo.bmp");

}