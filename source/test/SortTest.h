/*
 * SortTest.h
 *
 *  Created on: 2017年8月9日
 *      Author: LongShu
 */

#ifndef TEST_SORTTEST_H_
#define TEST_SORTTEST_H_

#include <memory.h>

#include "../common.h"
#include "../sort.h"

///////// 测试排序 /////////

SortData sortDatas[] = { { 72, "10" }, { 89, "20" }, { 94, "30" }, { 94, "31" },
        { 77, "40" }, { 89, "50" }, { 66, "60" } };

int sortDataLen = sizeofArray(sortDatas);
// 定义指针函数
typedef void (*SortMethod)(SortData*, int);

/*
 * 拷贝一份做测试
 */
void copySortDatas(SortData arr[]) {
    memcpy(arr, sortDatas, sortDataLen * sizeof(SortData));
}

void doTestSort(SortMethod method, char* name) {
    print("%-10s:", name);
    SortData arr[sortDataLen];
    copySortDatas(arr);

    method(arr, sortDataLen);
    printSortDataArray(arr, sortDataLen);
}

void testSort() {
    print("testSort:  ");
    printSortDataArray(sortDatas, sortDataLen);

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
