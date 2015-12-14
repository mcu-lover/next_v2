#ifndef IMAGE_STUB_HEADER
#define IMAGE_STUB_HEADER


#ifdef _MSC_VER
#include <pshpack2.h>
#endif


#ifndef tagBITMAPFILEHEADER
typedef struct tagBITMAPFILEHEADER {
    short			bfType;
    unsigned long   bfSize;
    short			bfReserved1;
    short			bfReserved2;
    unsigned long   bfOffBits;
} BITMAPFILEHEADER;



#ifdef _MSC_VER
#include <poppack.h>
#endif

typedef BITMAPFILEHEADER *LPBITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {
    unsigned long      biSize;
    long			   biWidth;
    long			   biHeight;
    short			   biPlanes;
    short			   biBitCount;
    unsigned long      biCompression;
    unsigned long      biSizeImage;
    long               biXPelsPerMeter;
    long               biYPelsPerMeter;
    unsigned long      biClrUsed;
    unsigned long      biClrImportant;
} BITMAPINFOHEADER;

typedef  BITMAPINFOHEADER *LPBITMAPINFOHEADER;


typedef struct tagRGBQUAD {
    unsigned char    rgbBlue;
    unsigned char    rgbGreen;
    unsigned char    rgbRed;
    unsigned char    rgbReserved;
} RGBQUAD;

typedef RGBQUAD * LPRGBQUAD;

typedef struct tagBITMAPINFO {
    BITMAPINFOHEADER    bmiHeader;
    RGBQUAD             bmiColors[1];
} BITMAPINFO;

typedef BITMAPINFO *LPBITMAPINFO;


#endif



class  bmpImage
{
   static const size_t bitPerPlane = 24;
public:
    bmpImage();
    bmpImage(bmpImage & b);
    ~bmpImage();
    bool copyFromFile(const wchar_t *name);
    bool copyFrombmpImage(bmpImage & b);
    bool copyToFile(const wchar_t *name);
    bool create(int width, int height,  unsigned char  color);
    bool isValid(void);
    bool clear(void);
    bool detach(void);
    bool attach(bmpImage &);
    bool attach(LPBITMAPFILEHEADER p);
    bool portrait(bool mirror = true);
    bool landscape(bool mirror = true);
    bool check(unsigned int Width, unsigned int Height);
    LPBITMAPINFOHEADER getInfoHeader(void) const;
    LPBITMAPINFO getInfo() const;
    LPRGBQUAD  getPalette(void);
    void setHorizontalResolution(double value);
    void setVerticalResolution(double value);
    bool setSize( unsigned width, unsigned height);
    unsigned int getBitsPerPixel(void) const;
    unsigned int getColorsUsed(void) const;
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    unsigned int getLine(void) const;
    unsigned int getPitch(void) const;
    unsigned char * getScanLine(unsigned scanline);
    unsigned char * getBits();
    bool invert(void);
    unsigned int  getColorType(void);
    bool convertTo24Bits(void);
    bool rotate(double angle);
    bool flipHorizontal(void);
    bool flipVertical(void);
    bool pasteSubImage(LPBITMAPFILEHEADER src, int left, int top);
    inline operator LPBITMAPFILEHEADER() { return m_hBitmap; }
    void operator =(bmpImage & b);
    bool swaptoBGR(void);
    bool swaptoRBG(void);
    bool swaptoGRB(void);
    bool copyBits(bmpImage & dst, size_t left,size_t top,size_t right,size_t bottom);
    bool drawSprite(bmpImage & sprite, int left, int top);
protected:
    bool replace(LPBITMAPFILEHEADER new_dib);
    static size_t getInternalImageSize(unsigned int width, unsigned int height);
    static LPBITMAPFILEHEADER  allocateBitmap(unsigned int width, unsigned int height);
    static void freeBitmap(LPBITMAPFILEHEADER bI);
    static LPBITMAPINFOHEADER  getInfoHeader(LPBITMAPFILEHEADER bI);
    static LPBITMAPINFO getInfo(LPBITMAPFILEHEADER bI);
    static LPRGBQUAD  getPalette(LPBITMAPFILEHEADER bI);
    static unsigned int getBitsPerPixel(LPBITMAPFILEHEADER bI);
    static unsigned char * getScanLine(LPBITMAPFILEHEADER bI, unsigned scanline);
    static unsigned char * getBits(LPBITMAPFILEHEADER bI);
    static unsigned int getHeight(LPBITMAPFILEHEADER bI);
    static unsigned int getWidth(LPBITMAPFILEHEADER bI);
    static unsigned int getPitch(LPBITMAPFILEHEADER bI);
    static unsigned int getLine(LPBITMAPFILEHEADER bI);
    static LPBITMAPFILEHEADER rotateInt(LPBITMAPFILEHEADER bI, double angle);
    static unsigned int bmpImage::getColorType(LPBITMAPFILEHEADER bI);
    static unsigned int getColorsUsed(LPBITMAPFILEHEADER bI);
    static LPBITMAPFILEHEADER RotateAny(LPBITMAPFILEHEADER src, double dAngle);
    static LPBITMAPFILEHEADER Rotate90(LPBITMAPFILEHEADER src);
    static LPBITMAPFILEHEADER Rotate180(LPBITMAPFILEHEADER src);
    static LPBITMAPFILEHEADER Rotate270(LPBITMAPFILEHEADER src);
    static LPBITMAPFILEHEADER cloneImage(LPBITMAPFILEHEADER pI);
    static bool pasteSubImage(LPBITMAPFILEHEADER dst, LPBITMAPFILEHEADER src, int left, int top);
    static bool copyBits(LPBITMAPFILEHEADER dst, LPBITMAPFILEHEADER src,size_t left, size_t top, size_t width, size_t height);
    static bool swapto(LPBITMAPFILEHEADER pI, int iSorg, int iDest);
    static bool drawSprite(LPBITMAPFILEHEADER dst, LPBITMAPFILEHEADER sprite, size_t left, size_t top);
protected:
    BITMAPFILEHEADER * m_hBitmap;
};



#include <map>



class  listImage
    :public std::map<size_t ,bmpImage * >
{
    unsigned int Width;
    unsigned int Height;

public:
    listImage( unsigned int w = 0, unsigned int h = 0);
    ~listImage();
    bool Add(size_t index, bmpImage & b );
};


class bmpSprite
    : public bmpImage
{
public:
    bmpSprite() :bmpImage(){};
    bool fromImages(bmpImage & obj, bmpImage & mask);
protected:
    bool toSprite(LPBITMAPFILEHEADER dest, LPBITMAPFILEHEADER image, LPBITMAPFILEHEADER mask);
};

#endif