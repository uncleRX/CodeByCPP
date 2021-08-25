//
//  Test.m
//  C++调用OC方法
//
//  Created by 任迅 on 2021/8/23.
//

#import "Test.h"
#import "c_bridge_Interface.h"

@implementation Test

int MyObjectDoSomethingWith (void *self, void *aParameter)
{
    // 通过将self指针桥接为oc 对象来调用oc方法
    return [(__bridge id)self doSomethingWith:aParameter];
}

- (int) doSomethingWith:(void *) aParameter
{
    //将void *指针强转为对应的类型
    int* param = (int *)aParameter;
    return *param / 2 ;
}

- (void)dealloc
{
    NSLog(@"%s", __func__);
}

@end
