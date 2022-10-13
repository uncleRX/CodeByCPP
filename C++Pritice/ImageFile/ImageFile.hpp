//
//  ImageFile.hpp
//  ImageFile
//
//  Created by 任迅 on 2021/10/21.
//

#ifndef ImageFile_hpp
#define ImageFile_hpp

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>

typedef std::string String;

class ImageFile  {
public:
    static ImageFile* create(const String& path)
    {
        FILE* fS;
        fS = fopen(path.c_str(), "r");
        if(fS !=NULL)
        {
            int i;
            int iLen = path.length() ;
            int iPos = path.reverseFind('.');
            if (iPos <= 0)
            {
                return NULL;
            }
            String name = path.substring(iPos + 1, iLen);
            char s1[10];
            char s2[]="jpg";
            char s3[]="bmp";
            char s4[]="gif";
            char s5[]="png";
            char s6[]="jpeg";
            for(i=0;i<name.length();i++)
                s1[i] = name[i];
            s1[i] = '\0';
            if(strncmp(s1,s2,3)==0 || strncmp(s1,s3,3)==0 || strncmp(s1,s4,3)==0 || strncmp(s1,s5,3)==0|| strncmp(s1,s6,4)==0)
                return new NGBImageFile(path);     //路径正确且图片文件格式是以上四种，创建文件对象
            else
                return NULL;
        }
          return NULL;
    }

    String type() const;
    String location() const;
    String fileName() const;
    double width() const;
    double height() const;

private:
    ImageFile(const String& path);
    char* src;
    String mpath;
    String mtype;
    double mwidth;
    double mheight;
};



#endif /* ImageFile_hpp */
