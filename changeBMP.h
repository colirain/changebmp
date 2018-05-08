//cut file using c++
typedef struct BMPHeader  
{  
    unsigned char bfType[2];//文件格式  
    unsigned long bfSize;//文件大小  
    unsigned short bfReserved1;//保留  
    unsigned short bfReserved2;  
    unsigned long bfOffBits; //DIB数据在文件中的偏移量  
}Header;  
typedef struct BMPInfo  
{  
    unsigned long biSize;//该结构的大小  
    long biWidth;//文件宽度  
    long biHeight;//文件高度  
    unsigned short biPlanes;//平面数  
    unsigned short biBitCount;//颜色位数  
    unsigned long biCompression;//压缩类型  
    unsigned long biSizeImage;//DIB数据区大小  
    long biXPixPerMeter;  
    long biYPixPerMeter;  
    unsigned long biClrUsed;//多少颜色索引表  
    unsigned long biClrImporant;//多少重要颜色  
}Info;  
typedef struct RGBQuad  
{  
    unsigned char rgbBlue; //蓝色分量亮度  
    unsigned char rgbGreen;//绿色分量亮度  
    unsigned char rgbRed;//红色分量亮度  
    unsigned char rgbReserved;  
}Quad;  