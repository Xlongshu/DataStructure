/*
 * sort.c
 *
 *  Created on: 2017年8月8日
 *      Author: LongShu
 */

#include "sort.h"

void printSortData(const SortData sd) {
    print("{%d,'%s'}", sd.key, sd.data);
}

void printSortDataArray(SortData arr[], int len) {
    SortData data;
    print("[");
    for (int i = 0; i < len; i++) {
        data = arr[i];
        printSortData(data);
        if (i < len - 1)
            print(",");
    }
    println("]");
}

/////////////////////////////////////////////////

int compareSortData(SortData x, SortData y) {
    if (x.key == y.key) {
        return 0;
    }

    if (x.key > y.key) {
        return 1;
    }

    return -1;
}

/**
 * 冒泡排序,稳定
 */
void bubbleSort(SortData arr[], int len) {
    if (NULL == arr || 0 == len) {
        return;
    }
    bool exchange; // 标识是否交换

    for (int i = 0; i < (len - 1); i++) { // 外循环 (len-1) 趟
        exchange = false;
        for (int j = 0; j < len - i; j++) {
            if (compareSortData(arr[j], arr[j + 1]) > 0) {
                exchange = true;
                // 将大的往后移动
                SWAP(arr[j], arr[j + 1], SortData);
            }
        }
        // 没有交换则已经有序,提前终止
        if (!exchange) {
            return;
        }
    }
}

/**
 * 直接插入排序
 */
void insertSort(SortData arr[], int len) {
    if (NULL == arr || 0 == len) {
        return;
    }
    int j;
    SortData temp;
    for (int i = 0; i < len - 1; i++) {
        temp = arr[i + 1];
        // 查找位置,将大的值后移
        j = i;
        while (j > -1 && temp.key < arr[j].key) {
            arr[j + 1] = arr[j];    //后移
            j--;
        }
        arr[j + 1] = temp;
    }
}

/**
 * 选择排序
 */
void selectSort(SortData arr[], int len) {
    if (NULL == arr || 0 == len) {
        return;
    }
}

/**
 * 快速排序
 */
void quickSort(SortData arr[], int len) {
    if (NULL == arr || 0 == len) {
        return;
    }
}

/**
 * 归并排序
 */
void mergeSort(SortData arr[], int len) {
    if (NULL == arr || 0 == len) {
        return;
    }
}

/**
 * 堆排序
 */
void heapSort(SortData arr[], int len) {
    if (NULL == arr || 0 == len) {
        return;
    }
}

/**
 * 希尔排序
 */
void shellSort(SortData arr[], int len) {
    if (NULL == arr || 0 == len) {
        return;
    }
}
