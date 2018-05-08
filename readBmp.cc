//read bmp and send it to image vector
#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;
unsigned char *pBmpBuf;//读入图像数据的指针

int bmpWidth;//图像的宽
int bmpHeight;//图像的高
RGBQUAD *pColorTable;//颜色表指针

int biBitCount;//图像类型，每像素位数



//-----------------------------------------------------------------------------------------
//给定一个图像位图数据、宽、高、颜色表指针及每像素所占的位数等信息,将其写到指定文件中
bool readBmp(char *bmpName, std::vector<std::vector<float> > *images) 
{
    FILE *fp=fopen(bmpName,"rb");//二进制读方式打开指定的图像文件

    if(fp==0)
        return 0;

    //跳过位图文件头结构BITMAPFILEHEADER

    fseek(fp, sizeof(BITMAPFILEHEADER),0);

    //定义位图信息头结构变量，读取位图信息头进内存，存放在变量head中

    BITMAPINFOHEADER head;  

    fread(&head, sizeof(BITMAPINFOHEADER), 1,fp); //获取图像宽、高、每像素所占位数等信息

    bmpWidth = head.biWidth;

    bmpHeight = head.biHeight;

    biBitCount = head.biBitCount;//Specifies the number of bits per pixels. 
    //This value must be 1, 4, 8 or 24 in the 16 bit version; values of 16 or 32 may also be used in the 32 bit version of DaVinci.

    int lineByte=(bmpWidth * biBitCount/8+3)/4*4;//灰度图像有颜色表，且颜色表表项为256

    if(biBitCount==8)
    {

        //申请颜色表所需要的空间，读颜色表进内存

        pColorTable=new RGBQUAD[256];

        fread(pColorTable,sizeof(RGBQUAD),256,fp);

    }

    //申请位图数据所需要的空间，读位图数据进内存

    pBmpBuf=new unsigned char[lineByte * bmpHeight];

    fread(pBmpBuf,1,lineByte * bmpHeight,fp);

    for(int i=0; i < lineByte * bmpHeight; i++)
    {
        printf("%c ", pBmpBuf[i]);
        if(i%lineByte == 0){
            printf("\n");
        }
    }

    fclose(fp);//关闭文件

    return 1;//读取文件成功
}

int main(){
    std::vector<std::vector<float> > *images;
    readBmp("viewfile.bmp", images); 

}