//
//  main.m
//  Union(OC)
//
//  Created by 任迅 on 2021/11/23.
//

#import <Foundation/Foundation.h>


union ZQVec3 {
    struct
    {
        float x, y ,z;
    };
    struct
    {
        float r, g, b;
    };
};


int main(int argc, const char * argv[]) {
    
    union ZQVec3 v3c = {1,1,1};
//    v3c.position.x = 1;
//    v3c.position.y = 1;
//    v3c.position.z = 1;
//
//    v3c.rgb.r = 1;
//    v3c.rgb.g = 1;
//    v3c.rgb.b = 1;
//    ns
    return 0;
}
