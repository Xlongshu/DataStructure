/*
 * SortTest.h
 *
 *  Created on: 2017年8月9日
 *      Author: LongShu
 */

#ifndef TEST_SORTTEST_H_
#define TEST_SORTTEST_H_

#include <memory.h>
#include <time.h>

#include "../common.h"
#include "../sort.h"

/*
 * 产生随机数种子
 */
void SRANDOM() {
    //  用时间做种，每次产生随机数不一样
    srand((unsigned) time(NULL));
}

/*
 * 产生随机数 [a,b]
 */
int RANDOM(int a, int b) {
    return (rand() % (b - a + 1)) + a;
}

///////// 测试排序 /////////

// 定义指针函数
typedef void (*SortMethod)(SortData*, int);

SortData* sortDatas;
int sortDataLen;

/*
 * 随机产生测试数据
 */
void randSortDatas() {
    SRANDOM();
    sortDataLen = RANDOM(20000, 90000);
    println("sortDataLen=%d", sortDataLen);

    sortDatas = CALLOC(sortDataLen, SortData);
    for (int i = 0; i < sortDataLen; i++) {
        sortDatas[i].key = RANDOM(0, sortDataLen / 2);
    }
}

/*
 * 拷贝一份做测试
 */
void copySortDatas(SortData arr[]) {
    memcpy(arr, sortDatas, sortDataLen * sizeof(SortData));
}

void doTestSort(SortMethod method, char* name) {
    SortData arr[sortDataLen];
    copySortDatas(arr);

    clock_t start, end;
    start = clock();
    method(arr, sortDataLen);
    end = clock();
    println("%-10s: time=%-5ldms", name, (end - start));
//    printSortDataArray(arr, sortDataLen);
}

void testSort() {
    print("testSort:  ");
    randSortDatas();

    println("-------------");
    doTestSort(insertSort, "insertSort");
    doTestSort(shellSort, "shellSort");
    doTestSort(selectSort, "selectSort");
    doTestSort(heapSort, "heapSort");
    doTestSort(bubbleSort, "bubbleSort");
    doTestSort(quickSort, "quickSort");
    doTestSort(mergeSort, "mergeSort");
    doTestSort(radixSort, "radixSort");
    println("-------------");
}

#endif /* TEST_SORTTEST_H_ */
