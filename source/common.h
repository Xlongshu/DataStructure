/*
 * common.h
 *
 *  Created on: 2017年8月8日 下午2:23:59
 *      Author: LongShu
 */
#ifndef COMMON_H_
#define COMMON_H_

#include <stdio.h>
#include <stdlib.h>

// 定义bool
#ifndef bool
#define bool int
#define true 1
#define false 0
#endif // end bool

/**
 * 刷新控制台
 */
#define flush() fflush(stdout); fflush(stderr);

/*
 * 不换行打印输出
 */
#define print(FORMAT,...) printf(FORMAT,##__VA_ARGS__); flush()

/*
 * 换行打印输出
 */
#define println(FORMAT,...) printf(FORMAT"\n",##__VA_ARGS__); flush()

#define connChar(x,y) x##y
//#define toChar(x) #@x
#define toString(value) #value

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

/*
 * 求数组长度,不能是数组的指针
 */
#define sizeofArray(arr) (sizeof(arr)/sizeof(arr[0]))

/*
 * 交换,任何类型
 */
#define SWAP(x,y,TYPE){\
    TYPE temp = (x);\
    (x) = (y);\
    (y) = temp;\
}

/*
 * 逆转数组
 */
#define REVERSE(arr,size,TYPE){\
    int j = (size) - 1;\
    for (int i = 0; i < (size) / 2; i++){\
        SWAP(arr[i], arr[j], TYPE);\
    }\
}

/*
 * 动态返回TYPE类型size大小的空间,堆中
 */
#define MALLOC(size, TYPE) ((TYPE*)malloc((size)* sizeof(TYPE)))

/*
 * 动态返回TYPE类型size大小的空间,默认初始化,堆中
 */
#define CALLOC(size, TYPE) ((TYPE*)calloc((size), sizeof(TYPE)))

/**
 * 调整内存大小
 */
#define REALLOC(ptr,new_size, TYPE) ((TYPE*)realloc(ptr,new_size)

#define FREE(p) {free(p); p=NULL;}

#endif /* COMMON_H_ */
