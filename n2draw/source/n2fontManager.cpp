#include "stdio.h"
#include "images.h"
#include "n2draw.h"
#include "n2fontmanager.h"
#include "n2exception.h"

#ifndef _MSC_VER
#include <unistd.h>
#define _MAX_PATH  4096
#else
#include <direct.h>
#endif


nnFontManager::nnFontManager(const XCHAR *_path)
{
    availObj.clear();
    allImages.clear();
    path.clear();
    if (_path)
        path = _path;
}

nnFontManager::~nnFontManager()
{
    availObj.clear();
    allImages.clear();
    path.clear();
}
#if (_WIN32 || _WIN64)
#define getcwd  _getcwd
#endif

bool nnFontManager::readConfiguration(IXmlNode *node)
{
    bool res = false;
    long offset;
    STRING filename;
    IXmlNode *t = node->find(X("SYM"));
    if (t)
    {
        do {
            filename.clear();
            offset = -1;
            IXmlNode *e = t->find(X("VALUE"));
            if (e)
            {
                STRING _v = e->getValue();
                if (_v.size() > 0)
                    offset = _v.front();
            }
            e = t->find(X("FILE"));
            if (e)
            {
                filename = e->getValue();
            }
            if (offset >= 0 && !filename.empty())
            {
                if (availObj.find(offset) == availObj.end())
                    availObj[offset] = filename;
                else
                {
                    imagesConfigurationAlreadyLoadException *pe = new imagesConfigurationAlreadyLoadException(offset);
                    throw (pe);
                }
            }
            else
            {
                imagesConfigurationBadFormatException *pe = new imagesConfigurationBadFormatException();
                throw (pe);
            }
        } while ((t = t->getNext()) != nullptr);
    }
    return res = !availObj.empty();
}

bool nnFontManager::loadImages(void)
{
    bool res = false;
    if (availObj.size() > 0)
    {
        STRING filenameabs;
        objImageList::iterator it = availObj.begin();
        objImageList::iterator _end = availObj.end();
        while (it != _end)
        {
            bmpImage image;
            filenameabs = path;
            filenameabs += it->second;
            if (image.copyFromFile(filenameabs.c_str()))
            {
               
                    if (image.getBitsPerPixel() != 24)
                        image.convertTo24Bits();
                    //TO DO STRECT TO FIT
                    allImages.Add(it->first, image);

            }
            else
            {
                imagesConfigurationUnknowFileException *pe = new imagesConfigurationUnknowFileException(filenameabs);
                throw (pe);
            }
            it++;
        }
        res = true;
    }
    else
    {
        imagesConfigurationListEmptyException *pe = new imagesConfigurationListEmptyException();
        throw (pe);
    }
    return res;
}


bmpImage * nnFontManager::getImage(const char *_msg, unsigned char red, unsigned char green, unsigned char blue)
{
    bmpImage *res = nullptr;
    std::string msg(_msg);
    size_t len = msg.size();
    listImage::iterator it = allImages.begin();
    if (it != allImages.end())
    {
        int uW = it->second->getWidth();
        int uH = it->second->getHeight();
        int width = len * uW;
        res = new bmpImage();
        if (res)
        {
            res->create(width, uH, 0);
        }
        int pos_x = 0;
        for (auto i : msg)
        {
            it = allImages.find((int)i);
            if (it != allImages.end())
            {
                res->drawSprite(*it->second, pos_x, 0);
            }
            pos_x += uW;
        }
        res->translateColor(255, 255, 255, red, green, blue);
    }
    return res;
}




bool nnFontManager::setPath(const XCHAR *_path)
{
    path.clear();
    path = _path;
    return true;
}