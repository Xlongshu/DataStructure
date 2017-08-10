/*
 * SortTest.h
 *
 *  Created on: 2017年8月9日
 *      Author: LongShu
 */

#ifndef TEST_SORTTEST_H_
#define TEST_SORTTEST_H_

#include "../sort.h"

SortData sortDatas[] = { { 72, "11" }, { 89, "22" }, { 94, "33" }, { 66, "44" } };
void testBubbleSort() {
    bubbleSort(sortDatas, sizeofArray(sortDatas));

    printSortDataArray(sortDatas, sizeofArray(sortDatas));
}

void testInsertSort() {
//    SortData arr[] = { { 72, "11" }, { 89, "22" }, { 94, "33" }, { 66, "44" } };
    insertSort(sortDatas, sizeofArray(sortDatas));

    printSortDataArray(sortDatas, sizeofArray(sortDatas));
}

#endif /* TEST_SORTTEST_H_ */
