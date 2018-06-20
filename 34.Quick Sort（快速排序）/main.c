//
//  main.c
//  34.Quick Sort（快速排序）
//
//  Created by sunny&pei on 2018/6/20.
//  Copyright © 2018年 sunny&pei. All rights reserved.
//
/**
     快速排序。通过一趟排序将待排记录分割成独立的两部分，其中一部分记录的关键字均比另一部分记录的关键字小，则可分别对这两部分记录继续进行排序，以达到整个序列有序的目的地。
 */
#include <stdio.h>
typedef struct {
    int r[10];
    int length;
}Sqlist;
void swap(Sqlist *L,int i,int j){
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

/**
 交换顺序表中 子表的记录，使枢轴记录到位，并返回其所在位置。
 此时，在它之前（后）的记录均不大（小）于它。
 */
int Partition(Sqlist *L,int low,int high){
    int pivotkey;
    //三数取中法
    int m = low + (high - low)/2;//计算数组中间的下标
    if (L->r[low]>L->r[high]){
        swap(L,low,high);//保证左端较小
    }
    if (L->r[m]>L->r[high]) {
        swap(L, m, high);//保证中间较小
    }
    if (L->r[low]<L->r[m]) {
        swap(L, low, m);//保证左端为中间值
    }
    pivotkey = L->r[low];//用子表的第一个记录作中枢轴记录
    L->r[0] = pivotkey;//将中枢值关键字备份到L->r[0]
    while (low<high) {//从表的两端交替向中间扫描
        while (low<high && L->r[high]>=pivotkey)
            high--;
        L->r[low] = L->r[high];//采用替换，而不是交换
        while (low<high && L->r[low]<=pivotkey)
            low++;
        L->r[high] = L->r[low];//采用替换，而不是交换
        
    }
    L->r[low] = L->r[0];//将轴值替换为L.r[0]
    //打印过程
    for (int i = 1; i<L->length; i++) {
        printf("%d",L->r[i]);
    }
    printf("\n");
    return low;//返回枢轴所在位置
}
/**
 对顺序表中的子序列L->[low..high]做快速排序
 */
void QSort(Sqlist *L,int low,int high){
    int prvot;
    while(low < high){
        prvot = Partition(L,low,high);
        QSort(L, low, prvot-1);
//        QSort(L, prvot+1, high);
        low = prvot+1;//尾递归
    }
}

/**
 对顺序表L进行快速排序
 */
void QickSort(Sqlist *L){
    QSort(L,1,L->length);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    Sqlist L;
    L.length = 10;
    L.r[1] = 2;
    L.r[2] = 7;
    L.r[3] = 8;
    L.r[4] = 6;
    L.r[5] = 5;
    L.r[6] = 4;
    L.r[7] = 3;
    L.r[8] = 2;
    L.r[9] = 1;
    QickSort(&L);
//    for (int i = 1; i<L.length; i++) {
//        printf("%d\n",L.r[i]);
//    }
    return 0;
}
