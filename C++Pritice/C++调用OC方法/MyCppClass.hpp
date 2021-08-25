//
//  MyCppClass.hpp
//  C++调用OC方法
//
//  Created by 任迅 on 2021/8/23.
//

class MyCPPClass {
    
    
public:
    MyCPPClass();
    ~MyCPPClass();
    int someMethod (void *objectiveCObject, void *aParameter);
    void *self;
    
    void setSelf(void *self);
};
