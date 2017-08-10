/*
 * sort.h
 *
 *  Created on: 2017年8月8日
 *      Author: LongShu
 */

#ifndef SORT_H_
#define SORT_H_

#include "common.h"

typedef int KeyType; // 排序关键字类型
typedef char* DataType; // 相关数据类型

typedef struct {
    KeyType key; // 排序关键字
    DataType data; // 相关数据(可有可无),比如key是分数,data是学生姓名
} SortData;

void printSortData(const SortData sd);

/**
 * 打印数组内容
 */
void printSortDataArray(SortData arr[], int len);

/////////////////////////////////////////////////

/**
 * 比较 SortData
 * 返回 -1, 0, 1
 */
int compareSortData(SortData x, SortData y);

/**
 * 冒泡排序
 */
void bubbleSort(SortData arr[], int len);
/**
 * 直接插入排序
 */
void insertSort(SortData arr[], int len);
/**
 * 选择排序
 */
void selectSort(SortData arr[], int len);

/**
 * 快速排序
 */
void quickSort(SortData arr[], int len);
/**
 * 归并排序
 */
void mergeSort(SortData arr[], int len);
/**
 * 堆排序
 */
void heapSort(SortData arr[], int len);
/**
 * 希尔排序
 */
void shellSort(SortData arr[], int len);

#endif /* SORT_H_ */
