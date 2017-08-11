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

void swapSortData(SortData* x, SortData* y) {
    KeyType k = x->key;
    x->key = y->key;
    y->key = k;

    DataType d = x->data;
    x->data = y->data;
    y->data = d;
}

/**
 * 直接插入排序,稳定
 */
void insertSort(SortData arr[], int len) {
    if (NULL == arr || len <= 1) {
        return;
    }
    int j;
    SortData temp;
    for (int i = 0; i < len - 1; i++) {
        temp = arr[i + 1];
        // 查找位置,将大的值后移
        j = i;
        while (j > -1 && arr[j].key > temp.key) {
            arr[j + 1] = arr[j]; //后移
            j--;
        }
        arr[j + 1] = temp;
    }
}

void shellInsertSort(SortData arr[], int len, int span) {
    int j;
    SortData temp;

    //共有span个组,步长为span
    for (int k = 0; k < span; k++) {
        // 步长为span的插入排序
        for (int i = k; i < len - span; i += span) {
            temp = arr[i + span];
            j = i;
            while (j > -1 && temp.key < arr[j].key) {
                arr[j + span] = arr[j]; //后移
                j -= span;
            }
            arr[j + span] = temp;
        }
    }
}

/**
 * 希尔排序,不稳定
 */
void shellSort(SortData arr[], int len) {
    if (NULL == arr || len <= 1) {
        return;
    }

    // 增量步长
    int span = len;

    while (span > 0) {
        span = span / 2; // 每次增量递减
        shellInsertSort(arr, len, span);
    }
}

/**
 * 选择排序,不稳定
 */
void selectSort(SortData arr[], int len) {
    if (NULL == arr || len <= 1) {
        return;
    }

    int small;
    for (int i = 0; i < len - 1; i++) {
        small = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j].key < arr[small].key) {
                small = j; // 记下最小元素下标
            }
        }
        // 找到最小就交换
        if (small != i) {
            SWAP(arr[i], arr[small], SortData);
        }
    }
}

/**
 * 堆排序,不稳定
 */
void heapSort(SortData arr[], int len) {
    if (NULL == arr || len <= 1) {
        return;
    }
    // TODO
}

/**
 * 冒泡排序,稳定
 */
void bubbleSort(SortData arr[], int len) {
    if (NULL == arr || len <= 1) {
        return;
    }
    bool exchange; // 标识是否交换

    for (int i = 1; i < len; i++) { // 外循环 (len-1) 趟
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

void quickSort0(SortData arr[], int low, int high) {
    if (high <= low) {
        return;
    }

    int left = low, right = high;
    SortData pivot = arr[low]; // 存放基准值

    while (left < right) {
        // 扫描右边向前
        while (left < right && compareSortData(pivot, arr[right]) <= 0) {
            right--;
        }
        arr[left] = arr[right]; // 将比pivot小的往左低端移

        // 扫描左边向后
        while (left < right && compareSortData(pivot, arr[left]) >= 0) {
            left++;
        }
        arr[right] = arr[left]; // 将比pivot大的往右高端移
    }
    arr[left] = pivot; // 大小值交换完后基准值归位
    // 此时 left right 相等, 递归继续
    quickSort0(arr, low, left - 1);
    quickSort0(arr, right + 1, high);
}

/**
 * 快速排序,不稳定
 */
void quickSort(SortData arr[], int len) {
    if (NULL == arr || len <= 1) {
        return;
    }

    quickSort0(arr, 0, len - 1);
}

/*
 * mergeSort合并数据
 */
void merge(SortData arr[], int start, int middle, int end) {
    int length = end - start + 1;
    SortData* sorted = MALLOC(length, SortData);

    int left = start;
    int right = middle + 1;
    int i = 0;

    while (left <= middle && right <= end) {
        if (compareSortData(arr[left], arr[right]) <= 0) {
            sorted[i] = arr[left];
            i++;
            left++;
        } else {
            sorted[i] = arr[right];
            i++;
            right++;
        }
    }
    /*copy data*/
    while (left <= middle) {
        sorted[i++] = arr[left++];
    }
    /*可以用memcpy / memmove代替*/
//    if (left <= middle) {
//        memcpy(&sorted[i], &arr[left], sizeof(SortData) * (middle - left + 1));
//    }
    while (right <= end) {
        sorted[i++] = arr[right++];
    }

    for (i = 0; i < length; i++) {
        arr[start + i] = sorted[i];
    }
    FREE(sorted);
}

/*
 * mergeSort具体实现
 */
void mergeSort0(SortData arr[], int start, int end) {
    if (start < end) {
        // 从中间划分区间
        int middle = start + (end - start) / 2;
        // 对左边进行划分
        mergeSort0(arr, start, middle);
        // 对右边进行划分
        mergeSort0(arr, middle + 1, end);
        // 合并数据
        merge(arr, start, middle, end);
    }
}

/**
 * 归并排序,稳定
 */
void mergeSort(SortData arr[], int len) {
    if (NULL == arr || len <= 1) {
        return;
    }
    mergeSort0(arr, 0, len - 1);
}

/**
 * 基数排序,稳定
 */
void radixSort(SortData arr[], int len) {
    if (NULL == arr || len <= 1) {
        return;
    }
    // TODO
}
