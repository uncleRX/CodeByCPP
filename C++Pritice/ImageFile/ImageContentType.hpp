//
//  ImageContentType.hpp
//  ImageFile
//
//  Created by 任迅 on 2021/10/21.
//

#ifndef ImageContentType_hpp
#define ImageContentType_hpp

#include <stdio.h>

typedef enum : int {
    UNKNOW,
    JPEG,
    PNG,
    GIF,
}ImageType;

ImageType getTypeForImageData(int* buffer)
{
    return UNKNOW;
}



#endif /* ImageContentType_hpp */
