//
//  MyCppClass.cpp
//  C++调用OC方法
//
//  Created by 任迅 on 2021/8/23.
//

#include "MyCppClass.hpp"
#include "c_bridge_Interface.h"

MyCPPClass::MyCPPClass()
{
    
}

MyCPPClass::~MyCPPClass()
{
    
}


int MyCPPClass::someMethod (void *objectiveCObject, void *aParameter)
{
    // To invoke an Objective-C method from C++, use
    // the C trampoline function
    return MyObjectDoSomethingWith (objectiveCObject, aParameter);
}

void MyCPPClass::setSelf(void *aSelf)
{
    self = aSelf;
}
