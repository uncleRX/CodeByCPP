//
//  main.m
//  二分法查找数据
//
//  Created by 任迅 on 2022/5/31.
//

#import <Foundation/Foundation.h>
#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int ls[] = { 1,2,3,4,5,6,7,8,9 };
    int a = 0;
    int left = 0,right = 0;
    int mid = 0;
    int n = sizeof(ls)/sizeof(ls[0]);
    scanf("%d", &a);
    right = n - 1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (a > ls[mid])
        {
            left = mid + 1;
        }
        if (a < ls[mid])
        {
            right = mid - 1;
        }
        if (a == ls[mid])
        {
            printf("查找成功，其下标为：%d\n", mid);
            break;
        }
    }
    if (left > right)
    {
        printf("查找失败\n");
    }
    return 0;
}
