//
// Created by 87572 on 19/4/15.
//

#include "../include/ArrayPart.h"

/**
 * K1:==============================================================
 * 数组介绍.数组就是连续的内存.
 *
 */
void print_array(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        cout << "arr[ " << i << " ]" << arr[i] << endl;
    }
}

void init_arrary() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[5] = {1, 2};
    int arr3[5] = {1};      //这么写的时候,只初始化第一个=1;
    print_array(arr1, 5);
    print_array(arr2, 5);
    print_array(arr3, 5);
}

/**
 * K2:==============================================================
 *计算数组大小
 * sizeof(array)数组所占空间的总大小
 * sizeof(array)/sizeof(element)数组的length大小
 *
 */
void cal_size_array() {

    int arr[10] = {1};
    cout << "array total size:  " << sizeof(arr) << endl;
    cout << "array length:   " << sizeof(arr) / sizeof(int) << endl;
}

/**
 * K3:==============================================================
 * 数组的名 int arr[] ; arr就是常量指针,指向的就是数组首元素.(传递数据最合理)
 * arr与int*的区别: 1.arr当作形参的时候,退化成指针.
 * ----------------2.sizeof(arr) 取得是整个数组的大小.
 * ----------------3.&arr 是数组指针.
 * &arr,则是数组指针. int (*p) [10];   这个也是指向的首地址,但是步长是整个数组大小;
 * important:
 * ----int (*p) [10]=&arr;
 * ----int *q=*p;
 *  指针并不是简单的取所在地址的内容,还要看指针的类型.虽然数组指针指向的是一个int,
 *  但是解引用之后,是一个int*,是因为他是一个数组指针.所以仍是int *;
 */
void real_of_array() {

    int arr[10] = {1};
    printf("&arr, %d\n  ", &arr);
    printf("&arr[0], %d\n  ", &arr[0]);
    int (*p)[10] = &arr;
    printf("int (*p) [10], %d\n  ", p);
    int *q = *p;

}


/**
 * K4:==============================================================
 *  二维数组
 *  二维数组也是连续的空间.数组名代表了首数组的数组指针.
 *
 */
void print_two_array(int arr[][3], int len1, int len2) {
    for (int i = 0; i < len1; ++i) {
        for (int j = 0; j < len2; ++j) {
            cout << "arr" << arr[i][j] << endl;
        }
    }

}

void define_two_array() {

    int arr[2][3] = {

            {1, 2, 3},
            {4, 5, 6}

    };
    int (*p)[3] = arr;

    print_two_array(arr, 2, 3);
}


/**
 * K5:==============================================================
 *  数组逆置
 */
void inverse_array() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9,10};
    int start = 0;
    int end = 9;
    while (start < end) {
        int tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
        ++start;
        --end;
    }
    for (int i = 0; i <10; ++i) {

        cout<<"inverse array :  "<<arr[i]<<endl;
    }
}









