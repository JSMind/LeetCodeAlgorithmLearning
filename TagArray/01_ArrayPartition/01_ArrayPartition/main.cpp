//
//  main.cpp
//  01_ArrayPartition
//
//  Created by jinsheng huang on 2017/10/25.
//  Copyright © 2017年 黄锦生. All rights reserved.
//

/********************** 题解 *********************
     题目链接：https://leetcode.com/problems/array-partition-i/description
     题目大意：给定一个长度为2n(偶数)的数组，分成n个小组，返回每组中较小值的和sum，使sum尽量大
     题目解析：先排序，将相邻两个数分为一组，每组较小数都在左边，求和即可
 
 算法分析：假设对于每一对i，bi >= ai。 定义Sm = min（a1，b1）+ min（a2，b2）+ … + min（an，bn）。最大的Sm是这个问题的答案。由于bi >= ai，Sm = a1 + a2 + … + an。 定义Sa = a1 + b1 + a2 + b2 + … + an + bn。对于给定的输入，Sa是常数。 定义di = | ai - bi |。由于bi >= ai，di = bi-ai, bi = ai+di。 定义Sd = d1 + d2 + … + dn。 所以Sa = a1 + (a1 + d1) + a2 + (a2 + d2) + … + an + (an + di) = 2Sm + Sd , 所以Sm =（Sa-Sd）/ 2。为得到最大Sm，给定Sa为常数，需要使Sd尽可能小。 所以这个问题就是在数组中找到使di（ai和bi之间的距离）的和尽可能小的对。显然，相邻元素的这些距离之和是最小的。
 ************************************************/

#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    //给定数组
    int a[10] = {1,4,6,9,3,5,13,37,19,12};
    int length = (sizeof(a)/sizeof(a[0]));
    printf("lenth: %d\n", length);
    //冒泡排序
    for (int i = 0; i< length; i++) {
        for (int j = 0; j< (length-i-1); j++) {
            if (a[j] > a[j+1]) {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
    
    for (int i = 0; i< length; i++) {
        printf("%d,",a[i]);
    }
    
    int sum = 0;
    for (int i = 0; i< length; i+= 2) {
        sum += a[i];
    }
    
    printf("sum:%d\n",sum);
    return 0;
}
